# Theory — Command Line Arguments

> **Author: Pavan Shetty H S**

---

## 1. What Are Command Line Arguments?

When you run a program from the terminal, you can pass information directly on the command line:

```bash
./myprogram -v --output result.txt input.txt
```

These arguments arrive inside `main()` through two parameters: `argc` and `argv`.

---

## 2. argc and argv

```c
int main(int argc, char *argv[]) {
    /* argc: total argument count including the program name */
    /* argv: array of strings — each argument as a null-terminated string */
    /* argv[0]: program name (e.g., "./myprogram") */
    /* argv[1]: first user argument */
    /* argv[argc-1]: last argument */
    /* argv[argc]: NULL (sentinel — marks the end) */
}
```

**Example: running `./prog hello 42 3.14`**
```
argc    = 4
argv[0] = "./prog"
argv[1] = "hello"
argv[2] = "42"
argv[3] = "3.14"
argv[4] = NULL
```

All arguments arrive as strings. You must convert them to numbers when needed.

---

## 3. Memory Layout of argv

```
argv ──→  [ptr] ──→ "./prog\0"
          [ptr] ──→ "hello\0"
          [ptr] ──→ "42\0"
          [ptr] ──→ "3.14\0"
          [NULL]
```

argv is a `char **` — a pointer to an array of pointers to characters.

---

## 4. Converting Arguments to Numbers

```c
/* atoi — simple but no error detection */
int n = atoi(argv[1]);    /* silently returns 0 on bad input */

/* strtol — safe, with error detection */
char *end;
long val = strtol(argv[1], &end, 10);

if (*end != '\0') {
    fprintf(stderr, "Error: '%s' is not a valid integer\n", argv[1]);
    return 1;
}
if (val < INT_MIN || val > INT_MAX) {
    fprintf(stderr, "Error: value out of int range\n");
    return 1;
}

/* strtod — same idea for floating point */
double d = strtod(argv[2], &end);
```

---

## 5. Parsing Flags

```c
int verbose = 0;
char *output = "out.txt";

for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-v") == 0) {
        verbose = 1;
    } else if (strcmp(argv[i], "-o") == 0 && i + 1 < argc) {
        output = argv[++i];    /* next argument is the output filename */
    } else if (argv[i][0] == '-') {
        fprintf(stderr, "Unknown option: %s\n", argv[i]);
        return 1;
    } else {
        /* positional argument (input file, etc.) */
        printf("Input file: %s\n", argv[i]);
    }
}
```

---

## 6. Always Validate Your Arguments

```c
int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        fprintf(stderr, "Options:\n");
        fprintf(stderr, "  -v    verbose output\n");
        return EXIT_FAILURE;
    }
    /* ... rest of program ... */
}
```

Print a useful usage message when arguments are wrong. Use `argv[0]` as the program name so the message is always accurate.
