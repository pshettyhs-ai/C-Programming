# Theory — Preprocessor Directives

> **Author: Pavan Shetty H S**

---

## 1. What the Preprocessor Does

The preprocessor runs before the compiler sees your code. It is a text manipulation tool — it copies, replaces, and conditionally includes text. All preprocessor directives start with `#` and do not end with a semicolon.

After preprocessing, the compiler gets a clean `.i` file with all macros expanded and all includes pasted in.

---

## 2. #include

```c
#include <stdio.h>     /* system header — searches compiler's include paths */
#include "myfile.h"    /* user header — searches current directory first */
```

The preprocessor literally pastes the entire contents of that file at this point. That is all `#include` does — it is a copy-paste operation.

---

## 3. #define — Two Forms

**Object-like macros (constants):**
```c
#define PI          3.14159265358979
#define MAX_SIZE    100
#define APP_NAME    "Student Manager"

/* The preprocessor replaces every occurrence of PI with 3.14159... */
/* This happens before compilation — PI is NOT a variable */
```

**Function-like macros:**
```c
/* Rule: always parenthesise every parameter AND the whole expression */
#define SQUARE(x)       ((x) * (x))
#define MAX(a, b)       ((a) > (b) ? (a) : (b))
#define ABS(x)          ((x) < 0 ? -(x) : (x))

/* Why the parentheses matter: */
#define BAD_SQUARE(x)   x * x
printf("%d\n", BAD_SQUARE(2+3));    /* 2+3*2+3 = 11 — wrong */
printf("%d\n",     SQUARE(2+3));    /* (2+3)*(2+3) = 25 — correct */
```

**Multi-statement macro — the do-while(0) trick:**
```c
/* Without do-while, this breaks in if-else */
#define SWAP(T, a, b) do { T _tmp=(a); (a)=(b); (b)=_tmp; } while(0)

/* Works safely in all contexts: */
if (x > y) SWAP(int, x, y);    /* no dangling else problem */
```

---

## 4. Conditional Compilation

```c
/* Include guard — prevents a header being included twice */
#ifndef MYHEADER_H
#define MYHEADER_H
/* ... header content ... */
#endif

/* Alternative (widely supported, not standard) */
#pragma once

/* Debug builds */
#ifdef DEBUG
    #define LOG(msg) fprintf(stderr, "[DEBUG %s:%d] %s\n", __FILE__, __LINE__, msg)
#else
    #define LOG(msg)    /* expands to nothing in release builds */
#endif

/* Platform detection */
#if defined(_WIN32)
    #define CLEAR_SCREEN "cls"
#elif defined(__linux__)
    #define CLEAR_SCREEN "clear"
#else
    #define CLEAR_SCREEN "clear"
#endif
```

Compile with `gcc -DDEBUG program.c` to enable debug logging without changing any source code.

---

## 5. Stringification and Token Pasting

```c
/* # operator: converts a macro argument to a string literal */
#define STRINGIFY(x)    #x
printf("%s\n", STRINGIFY(hello));    /* prints: hello */
printf("%s\n", STRINGIFY(3.14));     /* prints: 3.14 */

/* ## operator: pastes two tokens together */
#define MAKE_FUNC(name) void func_##name(void) { printf(#name "\n"); }
MAKE_FUNC(hello)    /* creates: void func_hello(void) { printf("hello\n"); } */
MAKE_FUNC(world)    /* creates: void func_world(void) { printf("world\n"); } */
```

---

## 6. Predefined Macros

```c
__FILE__          /* current source filename as a string: "program.c" */
__LINE__          /* current line number as an integer: 42 */
__func__          /* current function name (C99): "main" */
__DATE__          /* compile date: "Jun 10 2025" */
__TIME__          /* compile time: "14:30:00" */
__STDC_VERSION__  /* C standard: 201112L for C11 */
```

I use these in a debug macro that tells me exactly where in my code something happened:

```c
#define DBG(fmt, ...) \
    fprintf(stderr, "[%s:%d %s] " fmt "\n", \
            __FILE__, __LINE__, __func__, ##__VA_ARGS__)

DBG("x = %d, y = %d", x, y);
/* prints: [program.c:42 main] x = 10, y = 20 */
```

---

## 7. #undef and #pragma

```c
#define BUFFER_SIZE 1024
/* ... use BUFFER_SIZE ... */
#undef BUFFER_SIZE    /* remove the macro definition */
/* BUFFER_SIZE is no longer defined after this point */

#pragma once          /* include guard — widely supported */
#pragma pack(1)       /* pack structs without padding (GCC extension) */

#error "This compiler version is not supported"   /* force compile error */
#warning "This function is deprecated"            /* emit a warning */
```

---

## 8. const vs #define — Which to Use

| Feature | `#define` | `const` |
|---------|-----------|---------|
| Type checking | None | Yes — compiler enforced |
| Scope | From definition to end of file | Block or file scope |
| Debuggable | No — not in symbol table | Yes |
| Memory | Zero — replaced before compilation | Has an address |
| Can take address | No | Yes |

**My preference:** use `const` for typed constants, `enum` for integer constants, `#define` only for macros or when compile-time text substitution is genuinely needed.
