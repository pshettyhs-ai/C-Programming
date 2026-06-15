# Theory — Advanced C

> **Author: Pavan Shetty H S**

---

## 1. volatile — Tell the Compiler Not to Optimise This Variable

When the compiler sees that you read or write a variable multiple times without anything changing it in between, it may optimise by caching the value in a register instead of reading memory each time. `volatile` prevents this.

```c
/* Without volatile — compiler may cache stop_flag in a register */
/* and never re-read it, so the loop never exits */
volatile int stop_flag = 0;   /* with volatile, memory is read every check */

void signal_handler(int sig) {
    stop_flag = 1;             /* changes memory — must be volatile for main to see it */
}

int main(void) {
    signal(SIGINT, signal_handler);
    while (!stop_flag) {       /* reads stop_flag from memory each iteration */
        /* do work */
    }
    printf("Stopped cleanly.\n");
}
```

Use `volatile` for: hardware registers, variables shared with interrupt handlers, variables accessed by multiple threads without a mutex (though for threads, `_Atomic` is better).

---

## 2. restrict — Promise of No Aliasing

`restrict` (C99) tells the compiler that within the current scope, the data pointed to by this pointer is only accessed through this pointer — no other pointer points to the same memory. This enables optimisations the compiler cannot otherwise perform safely.

```c
/* Without restrict — compiler must assume a and b could overlap */
void add_arrays(float *result, float *a, float *b, int n) {
    for (int i = 0; i < n; i++) result[i] = a[i] + b[i];
}

/* With restrict — compiler can vectorise and reorder freely */
void add_arrays(float * restrict result,
                const float * restrict a,
                const float * restrict b, int n) {
    for (int i = 0; i < n; i++) result[i] = a[i] + b[i];
}
```

The standard library declares `memcpy` with `restrict` on both src and dst pointers — that is why `memcpy` is undefined when the buffers overlap (use `memmove` for overlapping regions).

---

## 3. Flexible Array Members (C99)

A struct can have a zero-length array as its last member. You allocate extra space at the end to hold the actual array data.

```c
typedef struct {
    int    count;
    char   label[20];
    int    scores[];    /* flexible array — zero declared size, must be last */
} ScoreSet;

/* Allocate struct + space for 5 scores */
ScoreSet *ss = malloc(sizeof(ScoreSet) + 5 * sizeof(int));
ss->count = 5;
strcpy(ss->label, "Midterm");
for (int i = 0; i < 5; i++) ss->scores[i] = 60 + i*5;

/* sizeof(ScoreSet) does NOT include the flexible member */
/* The extra malloc space makes it work */

free(ss);
```

Used in: network packet structures, OS kernel data structures, any fixed-header + variable-data pattern where you want a single allocation.

---

## 4. _Generic — Type-Generic Macros (C11)

`_Generic` selects a function or expression based on the type of a controlling expression — evaluated at compile time.

```c
#include <math.h>

/* Type-generic sqrt that calls the right version automatically */
#define my_sqrt(x) _Generic((x), \
    float:  sqrtf,               \
    double: sqrt,                \
    long double: sqrtl           \
)(x)

printf("%.6f\n",  my_sqrt(2.0f));    /* calls sqrtf */
printf("%.15f\n", my_sqrt(2.0));     /* calls sqrt */

/* Type name macro — useful for debugging */
#define type_of(x) _Generic((x),     \
    int:           "int",            \
    long:          "long",           \
    float:         "float",          \
    double:        "double",         \
    char *:        "char*",          \
    default:       "other")

int n = 5;
printf("n is a %s\n", type_of(n));   /* "int" */
```

---

## 5. setjmp and longjmp — Non-local Jumps

`setjmp` saves the current execution state. `longjmp` restores it — making it look like `setjmp` returned a second time with a non-zero value.

```c
#include <setjmp.h>

jmp_buf recovery_point;

void risky_parse(const char *s) {
    char *end;
    long val = strtol(s, &end, 10);
    if (*end != '\0') {
        longjmp(recovery_point, 1);   /* jump back to setjmp */
    }
    printf("Parsed: %ld\n", val);
}

int main(void) {
    if (setjmp(recovery_point) == 0) {
        /* Normal path */
        risky_parse("123");    /* OK */
        risky_parse("abc");    /* triggers longjmp */
        printf("Never reached\n");
    } else {
        /* Recovery path — longjmp brought us here */
        printf("Parse error — recovered safely\n");
    }
}
```

Use very sparingly. Local variables not declared `volatile` may have indeterminate values after `longjmp`. Good for: error recovery in deeply nested parsers where propagating error codes through every level is tedious.

---

## 6. _Atomic — Thread-safe Single Operations (C11)

```c
#include <stdatomic.h>

atomic_int counter = 0;

/* Thread-safe increment — no mutex needed for simple operations */
atomic_fetch_add(&counter, 1);

int current = atomic_load(&counter);    /* atomic read */
atomic_store(&counter, 0);              /* atomic write */

/* Compare-and-swap: if counter equals 5, set it to 10 */
int expected = 5;
_Bool swapped = atomic_compare_exchange_strong(&counter, &expected, 10);
```

For simple counters and flags shared between threads, atomics are faster than mutexes. For anything involving multiple variables that must change together consistently, still use a mutex.

---

## 7. Compound Literals (C99)

Create temporary values of any type inline, without declaring a named variable:

```c
/* Pass a struct literal directly */
void configure(struct Config c);
configure((struct Config){ .width=800, .height=600, .title="App" });

/* Temporary array */
int *p = (int[]){ 1, 2, 3, 4, 5 };
for (int i = 0; i < 5; i++) printf("%d ", p[i]);

/* The compound literal exists until the end of the enclosing scope */
```
