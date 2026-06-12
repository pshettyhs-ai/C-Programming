# Interview Questions — Introduction to C

> **Author: Pavan Shetty H S**
>
> These are questions I actually encountered or collected from friends during placement drives. I wrote the answers in my own words — the way I would explain them to someone sitting next to me.

---

## 🟢 Basic Questions

---

**Q1. What is the C programming language?**

C is a general-purpose, compiled programming language created by Dennis Ritchie at Bell Labs in 1972. It was designed to write operating systems — specifically Unix — and it does that job exceptionally well because it gives you direct control over memory while still providing the structure of a high-level language.

---

**Q2. Why is C called a middle-level language?**

Because it sits between low-level assembly and high-level languages like Java or Python.

On the low-level side, C lets you work directly with memory using pointers, do bit manipulation, and write code that maps closely to hardware. On the high-level side, it gives you functions, structured programming, and portability across different machines.

Neither purely high nor purely low — hence middle-level.

---

**Q3. What are the key features of C?**

The ones I remember and actually use:

- **Compiled** — translates directly to machine code, so programs run fast
- **Procedural** — organise code into functions
- **Pointer support** — work directly with memory addresses
- **Portable** — code written to the ANSI standard runs on almost any machine
- **Efficient** — minimal runtime overhead, which is why OS kernels use it
- **Rich operator set** — arithmetic, bitwise, logical, relational all built in
- **Standard library** — stdio, stdlib, string, math give you a solid foundation

---

**Q4. What are the four stages of compilation in C?**

1. **Preprocessing** — expands #include and #define, removes comments, handles #ifdef
2. **Compilation** — checks syntax and semantics, translates C to assembly
3. **Assembling** — converts assembly to binary machine code (.o object file)
4. **Linking** — combines object files with libraries (like libc) to produce the final executable

You can stop after any stage:
```bash
gcc -E program.c    # stops after preprocessing — produces .i file
gcc -S program.c    # stops after compilation — produces .s assembly
gcc -c program.c    # stops after assembling — produces .o object file
gcc    program.c    # full pipeline — produces executable
```

---

**Q5. What does `return 0` mean in main()?**

It tells the operating system that the program finished successfully. The OS receives this value as the program's exit code. By convention, 0 means success and any non-zero value means something went wrong. Shell scripts use this: `if [ $? -eq 0 ]; then echo "OK"; fi`.

---

**Q6. What is the purpose of `#include <stdio.h>`?**

stdio.h (Standard Input/Output) contains declarations for functions like printf, scanf, fopen, and fclose. Without including it, the compiler does not know the signature of printf and will warn or error when you use it. The preprocessor replaces the `#include` line with the entire content of that header file before compilation begins.

---

**Q7. What is the difference between C and C++?**

| Aspect | C | C++ |
|--------|---|-----|
| Programming style | Procedural only | Procedural + Object-Oriented |
| Classes | Not available | Core feature |
| Function overloading | Not supported | Supported |
| References | Not supported | Supported (`int &r = x`) |
| I/O | printf / scanf | cout / cin as well |
| Standard library | Smaller (libc) | Much larger (STL) |

C is a subset of C++ in most cases — valid C code compiles as C++ — but the reverse is not true.

---

## 🟡 Intermediate Questions

---

**Q8. What are the predefined macros in C?**

These are set by the compiler automatically. I use them often in debugging:

```c
__FILE__          /* name of the current source file */
__LINE__          /* current line number as an integer */
__func__          /* name of the current function (C99 onward) */
__DATE__          /* compilation date as "MMM DD YYYY" */
__TIME__          /* compilation time as "HH:MM:SS" */
__STDC_VERSION__  /* C standard version: 199901L for C99, 201112L for C11 */
```

A useful debug macro built from these:
```c
#define DBG(msg) printf("[%s:%d] %s\n", __FILE__, __LINE__, msg)
```

---

**Q9. What is the difference between a compiler and an interpreter?**

A **compiler** (like GCC for C) translates your entire source code into machine code before any execution happens. The result is a standalone binary file. Fast at runtime. Errors found before the program runs.

An **interpreter** (like Python's CPython) reads and executes code line by line. No separate compilation step. Slower at runtime. Errors may only appear when that specific line executes.

Java is a hybrid — compiled to bytecode, then interpreted or JIT-compiled by the JVM.

---

**Q10. What is the significance of `void` in `int main(void)`?**

In C (not C++), `int main()` means the parameters are unspecified — the compiler accepts any arguments without complaint. `int main(void)` explicitly says: this function takes no parameters whatsoever. It is stricter and more correct. Always write `main(void)` in modern C code.

---

## 🔴 Advanced Questions

---

**Q11. What is undefined behaviour in C? Give examples.**

Undefined behaviour (UB) is code that the C standard says is not defined — the compiler is literally allowed to do anything: crash, produce wrong output, or even appear to work correctly.

Common examples:
- Reading an uninitialized local variable
- Signed integer overflow (`INT_MAX + 1`)
- Dereferencing a NULL or freed pointer
- Accessing an array out of bounds
- Modifying a string literal

UB is dangerous because it is not always a crash — it can produce silently wrong results that are hard to trace.

---

**Q12. Why does the C standard leave so many things as undefined behaviour?**

Because C was designed to be portable across radically different hardware. Specifying the exact behaviour of everything (like what happens on overflow) would either prevent useful optimizations or require handling every quirk of every CPU. By leaving edge cases undefined, the standard lets compiler writers implement C optimally for their target hardware, and it lets the compiler assume UB never happens — enabling aggressive optimization.

---

**Q13. What is the One Definition Rule?**

Each variable or function must be **defined** exactly once across all files in a project. It can be **declared** (with `extern`) in as many files as needed. Defining `int x = 5;` in two different `.c` files without `static` will cause a linker error: "multiple definition of x". Use `static` to give a variable file scope, or define it once and declare it `extern` everywhere else.

---

**Q14. Explain the difference between a declaration and a definition.**

A **declaration** tells the compiler that something exists — its name and type — but does not allocate memory or provide a body.

A **definition** actually creates the thing — allocates memory for a variable, or provides the function body.

```c
extern int count;          /* declaration — no memory allocated */
int count = 0;             /* definition — memory allocated here */

int square(int n);         /* declaration (prototype) — no body */
int square(int n)          /* definition — body provided */
{ return n * n; }
```

You can declare something many times. You can define it only once.

---

*— Pavan Shetty H S*
