# Theory — Functions in C

> **Author: Pavan Shetty H S**

---

## 1. Why Functions Matter

When I first started programming, I put everything in `main()`. It worked for small programs, but the moment my code grew past 50 lines, it became impossible to read or debug.

Functions solve this. You break a large program into named, reusable pieces. Each function does one thing. You test it once and use it many times.

---

## 2. The Parts of a Function

```c
/* PROTOTYPE (forward declaration) — placed before main or in a header */
int add(int a, int b);

/* DEFINITION — the actual implementation */
int add(int a, int b) {         /* a and b are parameters */
    int result = a + b;         /* local variable — only exists inside this function */
    return result;              /* sends the value back to whoever called this */
}

/* CALL — using the function */
int sum = add(10, 20);         /* 10 and 20 are arguments */
printf("%d\n", sum);           /* 30 */
```

**Prototype vs definition:**
- A prototype is just the signature — return type, name, parameter types. No body. It tells the compiler what to expect.
- The definition has the actual body with all the code.
- A function must be defined exactly once. It can be declared (prototyped) many times.

---

## 3. Call by Value — C's Default

In C, all arguments are passed by value. The function receives a **copy** of the argument. Changes inside the function do not affect the original.

```c
void try_to_double(int x) {
    x = x * 2;    /* modifies the LOCAL copy of x */
}

int n = 10;
try_to_double(n);
printf("%d\n", n);    /* still 10 — the original was not changed */
```

This is usually what you want. But sometimes you need to modify the original — that is where pointers come in.

---

## 4. Call by Reference — Using Pointers

To let a function modify a variable, pass its address:

```c
void actually_double(int *x) {
    *x = *x * 2;    /* modifies the original through the pointer */
}

int n = 10;
actually_double(&n);    /* pass the address, not the value */
printf("%d\n", n);      /* 20 — it changed! */
```

**Classic example — swap two numbers:**
```c
/* This does NOT work — both get copies */
void bad_swap(int a, int b) {
    int temp = a; a = b; b = temp;    /* modifies copies only */
}

/* This DOES work — we get the addresses */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int x = 5, y = 10;
swap(&x, &y);
printf("%d %d\n", x, y);   /* 10 5 */
```

---

## 5. Returning Multiple Values

C functions can only `return` one value. When I need to return more, I use pointer parameters:

```c
/* Returns min and max through pointer parameters */
void find_min_max(int arr[], int n, int *min, int *max) {
    *min = *max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < *min) *min = arr[i];
        if (arr[i] > *max) *max = arr[i];
    }
}

int arr[] = {3, 7, 1, 9, 4, 6};
int lo, hi;
find_min_max(arr, 6, &lo, &hi);
printf("Min: %d, Max: %d\n", lo, hi);   /* Min: 1, Max: 9 */
```

---

## 6. Function Prototypes — Why They Exist

```c
/* Without a prototype — compiler assumes wrong things about the function */

/* With a prototype — compiler validates every call you make */
double power(double base, int exp);    /* prototype */

int main(void) {
    printf("%.0f\n", power(2.0, 8));   /* compiler checks: base=double, exp=int */
    return 0;
}

double power(double base, int exp) {   /* definition can come after main */
    double result = 1.0;
    for (int i = 0; i < exp; i++) result *= base;
    return result;
}
```

In larger projects, prototypes go in `.h` header files so any `.c` file can include them.

---

## 7. static Functions — Keeping Things Private

A `static` function is only visible within the file where it is defined. Other `.c` files cannot call it. I use this for helper functions that are implementation details:

```c
/* validate_age is a private helper — no other file should call this */
static int validate_age(int age) {
    return age >= 0 && age <= 150;
}

/* This is the public function — other files can use it */
int set_person_age(int age) {
    if (!validate_age(age)) return -1;
    /* ... */
    return 0;
}
```

---

## 8. Common Mistakes

```c
/* Mistake 1: Returning address of a local variable */
int *bad_function(void) {
    int local = 42;
    return &local;    /* DANGER! local is destroyed when function returns */
}                     /* the pointer is now dangling */

/* Mistake 2: Missing return in non-void function */
int find(int arr[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (arr[i] == key) return i;
    /* forgot: return -1 when not found — undefined behaviour */
}

/* Mistake 3: Ignoring return values */
int result = scanf("%d", &n);
/* What if scanf failed? Always check the return value. */

/* Mistake 4: Calling function before prototype */
int main(void) {
    int x = double_it(5);    /* compiler does not know double_it yet */
}
int double_it(int n) { return n * 2; }
/* Fix: add prototype before main, or move definition before main */
```
