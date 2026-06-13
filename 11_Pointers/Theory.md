# Theory — Pointers

> **Author: Pavan Shetty H S**

---

## 1. The One Thing That Changes Everything

Pointers were the topic I spent the most time on. When they finally clicked, everything else in C became easier — dynamic memory, data structures, function callbacks, efficient string manipulation. It all depends on understanding pointers.

Here is the core idea: **a pointer is a variable that stores a memory address.**

```c
int  value = 42;       /* a normal integer variable */
int *ptr   = &value;   /* ptr stores the ADDRESS of value */

/*  value:  42   at address  0x7ffd1234
    ptr:    0x7ffd1234  (the address of value)
    *ptr:   42   (the value AT that address — dereferencing)
*/
```

**Two key operators:**
- `&` (address-of): gives you the memory address of a variable
- `*` (dereference): gives you the value stored at an address

---

## 2. Declaration and Initialization

```c
int    *p;       /* pointer to int */
float  *q;       /* pointer to float */
char   *s;       /* pointer to char (commonly used for strings) */
void   *v;       /* pointer to void — can point to any type */
int   **pp;      /* pointer to a pointer to int */

/* ALWAYS initialize pointers before using them */
int x = 10;
int *p = &x;      /* good: points to x */
int *q = NULL;    /* good: explicitly "no address" */
int *r;           /* BAD: wild pointer — contains garbage address */
```

---

## 3. Dereferencing — Reading and Writing Through a Pointer

```c
int x = 42;
int *p = &x;

printf("%d\n", *p);    /* 42 — read the value at address p */

*p = 100;              /* write through the pointer — changes x */
printf("%d\n", x);     /* 100 — x was changed! */
```

**This is how functions modify variables in the calling code:**
```c
void increment(int *ptr) {
    (*ptr)++;    /* parentheses needed: *ptr++ would increment the pointer, not the value */
}

int n = 5;
increment(&n);
printf("%d\n", n);   /* 6 */
```

---

## 4. Pointer Arithmetic

Adding or subtracting from a pointer moves it by multiples of the pointed-to type's size, not by bytes.

```c
int arr[] = {10, 20, 30, 40, 50};
int *p = arr;                 /* points to arr[0] */

printf("%d\n", *p);           /* 10 */
p++;                           /* moves 4 bytes forward (sizeof int) */
printf("%d\n", *p);           /* 20 */
p += 2;
printf("%d\n", *p);           /* 40 */

/* Difference between two pointers gives element count */
int *start = arr;
int *end   = arr + 5;
printf("%td\n", end - start); /* 5 */
```

**Valid pointer arithmetic:**
- Add or subtract an integer to move within the same array
- Subtract two pointers to get element count (same array only)
- Compare two pointers from the same array

**Invalid:** arithmetic on unrelated pointers, or going more than one past the array end.

---

## 5. const with Pointers — Four Combinations

This confused me at first. Read the declaration right-to-left:

```c
/* 1. Pointer to int — both changeable */
int *p = &x;
*p = 5;   /* OK */
p  = &y;  /* OK */

/* 2. Pointer to CONST int — value locked, pointer can move */
const int *p = &x;
*p = 5;   /* ERROR: cannot change value through p */
p  = &y;  /* OK: p can point elsewhere */

/* 3. CONST pointer to int — pointer locked, value can change */
int * const p = &x;
*p = 5;   /* OK: can change value */
p  = &y;  /* ERROR: cannot reassign p */

/* 4. CONST pointer to CONST int — both locked */
const int * const p = &x;
*p = 5;   /* ERROR */
p  = &y;  /* ERROR */
```

**My memory trick:** read from right to left. `const int *p` — p is a pointer to const int. `int * const p` — p is a const pointer to int.

Use `const int *p` when passing a pointer to a function that should not modify the value. It is a contract you make with the compiler.

---

## 6. NULL Pointers and Safety

```c
int *p = NULL;    /* NULL means: this pointer currently points to nothing */

/* Always check before dereferencing any pointer that might be NULL */
if (p != NULL) {
    *p = 5;       /* safe */
}

/* This is why malloc checks matter */
int *arr = malloc(100 * sizeof(int));
if (arr == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(1);
}
```

---

## 7. Common Pointer Bugs — The Ones That Will Hurt You

```c
/* Bug 1: Wild pointer — uninitialized */
int *p;
*p = 5;    /* writes to a random memory address — crash or silent corruption */
/* Fix: always initialize: int *p = NULL; or int *p = &variable; */

/* Bug 2: NULL dereference */
int *p = NULL;
*p = 5;    /* crash — segfault every time */
/* Fix: check for NULL before dereferencing */

/* Bug 3: Dangling pointer — pointing to freed/out-of-scope memory */
int *get_value(void) {
    int local = 42;
    return &local;     /* local dies when function returns */
}                      /* returned pointer now points to dead memory */

/* Bug 4: Dangling pointer after free */
int *p = malloc(sizeof(int));
free(p);
*p = 5;    /* undefined behaviour — memory was returned to heap */
p = NULL;  /* always do this after free */

/* Bug 5: Buffer overrun */
int arr[5];
int *p = arr;
*(p + 10) = 0;    /* writing 40 bytes past the array — corrupts other memory */
```

---

## 8. Double Pointers

A pointer to a pointer. Used when you need to modify a pointer variable from within a function, or to build 2D dynamic arrays.

```c
int   x   = 42;
int  *p   = &x;     /* p holds address of x */
int **pp  = &p;     /* pp holds address of p */

printf("%d\n", x);     /* 42 */
printf("%d\n", *p);    /* 42 */
printf("%d\n", **pp);  /* 42 — two levels of dereferencing */

**pp = 99;
printf("%d\n", x);     /* 99 — modified through two pointer levels */

/* Typical use: modify a pointer inside a function */
void allocate(int **arr, int n) {
    *arr = malloc(n * sizeof(int));   /* modifies the caller's pointer */
}

int *data = NULL;
allocate(&data, 10);   /* data now points to 10-int block on heap */
```
