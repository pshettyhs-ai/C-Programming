# Theory — Introduction to C Programming

> **Author: Pavan Shetty H S**

---

## 1. What is C?

C is a **compiled, general-purpose programming language** created by Dennis Ritchie at Bell Labs between 1969 and 1973. It was built to rewrite the Unix operating system, which was previously written in assembly — a language that is powerful but incredibly tedious to write.

The interesting thing about C is where it sits. It is not as low-level as assembly (you do not manage individual CPU registers manually), but it is not as high-level as Python (the language does almost nothing for you automatically). This middle position is exactly what makes C so valuable — and why learning it teaches you how computers actually work.

---

## 2. Why Should You Learn C?

I get asked this a lot. Here is my honest answer:

| Reason | What it means in practice |
|--------|--------------------------|
| **It teaches you how memory works** | No garbage collector, no automatic management — you are responsible |
| **Every language borrows from C** | C++, Java, Python, PHP, JavaScript all have C-style syntax |
| **Operating systems are written in C** | Linux, Windows NT kernel, macOS XNU — all C |
| **Embedded and hardware programming** | Arduino, automotive ECUs, medical devices — C is everywhere |
| **Placements test C fundamentals** | Pointers, recursion, data structures in C are common interview topics |
| **It makes you a better programmer** | When you understand C, every other language feels easier |

---

## 3. A Brief History

```
1969  Ken Thompson writes the 'B' language at Bell Labs
1972  Dennis Ritchie creates C — improves on B with data types
1973  The Unix kernel (11,000 lines) is rewritten in C
1978  Kernighan and Ritchie publish "The C Programming Language" — still a classic
1989  ANSI publishes the first C standard — known as C89 or ANSI C
1990  ISO adopts the same standard — also called C90
1999  C99 adds // comments, inline functions, variable-length arrays, stdint.h
2011  C11 adds thread support, atomics, and anonymous structs/unions
2017  C17 — mostly bug fixes to C11, no major new features
2023  C23 — adds typeof, binary literals like 0b1010, and #elifdef
```

The most widely used standard today is C11. When you compile with `gcc -std=c11`, you get all the features of C11.

---

## 4. How Compilation Works — All 4 Stages

This is something I think every C student should understand deeply. When you type `gcc program.c -o program`, four things happen in sequence:

```
Your source code: program.c
         │
         ▼  STAGE 1 — PREPROCESSING  (tool: cpp)
         
  Produces: program.i
  
  What happens here:
  • Every #include <stdio.h> is replaced by the actual content of stdio.h
  • Every #define MAX 100 is replaced — MAX becomes 100 everywhere
  • All comments (// and /* */) are stripped out
  • Conditional compilation (#ifdef, #ifndef) is evaluated
         │
         ▼  STAGE 2 — COMPILATION  (tool: cc1)
         
  Produces: program.s  (assembly language)
  
  What happens here:
  • The compiler checks your syntax (catches missing semicolons, etc.)
  • It checks your types (catches passing int where float is expected)
  • It translates your C code into CPU assembly instructions
  • If you use -O2, it also applies optimizations here
         │
         ▼  STAGE 3 — ASSEMBLING  (tool: as)
         
  Produces: program.o  (machine code, not yet executable)
  
  What happens here:
  • The assembler converts assembly mnemonics to binary machine code
  • Creates a symbol table (list of all function and variable names)
         │
         ▼  STAGE 4 — LINKING  (tool: ld)
         
  Produces: program  (the final executable)
  
  What happens here:
  • Combines your .o file with the standard library (libc)
  • Resolves external references — printf is defined in libc, linked here
  • Assigns final memory addresses to everything
```

**You can stop at any stage:**
```bash
gcc -E  program.c -o program.i    # stop after preprocessing
gcc -S  program.c -o program.s    # stop after compilation
gcc -c  program.c -o program.o    # stop after assembling
gcc     program.c -o program      # go all the way to executable
```

---

## 5. Every Part of a C Program Explained

```c
/*─────────────────────────────────────────────────────────────────
  SECTION 1: Preprocessor directives
  These are processed BEFORE compilation.
  #include pastes the entire content of stdio.h right here.
─────────────────────────────────────────────────────────────────*/
#include <stdio.h>     /* gives us printf, scanf, fopen, etc. */
#include <stdlib.h>    /* gives us malloc, free, exit, atoi, etc. */

/*─────────────────────────────────────────────────────────────────
  SECTION 2: Macros and constants
  These are NOT variables. The preprocessor replaces them with
  their values before compilation. They take no memory at runtime.
─────────────────────────────────────────────────────────────────*/
#define MAX_STUDENTS  50
#define PI            3.14159265358979

/*─────────────────────────────────────────────────────────────────
  SECTION 3: Global variables
  Declared outside all functions. Live in the DATA or BSS segment.
  They exist for the entire life of the program.
─────────────────────────────────────────────────────────────────*/
int global_count = 0;

/*─────────────────────────────────────────────────────────────────
  SECTION 4: Function prototypes (forward declarations)
  Tell the compiler about a function before we define it below.
  Without this, calling a function before its definition is an error.
─────────────────────────────────────────────────────────────────*/
void greet(const char *name);
int  square(int n);

/*─────────────────────────────────────────────────────────────────
  SECTION 5: The main function
  This is where the operating system starts your program.
  Every C program must have exactly one main().
  Return 0 to signal success. Return non-zero for errors.
─────────────────────────────────────────────────────────────────*/
int main(void) {
    int age = 20;           /* local variable — lives on the STACK */
    char name[] = "Pavan";  /* char array — also on the STACK */

    greet(name);
    printf("Square of %d is %d\n", age, square(age));

    return 0;   /* tell the OS: program finished successfully */
}

/*─────────────────────────────────────────────────────────────────
  SECTION 6: Function definitions
─────────────────────────────────────────────────────────────────*/
void greet(const char *name) {
    printf("Hello, %s! Welcome to C programming.\n", name);
}

int square(int n) {
    return n * n;
}
```

---

## 6. Where C is Used Today

You might think C is old and no longer relevant. It is old — but it is absolutely still relevant.

| Domain | Real-world examples |
|--------|-------------------|
| **Operating Systems** | Linux kernel, macOS XNU, Windows NT kernel |
| **Databases** | MySQL, PostgreSQL, SQLite are all written in C |
| **Compilers** | GCC itself is written in C. CPython (Python's interpreter) is C |
| **Embedded Systems** | Every Arduino sketch compiles to C under the hood |
| **Networking** | Nginx, the Apache web server, most of the internet's plumbing |
| **Game Engines** | The original Quake and Doom engines were pure C |

---

## 7. C vs Other Languages — The Honest Comparison

| Feature | C | C++ | Java | Python |
|---------|---|-----|------|--------|
| Speed | Fastest | Very fast | Medium | Slow |
| Memory control | You manage it | You manage it | Garbage collected | Garbage collected |
| Syntax difficulty | Moderate | Hard | Moderate | Easy |
| OOP support | None | Full | Full | Full |
| Where it runs | Compiled binary | Compiled binary | JVM | Interpreter |
| Best used for | Systems, embedded | Systems, games, apps | Enterprise | Scripting, ML, automation |

Learning C first makes every language after it easier to understand deeply.
