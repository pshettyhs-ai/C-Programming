# Theory — Storage Classes

> **Author: Pavan Shetty H S**

---

## 1. What is a Storage Class?

A storage class tells the compiler three things about a variable: where it is stored in memory, what its default initial value is, and how long it lives.

C has four storage classes: `auto`, `register`, `static`, and `extern`.

---

## 2. auto — The Default

Every local variable is `auto` by default. You almost never write the keyword explicitly.

```c
void demo(void) {
    auto int x = 10;    /* 'auto' is almost always omitted */
    int  y = 20;        /* same thing */
    /* x and y live on the stack, die when demo() returns */
}
```

Properties: stored on stack, uninitialized (garbage), scope limited to block, lifetime equals block execution.

---

## 3. register — A Historical Hint

`register` was a hint to the compiler to store a variable in a CPU register for speed. Modern compilers ignore it entirely and do their own register allocation. It is almost never used in new code.

```c
register int sum = 0;
for (register int i = 0; i < 1000000; i++) sum += i;

/* Note: you cannot take the address of a register variable */
/* &sum  would be a compile error */
```

---

## 4. static — Two Completely Different Uses

`static` is the most important storage class. It has two meanings depending on where it appears.

**Use 1: static local variable — retains its value between calls**
```c
void counter(void) {
    static int count = 0;    /* initialized ONCE, lives for entire program */
    count++;
    printf("Called %d time(s)\n", count);
}

counter();    /* Called 1 time(s)  */
counter();    /* Called 2 time(s)  */
counter();    /* Called 3 time(s)  */
```

Without `static`, `count` would reset to 0 every call. With `static`, it persists.

**Use 2: static at file scope — internal linkage**
```c
/* file1.c */
static int private_var = 100;      /* not visible to other .c files */
static void helper(void) { ... }   /* private helper function */

int public_api(int x) {            /* visible to other .c files */
    return helper(x) + private_var;
}
```

This is how you write private implementation details. Any `.c` file can define its own `static int count` without conflicting with another file's `static int count`.

---

## 5. extern — Sharing Across Files

`extern` declares that a variable or function is defined in a different translation unit (another `.c` file). It allocates no memory — it is just a declaration.

```c
/* globals.c — DEFINITION (memory allocated here) */
int global_score = 0;
void reset_score(void) { global_score = 0; }

/* main.c — DECLARATIONS (no memory, just tells compiler it exists) */
extern int   global_score;
extern void  reset_score(void);

int main(void) {
    global_score = 100;
    reset_score();
    printf("%d\n", global_score);    /* 0 */
}
```

---

## 6. Where Each Variable Type Lives in Memory

| Variable | Storage | Initialized to | Lifetime | Scope |
|----------|---------|----------------|----------|-------|
| `auto` local | Stack | Garbage | Block | Block |
| `static` local | Data/BSS | 0 | Program | Block |
| `static` global | Data/BSS | 0 | Program | File only |
| `extern` global | Data/BSS | 0 | Program | All files |
| `register` | Register/Stack | Garbage | Block | Block |

---

## 7. Practical Uses I Actually Apply

```c
/* Pattern 1: ID generator using static local */
int next_id(void) {
    static int id = 0;
    return ++id;
}
/* Calling next_id() gives 1, 2, 3, 4 ... */

/* Pattern 2: Memoization cache using static array */
long long fibonacci(int n) {
    static long long cache[100] = {0};
    if (n <= 1) return n;
    if (cache[n]) return cache[n];
    cache[n] = fibonacci(n-1) + fibonacci(n-2);
    return cache[n];
}

/* Pattern 3: Keeping helper functions private */
static int is_valid(int x) { return x > 0 && x < 1000; }
int process(int x) {
    if (!is_valid(x)) return -1;
    return x * 2;
}
```
