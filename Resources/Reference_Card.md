# C Quick Reference Card

> **Author: Pavan Shetty H S**
>
> The facts I look up most often — kept short on purpose.

---

## ASCII Values I Always Forget

| Character | Decimal | Hex |
|-----------|---------|-----|
| `\0` (null) | 0 | 00 |
| `\n` (newline) | 10 | 0A |
| `\t` (tab) | 9 | 09 |
| Space | 32 | 20 |
| `0` | 48 | 30 |
| `9` | 57 | 39 |
| `A` | 65 | 41 |
| `Z` | 90 | 5A |
| `a` | 97 | 61 |
| `z` | 122 | 7A |

**Useful patterns:**
```c
c - '0'          /* converts digit char to int: '7' - '0' = 7 */
c - 'A' + 10     /* converts hex letter to value: 'B' - 'A' + 10 = 11 */
c | 32           /* uppercase to lowercase (ASCII trick) */
c & ~32          /* lowercase to uppercase (ASCII trick) */
```

---

## Integer Promotion Rules

When mixing types in an expression, the compiler promotes smaller types upward:

```
char / short  →  int  →  unsigned int  →  long  →  unsigned long
                                        →  long long  →  float  →  double  →  long double
```

```c
char a = 200, b = 100;
int  result = a + b;    /* chars promoted to int before addition */
printf("%d\n", result); /* 300 — no overflow because promoted to int */
```

---

## stdio.h Functions

```c
/* Output */
printf(fmt, ...)          fprintf(fp, fmt, ...)
sprintf(buf, fmt, ...)    snprintf(buf, n, fmt, ...)
puts(str)                 putchar(c)

/* Input */
scanf(fmt, &...)          fscanf(fp, fmt, &...)
sscanf(buf, fmt, &...)    fgets(buf, n, fp)
getchar()                 fgetc(fp)

/* File control */
fopen   fclose   fseek   ftell   rewind
fread   fwrite   feof    ferror  clearerr  fflush
```

---

## stdlib.h Functions

```c
/* Memory */
malloc   calloc   realloc   free

/* Conversion */
atoi(s)       atol(s)       atof(s)
strtol(s,&end,base)         strtod(s,&end)

/* Random */
rand()        srand(seed)   RAND_MAX

/* Math (integer) */
abs(n)        labs(n)       llabs(n)

/* Program control */
exit(code)    EXIT_SUCCESS  EXIT_FAILURE
atexit(func)  abort()

/* Search and sort */
qsort(arr, n, size, cmp)
bsearch(key, arr, n, size, cmp)

/* Environment */
getenv(name)   system(cmd)
```

---

## math.h Functions (compile with -lm)

```c
/* Basic */
fabs(x)     ceil(x)     floor(x)     round(x)
fmod(x,y)   remainder(x,y)

/* Power and root */
sqrt(x)     cbrt(x)     pow(x,y)     exp(x)
log(x)      log2(x)     log10(x)

/* Trig (radians) */
sin(x)      cos(x)      tan(x)
asin(x)     acos(x)     atan(x)      atan2(y,x)

/* Constants */
M_PI    M_E    M_SQRT2    M_LN2    HUGE_VAL    INFINITY    NAN
```

---

## ctype.h Character Tests

```c
isalpha(c)   isdigit(c)   isalnum(c)   isspace(c)
isupper(c)   islower(c)   ispunct(c)   isprint(c)
toupper(c)   tolower(c)
```

---

## limits.h Constants

```c
CHAR_MIN    CHAR_MAX    UCHAR_MAX
SHRT_MIN    SHRT_MAX    USHRT_MAX
INT_MIN     INT_MAX     UINT_MAX
LONG_MIN    LONG_MAX    ULONG_MAX
LLONG_MIN   LLONG_MAX   ULLONG_MAX
```

---

## Common GCC Warning Flags

```bash
-Wall          # most important warnings
-Wextra        # extra warnings
-Wshadow       # variable shadows outer variable
-Wformat=2     # extra format string checks
-Wnull-dereference  # potential NULL deref
-Wstrict-overflow   # overflow on constant expressions
```

---

*— Pavan Shetty H S*
