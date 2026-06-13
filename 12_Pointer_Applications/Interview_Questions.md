# Interview Questions — Pointer Applications

## 🟢 Basic

**Q1. What is a function pointer and how do you declare one?**
> A function pointer stores the address of a function. Declaration: `return_type (*ptr_name)(param_types);`. Example: `int (*fp)(int, int) = &add;`. Call: `fp(3, 4)` or `(*fp)(3, 4)`. Used for callbacks, dispatch tables, and plugins.

**Q2. What is a void pointer?**
> `void *` is a generic pointer that can hold the address of any data type. It cannot be dereferenced directly — must be cast to a concrete type first. `malloc()` returns `void *`. Used in generic functions like `memcpy`, `qsort`, `bsearch`.

**Q3. When would you use a double pointer `**p`?**
> - To modify a pointer variable inside a function (you pass `&ptr`)
> - To build dynamic 2D arrays (array of pointers to arrays)
> - Command-line arguments `char **argv`
> - Linked list node insertion (modifying `head` pointer)

## 🟡 Intermediate

**Q4. How does `qsort` use function pointers?**
> `qsort(arr, n, size, comparator)` sorts `n` elements of `size` bytes each. The comparator is a `int (*)(const void*, const void*)` function pointer. `qsort` calls it with pairs of elements to determine order. Returns <0, 0, or >0 for less-than, equal, greater-than.

**Q5. What is the difference between `int *arr[5]` and `int (*arr)[5]`?**
> `int *arr[5]`: array of 5 pointers to int — 5 independent pointers. `int (*arr)[5]`: pointer to an array of 5 ints — a single pointer that can step through rows of a 2D array. Use the latter for passing 2D arrays to functions.

**Q6. How do you pass a 2D array to a function?**
```c
/* Fixed columns — most common */
void func(int mat[][4], int rows);

/* Using pointer to array */
void func(int (*mat)[4], int rows);

/* Using double pointer (for dynamic 2D) */
void func(int **mat, int rows, int cols);
```

## 🔴 Advanced

**Q7. Explain how to implement a generic stack using void pointers.**
```c
typedef struct {
    void **data;
    int top, capacity;
    size_t elem_size;
} GenStack;
/* push: memcpy element into data[top++] */
/* pop:  memcpy data[--top] into output buffer */
/* Works for any type without code duplication */
```

**Q8. What is a pointer to a function returning a pointer to a function?**
```c
/* Convoluted but valid: */
int (*(*get_op(char op))(int))(int);
/* Use typedef to clarify: */
typedef int (*Handler)(int);
typedef Handler (*GetHandler)(char);
/* Much more readable! Always typedef complex function pointers. */
```

**Q9. Why is `int (*fp)()` different from `int (*fp)(void)` in C?**
> `int (*fp)()` — pointer to function with unspecified parameters (K&R style, accepts any arguments — legacy). `int (*fp)(void)` — pointer to function that takes NO parameters (strict, modern C). Always use `(void)` for zero-parameter functions in modern C code.

---

*— Pavan Shetty H S*
