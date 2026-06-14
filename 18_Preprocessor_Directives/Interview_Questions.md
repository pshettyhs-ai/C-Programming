# Interview Questions — Preprocessor Directives

## 🟢 Basic
**Q1. What is the C preprocessor and when does it run?**
> The preprocessor runs BEFORE the compiler. It performs text transformations: expands `#include`, replaces `#define` macros, processes `#ifdef`/`#ifndef` conditional compilation, and removes comments. The compiler never sees preprocessor directives — only the expanded output.

**Q2. What is an include guard and why is it needed?**
> An include guard prevents a header file from being included multiple times, which would cause duplicate declaration errors:
```c
#ifndef MYHEADER_H
#define MYHEADER_H
/* ... content ... */
#endif
```
> The alternative is `#pragma once` (non-standard but universally supported).

**Q3. What is the difference between `#include <file>` and `#include "file"`?**
> `<file>` searches the system include paths (standard library headers). `"file"` searches the current directory first, then system paths. Use `<>` for standard/library headers, `""` for your own headers.

## 🟡 Intermediate
**Q4. Why should function-like macros have every parameter and the whole expression in parentheses?**
> Without parentheses, operator precedence can break the macro:
```c
#define BAD_DOUBLE(x)  x + x
printf("%d", BAD_DOUBLE(3) * 2);  /* 3 + 3*2 = 9, not 12! */
#define GOOD_DOUBLE(x) ((x) + (x))
printf("%d", GOOD_DOUBLE(3) * 2); /* (3+3)*2 = 12 — correct */
```

**Q5. What is the do-while(0) trick in macros?**
> Wrapping a multi-statement macro in `do { ... } while(0)` makes it behave like a single statement safely in all contexts:
```c
#define SAFE_MACRO(x) do { stmt1; stmt2; } while(0)
if (cond) SAFE_MACRO(x);   /* works correctly */
/* without do-while: only stmt1 is conditional! */
```

## 🔴 Advanced
**Q6. What is the difference between `#define` and `const` and `enum` for constants?**
> `#define PI 3.14`: no type, no scope, preprocessor replacement, not in symbol table, can't debug, can't take address. `const double PI = 3.14`: typed, scoped, in symbol table, debuggable, has address, enforced by compiler. `enum { MAX = 100 }`: integer only, typed, no memory, scoped, good for related constants. Modern C prefers `const` and `enum` over `#define` for constants.

**Q7. How does the `##` token-pasting operator work?**
> `##` joins two preprocessing tokens into one: `#define VAR(n) x##n` → `VAR(1)` becomes `x1`. Used to generate unique variable names or to build identifiers programmatically. The result must be a valid C token.

---

*— Pavan Shetty H S*
