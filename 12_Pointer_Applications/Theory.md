# Theory — Pointer Applications

> **Author: Pavan Shetty H S**

---

## 1. Why This Chapter Exists

Once you understand basic pointers, the next step is learning how they power the most flexible patterns in C. This chapter covers four ideas that keep appearing everywhere: function pointers, void pointers, double pointers, and pointer arrays. Master these and you will understand how the standard library itself is built.

---

## 2. Function Pointers

A function pointer stores the address of a function. You can call a function through a pointer just like you call it by name.

**Declaration syntax:**
```c
/* return_type (*pointer_name)(parameter_types); */
int (*fp)(int, int);       /* pointer to a function taking 2 ints, returning int */
```

**Basic usage:**
```c
int add(int a, int b) { return a + b; }
int mul(int a, int b) { return a * b; }

int (*op)(int, int);

op = add;
printf("%d\n", op(3, 4));   /* 7 — calls add */

op = mul;
printf("%d\n", op(3, 4));   /* 12 — calls mul */
```

**typedef makes complex declarations readable:**
```c
typedef int (*MathOp)(int, int);

MathOp ops[]   = { add, mul };
char  *names[] = { "add", "mul" };

for (int i = 0; i < 2; i++)
    printf("%s(5, 3) = %d\n", names[i], ops[i](5, 3));
```

**Real-world use — dispatch table (like a switch with no limits):**
```c
typedef struct {
    const char *command;
    void (*handler)(void);
} Command;

void cmd_help(void)  { printf("Available commands: help, quit\n"); }
void cmd_quit(void)  { exit(0); }

Command table[] = {
    { "help", cmd_help },
    { "quit", cmd_quit },
};

/* To dispatch: compare input string, call matching handler */
```

**Callback pattern — how qsort works:**
```c
int cmp_ascending(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int arr[] = { 5, 2, 8, 1, 9 };
qsort(arr, 5, sizeof(int), cmp_ascending);
/* qsort does not know your type — you provide the comparison logic */
```

---

## 3. void Pointers — Generic Pointers

`void *` can hold any pointer type without a cast. It cannot be dereferenced or used in arithmetic directly — you must cast it to a concrete type first.

```c
void *p;

int    i = 42;
double d = 3.14;
char   s[] = "Pavan";

p = &i;   printf("%d\n",   *(int *)p);
p = &d;   printf("%.2f\n", *(double *)p);
p = s;    printf("%s\n",   (char *)p);
```

**Where void pointers appear constantly:**
- `malloc` returns `void *` — works for any type
- `qsort` and `bsearch` accept `void *` arrays and comparators
- `memcpy` and `memset` operate on `void *`

**Generic swap using void pointers:**
```c
void swap(void *a, void *b, size_t size) {
    unsigned char temp[256];     /* temporary buffer */
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
}

int x = 10, y = 20;
swap(&x, &y, sizeof(int));   /* x=20, y=10 */

double p = 1.5, q = 9.9;
swap(&p, &q, sizeof(double));
```

---

## 4. Double Pointers — Pointer to Pointer

**Use case 1: Modify a pointer inside a function**
```c
/* This does NOT work — the function gets a copy of the pointer */
void bad_alloc(int *p, int n) {
    p = malloc(n * sizeof(int));    /* modifies local copy only */
}

/* This DOES work — pass the address of the pointer */
void good_alloc(int **pp, int n) {
    *pp = malloc(n * sizeof(int));  /* modifies caller's pointer */
}

int *arr = NULL;
good_alloc(&arr, 10);
/* arr now points to 10 ints on the heap */
```

**Use case 2: Dynamic 2D arrays**
```c
int rows = 3, cols = 4;

int **matrix = malloc(rows * sizeof(int *));    /* array of row pointers */
for (int i = 0; i < rows; i++)
    matrix[i] = malloc(cols * sizeof(int));     /* each row */

matrix[1][2] = 99;    /* access like a 2D array */

/* Free in reverse order */
for (int i = 0; i < rows; i++) free(matrix[i]);
free(matrix);
```

**Use case 3: argv — command line arguments**
```c
int main(int argc, char **argv) {
    /* argv is char** — an array of strings */
    /* argv[0] = program name */
    /* argv[1] = first argument, etc. */
    printf("Program: %s\n", argv[0]);
}
```

---

## 5. Arrays of Pointers vs Pointer to Array

```c
/* Array of 5 pointers to int — each pointer is independent */
int a=1, b=2, c=3;
int *ptrs[3] = { &a, &b, &c };
printf("%d\n", *ptrs[1]);       /* 2 */

/* Pointer to an array of 5 ints — moves one whole row at a time */
int arr[5] = {1, 2, 3, 4, 5};
int (*parr)[5] = &arr;
printf("%d\n", (*parr)[3]);     /* 4 */

/* Array of strings is array of char pointers */
const char *days[] = { "Mon","Tue","Wed","Thu","Fri","Sat","Sun" };
printf("%s\n", days[0]);        /* Mon */
```

---

## 6. Pointers to Structs — The Arrow Operator

```c
typedef struct {
    char  name[50];
    int   age;
    float gpa;
} Student;

Student s = { "Pavan", 21, 9.1f };
Student *p = &s;

/* Two identical ways to access members through a pointer */
printf("%s\n", (*p).name);   /* old style — dereference then dot */
printf("%s\n", p->name);     /* arrow operator — shorter, preferred */

p->age = 22;    /* modify through pointer */
```

The arrow operator `->` is just shorthand for `(*pointer).member`. Use it always — it is cleaner.
