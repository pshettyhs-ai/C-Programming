# Theory — Input and Output in C

> **Author: Pavan Shetty H S**

---

## 1. The Three Standard Streams

Every C program automatically gets three open file streams:

| Stream | What it is | Default destination | File descriptor |
|--------|-----------|-------------------|----------------|
| `stdin` | Standard input | Keyboard | 0 |
| `stdout` | Standard output | Terminal screen | 1 |
| `stderr` | Standard error | Terminal screen (unbuffered) | 2 |

You can redirect these from the shell:
```bash
./program < input.txt        # redirect stdin from a file
./program > output.txt       # redirect stdout to a file
./program 2> errors.txt      # redirect stderr to a file
```

---

## 2. printf — Formatted Output

printf sends formatted text to stdout. The first argument is always a format string.

**Format specifier anatomy:**
```
  %   -   10   .   5    l    f
  │   │    │   │   │    │    └── type (f = float/double)
  │   │    │   │   │    └─────── length modifier (l = long)
  │   │    │   │   └──────────── precision (5 decimal places)
  │   │    │   └──────────────── decimal point
  │   │    └──────────────────── width (minimum field width)
  │   └───────────────────────── flag (- = left-align)
  └───────────────────────────── start of specifier
```

**All format specifiers I use regularly:**

```c
printf("%d",    42);          /* decimal integer */
printf("%i",    42);          /* same as %d */
printf("%u",    42u);         /* unsigned integer */
printf("%ld",   1000000L);    /* long int */
printf("%lld",  9999999LL);   /* long long int */
printf("%f",    3.14);        /* float or double */
printf("%lf",   3.14);        /* double (same as %f in printf) */
printf("%e",    12345.6789);  /* scientific notation */
printf("%g",    0.000123);    /* shorter of %f or %e */
printf("%c",    'A');         /* single character */
printf("%s",    "hello");     /* string (char array) */
printf("%p",    &x);          /* pointer address */
printf("%x",    255);         /* hexadecimal lowercase */
printf("%X",    255);         /* hexadecimal uppercase */
printf("%o",    8);           /* octal */
printf("%zu",   sizeof(int)); /* size_t (use this for sizeof) */
printf("%%");                 /* prints a literal % sign */
```

**Width and precision formatting:**
```c
printf("[%10d]\n",   42);     /* [        42]  right-aligned */
printf("[%-10d]\n",  42);     /* [42        ]  left-aligned */
printf("[%010d]\n",  42);     /* [0000000042]  zero-padded */
printf("[%+d]\n",    42);     /* [+42]         always show sign */
printf("[%.5f]\n",  3.14);    /* [3.14000]     5 decimal places */
printf("[%10.2f]\n",3.14);    /* [      3.14]  width 10, 2 decimals */
```

---

## 3. scanf — Reading Input

scanf reads from stdin and stores values into variables. **Always use the `&` operator** to pass the address of the variable (except for string arrays).

```c
int   age;
float gpa;
char  name[50];

scanf("%d",   &age);     /* reads an integer into age */
scanf("%f",   &gpa);     /* reads a float into gpa */
scanf("%49s", name);     /* reads a string into name (NO & needed for arrays) */
                         /* %49s limits to 49 chars to prevent buffer overflow */
```

**Why does scanf need `&`?**
Because scanf has to store the value at the variable's location. Without `&`, you pass the variable's current value (not its address), and scanf writes to a random memory location — crash.

**The return value matters:**
```c
int items = scanf("%d %d", &a, &b);
if (items != 2) {
    fprintf(stderr, "Error: expected 2 integers, got %d\n", items);
}
/* scanf returns: number of items successfully read, or EOF on error */
```

**Flushing leftover input:**
```c
scanf("%d", &n);
/* After reading an int, the \n is still in the buffer */
while (getchar() != '\n');   /* consume everything up to the newline */
scanf("%c", &ch);             /* now safe to read a character */
```

---

## 4. Reading Strings Safely

The two big rules for reading strings in C:

**Never use `gets()`** — it was removed from C11 because it has no buffer-size limit and causes buffer overflows.

**Never use `scanf("%s", ...)` without a width limit** — same problem.

```c
char buffer[100];

/* SAFE — fgets reads at most sizeof(buffer)-1 chars */
fgets(buffer, sizeof(buffer), stdin);

/* Remove the trailing newline that fgets includes */
buffer[strcspn(buffer, "\n")] = '\0';

/* Or with a width limit in scanf */
scanf("%99s", buffer);    /* safe: reads at most 99 chars */
```

---

## 5. fprintf and sprintf

```c
/* fprintf writes to any stream, not just stdout */
fprintf(stdout, "Same as printf\n");
fprintf(stderr, "Error: file not found\n");   /* goes to stderr */
FILE *fp = fopen("log.txt", "w");
fprintf(fp, "Log entry: %d\n", 42);

/* sprintf writes into a string buffer */
char result[50];
sprintf(result, "Score: %d out of %d", 45, 50);
printf("%s\n", result);    /* "Score: 45 out of 50" */

/* snprintf is safer — limits the output length */
snprintf(result, sizeof(result), "Name: %s", name);
```

---

## 6. Character I/O

```c
/* getchar reads one character from stdin */
int ch = getchar();         /* returns int, not char — to handle EOF */
if (ch == EOF) { /* end of input */ }

/* putchar writes one character to stdout */
putchar('A');
putchar('\n');

/* Count characters in a line of input */
int ch, count = 0;
while ((ch = getchar()) != '\n' && ch != EOF)
    count++;
printf("You typed %d characters.\n", count);
```

---

## 7. Why stderr Exists

Use `fprintf(stderr, ...)` for error messages. This way, error output and normal output can be separated:

```bash
./program > output.txt      # stdout goes to file, stderr still appears on terminal
./program > out.txt 2> err.txt  # both redirected separately
```

This is important for programs used in pipelines or scripts.
