# Memory Concepts — Introduction to C Programming

## 1. C Program Memory Layout

When the OS loads a C program, it partitions memory into five segments:

```
Higher Addresses
┌─────────────────────────────────────────────┐
│          STACK SEGMENT                      │
│  • Local variables                          │
│  • Function parameters                      │
│  • Return addresses                         │
│  • Grows DOWNWARD (toward lower addresses)  │
│                 ↓ grows                     │
├─────────────────────────────────────────────┤
│                                             │
│            (free / unallocated)             │
│                                             │
├─────────────────────────────────────────────┤
│                 ↑ grows                     │
│          HEAP SEGMENT                       │
│  • Dynamically allocated memory             │
│  • malloc(), calloc(), realloc()            │
│  • Grows UPWARD (toward higher addresses)   │
├─────────────────────────────────────────────┤
│          BSS SEGMENT                        │
│  • Uninitialized global/static variables    │
│  • Zero-initialized automatically by OS    │
├─────────────────────────────────────────────┤
│          DATA SEGMENT                       │
│  • Initialized global/static variables      │
│  • e.g., int g = 42; at file scope          │
├─────────────────────────────────────────────┤
│          TEXT SEGMENT (Code Segment)        │
│  • Compiled machine instructions            │
│  • Read-only — prevents self-modification   │
│  • Shared between processes (same program)  │
└─────────────────────────────────────────────┘
Lower Addresses
```

## 2. Where Each Variable Lives

```c
#include <stdio.h>
#include <stdlib.h>

int   globalInit   = 100;      /* DATA segment   — initialized global */
int   globalUninit;            /* BSS  segment   — uninitialized global (= 0) */
static int staticGlobal = 5;   /* DATA segment   — static global */

int main(void) {

    int   local      = 42;     /* STACK segment  — local variable */
    static int s     = 0;      /* DATA segment   — static local (persists) */
    int   *heapPtr   = malloc(sizeof(int));  /* HEAP segment */

    *heapPtr = 99;

    printf("globalInit  @ %p (DATA)\n",  (void*)&globalInit);
    printf("globalUninit@ %p (BSS)\n",   (void*)&globalUninit);
    printf("staticGlobal@ %p (DATA)\n",  (void*)&staticGlobal);
    printf("local       @ %p (STACK)\n", (void*)&local);
    printf("staticLocal @ %p (DATA)\n",  (void*)&s);
    printf("heapPtr val @ %p (HEAP)\n",  (void*)heapPtr);

    free(heapPtr);
    return 0;
}
```

## 3. Stack Frames — How Function Calls Work

Each function call creates a **stack frame** (also called activation record):

```
Stack during execution of add(3, 4) called from main():

┌────────────────────────────┐  ← Stack grows downward
│    main() Stack Frame      │
│  ─────────────────────     │
│  int result  = ?           │  ← local var, waiting for return
│  int y = 4                 │
│  int x = 3                 │
│  return address (to OS)    │
├────────────────────────────┤
│    add() Stack Frame       │  ← pushed when add() called
│  ─────────────────────     │
│  int sum = 7               │  ← local var
│  int b = 4                 │  ← parameter
│  int a = 3                 │  ← parameter
│  return address (to main)  │  ← where to return after add()
└────────────────────────────┘

When add() returns:
  • add() frame is POPPED off the stack
  • Execution resumes in main() at return address
  • Return value (7) placed in result
```

## 4. Variable Scope and Lifetime Summary

| Variable Kind | Where Declared | Scope | Lifetime | Default Value |
|---|---|---|---|---|
| Local | Inside `{ }` block | That block only | Block execution | **Garbage** |
| Global | Outside all functions | Entire file (and extern files) | Whole program | **0** |
| Static local | Inside block with `static` | That block only | Whole program | **0** |
| Static global | File scope with `static` | This file only | Whole program | **0** |
| Function parameter | Function signature | Function body | Function call | Passed value |
| Dynamic (`malloc`) | Anywhere via pointer | Anywhere pointer reaches | Until `free()` | **Garbage** |

## 5. Stack vs Heap Comparison

| Property | Stack | Heap |
|----------|-------|------|
| Management | Automatic (compiler) | Manual (programmer) |
| Speed | Very fast (just move SP) | Slower (system call) |
| Size | Limited (~1–8 MB) | Large (limited by RAM) |
| Fragmentation | None | Possible |
| Thread-safe | Each thread has own stack | Shared — needs sync |
| Memory leak risk | None (auto freed) | Yes — must call `free()` |
| Access pattern | LIFO | Random access |

## 6. Common Memory Pitfalls (Preview)

```c
/* PITFALL 1: Uninitialized local variable — garbage value */
int x;
printf("%d", x);   // Undefined behavior — x has random garbage!

/* PITFALL 2: Returning address of local variable — dangling pointer */
int* bad_function(void) {
    int local = 5;
    return &local;  // ERROR: local destroyed when function returns!
}

/* PITFALL 3: Stack overflow — infinite recursion */
void infinite(void) {
    infinite();    // Keeps pushing frames until stack exhausted!
}

/* PITFALL 4: Heap memory leak — forgetting free() */
int *p = malloc(100 * sizeof(int));
// ... use p ...
// forgot free(p) — memory leaked until program exits!
```

---

*— Pavan Shetty H S*
