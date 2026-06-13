# Theory — Arrays

> **Author: Pavan Shetty H S**

---

## 1. What is an Array?

An array stores multiple values of the **same type** in **contiguous memory locations**. Instead of declaring ten separate integer variables, you declare one array of ten integers.

```c
/* Without array: tedious and error-prone */
int score0, score1, score2, score3, score4;

/* With array: clean and flexible */
int scores[5];    /* 5 integers, stored back-to-back in memory */
scores[0] = 85;   /* index starts at 0, not 1 */
scores[4] = 92;   /* last valid index is size-1 */
```

**Memory layout of `int scores[5]`:**
```
Address:  1000   1004   1008   1012   1016
         ┌──────┬──────┬──────┬──────┬──────┐
         │  85  │  ?   │  ?   │  ?   │  92  │
         └──────┴──────┴──────┴──────┴──────┘
Index:     [0]    [1]    [2]    [3]    [4]

Each int is 4 bytes, so addresses differ by 4.
Element i is at: base_address + i × sizeof(int)
```

---

## 2. Declaring and Initializing Arrays

```c
/* Declaration — size must be known at compile time */
int scores[5];                      /* uninitialised (local) — garbage values */
float prices[10] = {0};             /* all 10 set to 0.0 */

/* Full initialization */
int days[7] = {31, 28, 31, 30, 31, 30, 31};

/* Partial initialization — rest automatically set to 0 */
int arr[5] = {10, 20};              /* {10, 20, 0, 0, 0} */

/* Let compiler count the size */
int primes[] = {2, 3, 5, 7, 11};   /* compiler makes it size 5 */

/* Designated initializers (C99) */
int flags[8] = {[0]=1, [3]=1, [7]=1};   /* {1,0,0,1,0,0,0,1} */
```

**How I count elements without a separate variable:**
```c
int arr[] = {10, 20, 30, 40, 50};
int n = sizeof(arr) / sizeof(arr[0]);   /* 5 */
```

This only works where the array is declared. Inside a function that receives the array as a parameter, it gives the pointer size, not the array size.

---

## 3. Arrays and Pointers — They are Very Closely Related

This is one of those things that confuses beginners until it suddenly clicks.

```c
int arr[] = {10, 20, 30, 40, 50};

/* These four expressions all give the same result: 30 */
arr[2]          /* normal subscript notation */
*(arr + 2)      /* pointer arithmetic */
*(2 + arr)      /* addition is commutative */
2[arr]          /* valid C! (but please never write this) */
```

The reason: `arr[i]` is defined as `*(arr + i)` — it is just pointer arithmetic. The array name `arr` evaluates to a pointer to its first element.

But arrays and pointers are NOT the same thing:
```c
int arr[5] = {1,2,3,4,5};
int *p = arr;

sizeof(arr)    /* 20 — total array size in bytes */
sizeof(p)      /* 8  — just the pointer (on 64-bit) */

arr = p;       /* ERROR — array name is not a variable, cannot reassign */
p   = arr;     /* OK — p is a pointer variable */
```

---

## 4. Passing Arrays to Functions

When you pass an array to a function, it decays to a pointer to its first element. The function does not get a copy of the array — it gets direct access to the original.

```c
/* These two signatures are identical */
void print_array(int arr[], int n) { }
void print_array(int *arr, int n)  { }

/* Always pass the size separately — the function cannot know it otherwise */
void sum_array(int arr[], int n, int *total) {
    *total = 0;
    for (int i = 0; i < n; i++) *total += arr[i];
}

int nums[] = {1, 2, 3, 4, 5};
int result;
sum_array(nums, 5, &result);
```

---

## 5. 2D Arrays

A 2D array is an array of arrays. In memory, it is stored row by row (row-major order).

```c
int matrix[3][4];    /* 3 rows, 4 columns */

/* Initialization */
int grid[2][3] = {{1, 2, 3},
                  {4, 5, 6}};

/* Accessing elements */
printf("%d\n", grid[1][2]);   /* 6 — row 1, column 2 */

/* Iterating */
for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
        printf("%4d", grid[i][j]);
    }
    printf("\n");
}
```

**Why row-major matters for performance:**
```c
/* Cache-friendly: row by row — adjacent elements in memory */
for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
        sum += matrix[i][j];   /* fast */

/* Cache-unfriendly: column by column — jumps in memory */
for (int j = 0; j < cols; j++)
    for (int i = 0; i < rows; i++)
        sum += matrix[i][j];   /* slow for large matrices */
```

---

## 6. Common Mistakes

```c
/* Mistake 1: Off-by-one — accessing arr[n] which does not exist */
int arr[5];
for (int i = 0; i <= 5; i++)    /* i <= 5 goes one past the end */
    arr[i] = 0;                 /* arr[5] is out of bounds — undefined behaviour */
/* Fix: i < 5 */

/* Mistake 2: Sizeof array inside function */
void bad_size(int arr[]) {
    int n = sizeof(arr) / sizeof(arr[0]);   /* WRONG — gives pointer size / 4 */
}
/* Fix: pass n as a separate parameter */

/* Mistake 3: Not initializing */
int arr[10];
printf("%d\n", arr[3]);    /* garbage value — undefined behaviour */
/* Fix: int arr[10] = {0}; initializes all to zero */

/* Mistake 4: Comparing arrays with == */
int a[] = {1,2,3}, b[] = {1,2,3};
if (a == b) { ... }    /* compares pointer addresses, not contents */
/* Fix: use memcmp(a, b, sizeof(a)) == 0 */
```
