# Theory — Dynamic Memory Allocation

> **Author: Pavan Shetty H S**

---

## 1. Why Dynamic Memory Exists

Static arrays have a fixed size decided at compile time. But what if you do not know how many students will be in the list until the user tells you at runtime? That is what dynamic memory allocation solves.

```c
/* Static — size fixed at compile time */
int scores[100];     /* always 100, even if you only use 3 */

/* Dynamic — size decided at runtime */
int n;
printf("How many scores? ");
scanf("%d", &n);
int *scores = malloc(n * sizeof(int));   /* exactly n, no more no less */
```

---

## 2. The Four Functions

```c
#include <stdlib.h>

/* malloc — allocate bytes, contents UNINITIALISED (garbage) */
void *malloc(size_t size);

/* calloc — allocate n elements, ALL ZEROED */
void *calloc(size_t count, size_t element_size);

/* realloc — resize an existing allocation */
void *realloc(void *ptr, size_t new_size);

/* free — return memory to the heap */
void free(void *ptr);
```

---

## 3. malloc — Basic Allocation

```c
/* Always write sizeof(*ptr), not sizeof(type) */
/* If you later change int to long, sizeof(*arr) still works */
int *arr = malloc(10 * sizeof(*arr));

/* ALWAYS check the return value */
if (arr == NULL) {
    fprintf(stderr, "Error: malloc failed\n");
    exit(EXIT_FAILURE);
}

/* Use the memory */
for (int i = 0; i < 10; i++) arr[i] = i * i;

/* ALWAYS free when done */
free(arr);
arr = NULL;    /* prevents accidental use after free */
```

---

## 4. calloc — When You Need Zeroed Memory

```c
/* calloc(count, element_size) — allocates count × element_size bytes, all zero */
int *zeros = calloc(10, sizeof(int));
/* zeros[0] through zeros[9] are all 0 */

/* malloc equivalent (but calloc is cleaner) */
int *zeros2 = malloc(10 * sizeof(int));
memset(zeros2, 0, 10 * sizeof(int));
```

Use `calloc` when you need the memory to be zero from the start — for counters, accumulators, or arrays you will fill partially.

---

## 5. realloc — Growing and Shrinking Allocations

```c
/* Critical: never assign realloc result directly to the original pointer */
/* If realloc fails, it returns NULL — you lose the original pointer and leak memory */

/* WRONG */
arr = realloc(arr, new_size);    /* if this fails, arr = NULL, original memory lost */

/* CORRECT */
int *tmp = realloc(arr, new_size * sizeof(int));
if (tmp == NULL) {
    free(arr);      /* clean up original */
    return -1;      /* report error */
}
arr = tmp;          /* safe to update now */
```

---

## 6. Dynamic Array — The Most Common Pattern

```c
typedef struct {
    int  *data;
    int   size;
    int   capacity;
} DynArray;

void da_init(DynArray *da, int initial_cap) {
    da->data     = malloc(initial_cap * sizeof(int));
    da->size     = 0;
    da->capacity = initial_cap;
}

void da_push(DynArray *da, int value) {
    if (da->size == da->capacity) {
        da->capacity *= 2;    /* double capacity */
        int *tmp = realloc(da->data, da->capacity * sizeof(int));
        if (!tmp) { free(da->data); exit(1); }
        da->data = tmp;
    }
    da->data[da->size++] = value;
}

void da_free(DynArray *da) {
    free(da->data);
    da->data     = NULL;
    da->size     = 0;
    da->capacity = 0;
}
```

---

## 7. The Four Memory Errors You Must Know

```c
/* Error 1: Memory leak — forgot to free */
void bad(void) {
    int *p = malloc(100 * sizeof(int));
    /* ... use p ... */
    return;    /* p never freed — this memory is leaked */
}

/* Error 2: Double free — freeing same pointer twice */
free(p);
free(p);    /* undefined behaviour — heap corruption */

/* Error 3: Use after free */
free(p);
*p = 5;     /* undefined behaviour — memory may be reallocated to something else */
/* Fix: set p = NULL after every free */

/* Error 4: Writing past allocated bounds */
int *arr = malloc(5 * sizeof(int));
arr[5] = 10;    /* writes past end — corrupts heap metadata */
```

**How to detect these:** compile with `gcc -fsanitize=address -g` or run under Valgrind: `valgrind --leak-check=full ./program`

---

## 8. Dynamic Struct with Nested Allocation

```c
typedef struct {
    char *name;
    int  *scores;
    int   count;
} Student;

Student *create_student(const char *name, int n) {
    Student *s  = malloc(sizeof(Student));
    s->name     = malloc(strlen(name) + 1);   /* +1 for null terminator */
    s->scores   = malloc(n * sizeof(int));
    s->count    = n;
    strcpy(s->name, name);
    return s;
}

void free_student(Student *s) {
    free(s->scores);    /* free nested allocations first */
    free(s->name);
    free(s);            /* then free the struct itself */
    /* Always free in reverse order of allocation */
}
```
