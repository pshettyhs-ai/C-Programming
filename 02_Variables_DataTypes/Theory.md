# Theory — Variables and Data Types

> **Author: Pavan Shetty H S**

---

## 1. What is a Variable?

A variable is a named location in memory where you can store a value. Think of it as a labelled box: you give it a name, put something inside, and refer to it by that name later.

Every variable in C has four things:
- **A name** (what you call it)
- **A type** (what kind of data it holds)
- **A value** (the current contents)
- **An address** (where it actually sits in RAM)

```c
int score = 95;
/*
   name:    score
   type:    int (stores whole numbers)
   value:   95
   address: &score (some address like 0x7ffd...)
*/
```

---

## 2. Declaration vs Definition vs Initialization

These three words mean different things in C:

```c
int x;              /* declaration + definition: tells compiler name and type,
                       allocates memory, but value is garbage (not set) */

extern int y;       /* declaration only: says y exists somewhere else,
                       no memory allocated here */

int x = 10;         /* declaration + definition + initialization:
                       memory allocated AND value set to 10 */

x = 20;             /* assignment: changes value of already-declared variable */
```

My rule: **always initialize local variables when you declare them.** Uninitialized variables contain whatever garbage was in that memory before — and using them is undefined behaviour.

---

## 3. All Data Types in C

```
C Data Types
│
├── Primary (built-in)
│   ├── Integer family:  char, short, int, long, long long
│   ├── Floating-point:  float, double, long double
│   └── No value:        void
│
├── Derived (built from primary)
│   ├── Arrays
│   ├── Pointers
│   └── Functions
│
└── User-defined
    ├── struct
    ├── union
    ├── enum
    └── typedef aliases
```

---

## 4. Integer Types — Sizes and Ranges (64-bit Linux)

| Type | Size | Signed Range | Unsigned Range |
|------|------|-------------|----------------|
| `char` | 1 byte | -128 to 127 | 0 to 255 |
| `short` | 2 bytes | -32,768 to 32,767 | 0 to 65,535 |
| `int` | 4 bytes | -2,147,483,648 to 2,147,483,647 | 0 to 4,294,967,295 |
| `long` | 8 bytes | -9.2×10¹⁸ to 9.2×10¹⁸ | — |
| `long long` | 8 bytes | same as long on 64-bit | — |

**Important:** `long` is 4 bytes on Windows 64-bit but 8 bytes on Linux 64-bit. If you need a guaranteed size, use `int32_t` or `int64_t` from `<stdint.h>`.

---

## 5. Floating-Point Types

| Type | Size | Decimal precision |
|------|------|------------------|
| `float` | 4 bytes | ~7 significant digits |
| `double` | 8 bytes | ~15-16 significant digits |
| `long double` | 10-16 bytes | 18-19 digits |

I use `double` by default. `float` is only worth it when memory is very tight (like arrays of millions of values).

**Watch out for floating-point imprecision:**
```c
double x = 0.1 + 0.2;
printf("%.20f\n", x);   /* 0.30000000000000004441 -- NOT 0.3 */
/* Floating point cannot represent 0.1 or 0.2 exactly in binary */
/* Never compare floats with ==. Use: fabs(a - b) < 1e-9 instead */
```

---

## 6. Type Modifiers

```c
signed   int a;    /* can hold negatives (this is the default for int) */
unsigned int b;    /* only non-negative — doubles the positive range */
short    int c;    /* 2 bytes */
long     int d;    /* 4 or 8 bytes depending on system */
long long int e;   /* always 8 bytes */
```

---

## 7. Type Qualifiers

```c
const int MAX_SIZE = 100;    /* value cannot be changed after initialization */
volatile int sensor_pin;     /* value may change outside normal program flow
                                (hardware, signals, another thread) */
```

`const` is enforced by the compiler — it will error if you try to modify the value. `volatile` is an instruction to the compiler: "do not cache this in a register, always read/write to actual memory."

---

## 8. Fixed-Width Types from stdint.h

For code that must work identically on 32-bit and 64-bit systems, use these:

```c
#include <stdint.h>

int8_t   a = -128;           /* exactly 8 bits, signed */
uint8_t  b = 255;            /* exactly 8 bits, unsigned */
int16_t  c = 32767;          /* exactly 16 bits, signed */
uint32_t d = 4294967295U;    /* exactly 32 bits, unsigned */
int64_t  e = -9223372036854775807LL;
```

Use these whenever you are: reading/writing binary files, implementing network protocols, writing code that runs on both 32-bit and 64-bit, or writing code for embedded hardware.

---

## 9. Type Conversion

**Implicit (automatic):** the compiler converts smaller types to larger ones automatically:
```c
int    i = 65;
double d = i;    /* int widened to double — safe, no data loss */
char   c = i;    /* int to char — 65 = 'A', works in this case */
```

**Explicit (cast):** you force a conversion — may lose data:
```c
double pi  = 3.99;
int    n   = (int)pi;   /* n = 3 — fractional part truncated, NOT rounded */

float  total = 7.0f;
int    count = 2;
float  avg   = total / count;               /* 3.5 — correct */
float  wrong = (int)total / count;          /* 3 -- both int, then cast */
```

**My tip:** when in doubt, cast the denominator: `(float)count` ensures float division happens.

---

## 10. Common Mistakes I Made

```c
/* Mistake 1: Using uninitialized variable */
int x;
printf("%d\n", x);    /* prints garbage — undefined behaviour */

/* Mistake 2: Integer overflow */
int max = 2147483647;
max++;                 /* undefined behaviour — wraps around or worse */
/* Fix: use long long if the value might exceed INT_MAX */

/* Mistake 3: Comparing floats with == */
float f = 0.1f + 0.2f;
if (f == 0.3f) { ... }    /* may never be true due to float imprecision */
/* Fix: if (fabs(f - 0.3f) < 1e-6) { ... } */

/* Mistake 4: sizeof on wrong type */
int *p = malloc(sizeof(p));     /* allocates 8 bytes (pointer size), not int size */
int *p = malloc(sizeof(*p));    /* correct — allocates sizeof(int) = 4 bytes */
```
