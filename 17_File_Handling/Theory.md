# Theory — File Handling

> **Author: Pavan Shetty H S**

---

## 1. Why File Handling Matters

Everything we have done so far disappears when the program ends. File handling is how you make data permanent — save student records, load configuration, write logs.

---

## 2. The File I/O Model

```
Your Program  ←──────────────────────→  File on Disk
               fopen / fclose
               fread / fwrite
               fprintf / fscanf
               fgets / fputs
               fseek / ftell
```

All file operations in C go through a `FILE *` — an opaque handle that the standard library manages for you.

---

## 3. Opening and Closing Files

```c
FILE *fp = fopen("filename.txt", "mode");

/* Always check the return value */
if (fp == NULL) {
    perror("fopen");      /* prints: fopen: No such file or directory */
    return 1;
}

/* ... do file operations ... */

fclose(fp);               /* always close when done */
```

**Mode strings:**

| Mode | Meaning |
|------|---------|
| `"r"` | Read — file must exist |
| `"w"` | Write — creates file or truncates existing |
| `"a"` | Append — creates or appends |
| `"r+"` | Read and write — file must exist |
| `"w+"` | Read and write — creates or truncates |
| `"rb"`, `"wb"` | Binary read/write (important on Windows) |

---

## 4. Text File Operations

```c
/* Writing */
FILE *fp = fopen("notes.txt", "w");
fprintf(fp, "Name: %s\n", "Pavan");
fprintf(fp, "Score: %d\n", 95);
fputs("End of record\n", fp);
fclose(fp);

/* Reading line by line */
fp = fopen("notes.txt", "r");
char line[256];
while (fgets(line, sizeof(line), fp) != NULL) {
    line[strcspn(line, "\n")] = '\0';    /* strip the newline */
    printf("Read: %s\n", line);
}
fclose(fp);

/* Reading formatted data */
fp = fopen("notes.txt", "r");
char name[50]; int score;
fscanf(fp, "Name: %49s\n", name);
fscanf(fp, "Score: %d\n",  &score);
fclose(fp);
```

---

## 5. Binary File Operations

Binary mode is faster and exact — struct data is written as-is, no text conversion.

```c
typedef struct {
    char  name[30];
    int   roll;
    float gpa;
} Student;

/* Write */
Student s = { "Pavan", 101, 9.1f };
FILE *fp = fopen("students.bin", "wb");
fwrite(&s, sizeof(Student), 1, fp);     /* write 1 record */
fclose(fp);

/* Read back */
Student loaded;
fp = fopen("students.bin", "rb");
fread(&loaded, sizeof(Student), 1, fp); /* read 1 record */
fclose(fp);
printf("%s %d %.1f\n", loaded.name, loaded.roll, loaded.gpa);

/* Write/read multiple records */
Student class[3] = { {"A",1,9.0f}, {"B",2,8.5f}, {"C",3,9.5f} };
fp = fopen("class.bin", "wb");
fwrite(class, sizeof(Student), 3, fp);  /* write 3 records */
fclose(fp);
```

---

## 6. Random Access with fseek

Binary files support jumping directly to any record:

```c
/* fseek(file_pointer, offset_in_bytes, reference_point) */

fseek(fp, 0, SEEK_SET);                     /* jump to beginning */
fseek(fp, 0, SEEK_END);                     /* jump to end */
fseek(fp, -sizeof(Student), SEEK_CUR);      /* back one record */
fseek(fp, 2 * sizeof(Student), SEEK_SET);   /* jump to record index 2 */

/* Get current position */
long pos = ftell(fp);

/* Get file size */
fseek(fp, 0, SEEK_END);
long size = ftell(fp);
int records = size / sizeof(Student);
rewind(fp);    /* same as fseek(fp, 0, SEEK_SET) */
```

---

## 7. Error Handling

```c
FILE *fp = fopen("data.txt", "r");
if (fp == NULL) {
    perror("Error");      /* prints system error message */
    exit(EXIT_FAILURE);
}

size_t n = fread(buf, sizeof(int), 10, fp);
if (n < 10) {
    if (feof(fp))   printf("Reached end of file\n");
    if (ferror(fp)) perror("Read error");
}

clearerr(fp);    /* clear error flags if you want to continue */
fclose(fp);
```

---

## 8. One Rule I Always Follow

Never ignore the return value of `fopen`. If a file operation fails silently and you keep reading/writing, you corrupt data or crash in a hard-to-debug way. Always check, always handle.
