# Syntax — Introduction to C Programming

## 1. Minimal Valid C Program

```c
int main(void) {
    return 0;
}
```

## 2. Complete Syntax Structure

```c
/* Preprocessor directives — must be first */
#include <header.h>
#define MACRO value

/* Global declarations */
data_type variable_name;

/* Function prototypes */
return_type function_name(parameter_list);

/* main — mandatory entry point */
int main(void) {
    /* declarations */
    data_type var = initial_value;

    /* statements */
    statement;

    return 0;
}

/* Function definitions */
return_type function_name(parameter_list) {
    /* body */
}
```

## 3. Fundamental Rules

| Rule | Correct | Wrong |
|------|---------|-------|
| Statements end with `;` | `int x = 5;` | `int x = 5` |
| Case-sensitive language | `main()` ≠ `Main()` | — |
| Blocks enclosed in `{ }` | `if (x) { ... }` | `if (x) ...` (risky) |
| String literals: `" "` | `"Hello"` | `'Hello'` (error) |
| Char literals: `' '` | `'A'` | `"A"` (different type) |
| Variables declared before use | declare then use | use before declare ❌ |

## 4. All 32 C89 Keywords

```
auto      break     case      char      const
continue  default   do        double    else
enum      extern    float     for       goto
if        int       long      register  return
short     signed    sizeof    static    struct
switch    typedef   union     unsigned  void
volatile  while
```
*Additional in C99:* `_Bool`, `_Complex`, `_Imaginary`, `inline`, `restrict`
*Additional in C11:* `_Alignas`, `_Alignof`, `_Atomic`, `_Generic`, `_Noreturn`, `_Static_assert`, `_Thread_local`

## 5. Data Types — Sizes and Ranges

```c
/* Signed integer types */
char           c = 'A';            /* 1 byte  | -128 to 127              */
short          s = 32000;          /* 2 bytes | -32,768 to 32,767         */
int            i = 2000000;        /* 4 bytes | -2,147,483,648 to ...647  */
long           l = 2000000L;       /* 4/8 bytes (platform-dependent)      */
long long      ll = 9000000000LL;  /* 8 bytes | -(2^63) to (2^63 - 1)    */

/* Unsigned integer types */
unsigned char  uc = 255;           /* 0 to 255                            */
unsigned int   ui = 4000000000U;   /* 0 to 4,294,967,295                  */

/* Floating point types */
float          f  = 3.14f;         /* 4 bytes | 6–7 significant digits    */
double         d  = 3.14159265;    /* 8 bytes | 15–16 significant digits  */
long double    ld = 3.14159265L;   /* 10/16 bytes (platform-dependent)    */

/* Special */
void           *ptr;               /* typeless pointer                    */
_Bool          b = 1;              /* C99: 0 or 1                         */
```

**Check sizes at runtime:**
```c
#include <stdio.h>
int main(void) {
    printf("char:        %zu bytes\n", sizeof(char));
    printf("int:         %zu bytes\n", sizeof(int));
    printf("long:        %zu bytes\n", sizeof(long));
    printf("long long:   %zu bytes\n", sizeof(long long));
    printf("float:       %zu bytes\n", sizeof(float));
    printf("double:      %zu bytes\n", sizeof(double));
    return 0;
}
```

## 6. Format Specifiers (printf / scanf)

| Specifier | Type | printf example | scanf example |
|-----------|------|---------------|---------------|
| `%d` | `int` | `printf("%d", 42)` → `42` | `scanf("%d", &i)` |
| `%i` | `int` (also reads hex/octal) | `printf("%i", 42)` | `scanf("%i", &i)` |
| `%u` | `unsigned int` | `printf("%u", 42u)` | `scanf("%u", &u)` |
| `%ld` | `long int` | `printf("%ld", 1000L)` | `scanf("%ld", &l)` |
| `%lld` | `long long` | `printf("%lld", 1LL)` | `scanf("%lld", &ll)` |
| `%f` | `float` / `double` (printf) | `printf("%f", 3.14)` | — |
| `%lf` | `double` (scanf) | — | `scanf("%lf", &d)` |
| `%e` | Scientific notation | `printf("%e", 314.0)` → `3.14e+02` | — |
| `%g` | Shorter of `%f` or `%e` | `printf("%g", 0.0001)` | — |
| `%c` | `char` | `printf("%c", 'A')` → `A` | `scanf("%c", &c)` |
| `%s` | `char[]` string | `printf("%s", "hi")` | `scanf("%s", str)` |
| `%p` | pointer address | `printf("%p", ptr)` | — |
| `%x` | Hexadecimal (lower) | `printf("%x", 255)` → `ff` | — |
| `%X` | Hexadecimal (upper) | `printf("%X", 255)` → `FF` | — |
| `%o` | Octal | `printf("%o", 8)` → `10` | — |
| `%%` | Literal `%` | `printf("100%%")` → `100%` | — |

**Width and precision:**
```c
printf("%10d",   42);    /* right-aligned in 10 chars:  "        42" */
printf("%-10d",  42);    /* left-aligned:  "42        " */
printf("%010d",  42);    /* zero-padded:  "0000000042" */
printf("%.2f", 3.14159); /* 2 decimal places:  "3.14" */
printf("%8.2f", 3.14);   /* width 8, 2 decimals:  "    3.14" */
```

## 7. Escape Sequences

| Sequence | Name | ASCII Value | Use |
|----------|------|------------|-----|
| `\n` | Newline | 10 | Move to next line |
| `\t` | Horizontal tab | 9 | Align columns |
| `\r` | Carriage return | 13 | Move to line start |
| `\\` | Backslash | 92 | Print `\` |
| `\"` | Double quote | 34 | Print `"` inside string |
| `\'` | Single quote | 39 | Print `'` inside char |
| `\0` | Null character | 0 | String terminator |
| `\a` | Alert (bell) | 7 | Terminal beep |
| `\b` | Backspace | 8 | Move cursor back |
| `\f` | Form feed | 12 | Printer page break |
| `\v` | Vertical tab | 11 | Vertical spacing |
| `\xHH` | Hex value | varies | `'\x41'` = `'A'` |
| `\NNN` | Octal value | varies | `'\101'` = `'A'` |

## 8. Identifier Naming Rules

```c
/* VALID identifiers */
int age;            // simple name
float _speed;       // can start with underscore
char firstName;     // camelCase (common in C)
int count_2024;     // underscores and digits allowed
long MAX_VALUE;     // all caps (common for constants)

/* INVALID identifiers */
int 2fast;          // ERROR: starts with digit
float my-var;       // ERROR: hyphen not allowed
char int;           // ERROR: keyword reserved
double my value;    // ERROR: space not allowed
int @address;       // ERROR: @ not valid
```

---

*— Pavan Shetty H S*
