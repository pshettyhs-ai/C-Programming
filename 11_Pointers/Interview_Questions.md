# Interview Questions — Pointers

> **Author: Pavan Shetty H S**
>
> Pointers are the most tested topic in C interviews. I collected every question I encountered and answered them carefully.

---

## 🟢 Basic

**Q1. What is a pointer?**

A pointer is a variable that stores the memory address of another variable. It does not store a value directly — it stores a location. You access the value at that location using the dereference operator `*`.

```c
int x = 10;
int *p = &x;      /* p stores the address of x */
printf("%d\n", *p);   /* 10 — value at that address */
```

---

**Q2. What does `*` mean in a pointer declaration vs in an expression?**

In a **declaration** like `int *p`, the `*` means "p is a pointer to int" — it is part of the type syntax.

In an **expression** like `*p = 5`, the `*` is the dereference operator — it accesses the value at the address stored in p.

Same symbol, completely different meaning depending on context.

---

**Q3. What is the size of a pointer?**

On a 32-bit system: 4 bytes. On a 64-bit system: 8 bytes. This is true regardless of what the pointer points to — `sizeof(int*)`, `sizeof(char*)`, and `sizeof(void*)` are all the same on a given platform.

---

**Q4. What is a NULL pointer? When should you use it?**

NULL is a macro defined as `(void*)0` — it represents a pointer that does not point to any valid memory location. You should set a pointer to NULL when it has no valid address yet, and after you call `free()` on it. Always check `if (ptr != NULL)` before dereferencing any pointer that might be unset.

---

## 🟡 Intermediate

**Q5. What is the difference between `const int *p` and `int * const p`?**

`const int *p` — the value at the address cannot be changed through p, but p can be pointed at a different address. "Pointer to constant int."

`int * const p` — p itself cannot be reassigned to a different address, but the value it points to can be changed. "Constant pointer to int."

A quick mental check: find the `*` and look at where `const` appears relative to it.

---

**Q6. What is pointer arithmetic? Give an example.**

Adding an integer n to a pointer moves it forward by `n × sizeof(type)` bytes — not n bytes. So `p + 1` for an `int *p` advances by 4 bytes (one int), landing on the next element.

```c
int arr[] = {10, 20, 30};
int *p = arr;
printf("%d\n", *(p + 2));   /* 30 — moved 2 × 4 = 8 bytes forward */
```

---

**Q7. What is a dangling pointer? How do you prevent it?**

A dangling pointer holds the address of memory that is no longer valid — either because the variable went out of scope, or because the memory was freed. Accessing it is undefined behaviour.

Prevention: always set a pointer to `NULL` after `free()`, and never return the address of a local variable from a function.

---

**Q8. What is a wild pointer? How is it different from a dangling pointer?**

A wild pointer is an uninitialized pointer — it was declared but never assigned a valid address. It contains whatever garbage was in memory at that location. A dangling pointer was valid at some point but is no longer.

Both are dangerous. Both cause undefined behaviour when dereferenced. Fix: always initialize pointers, set to `NULL` when not in use.

---

## 🔴 Advanced

**Q9. What is the strict aliasing rule?**

The C standard says the compiler can assume that pointers of different types do not point to the same memory. This lets the compiler reorder loads and stores for optimization. Violating it — like accessing a `float` through an `int *` — is undefined behaviour. The only safe way to type-pun in C is through a `union` or `memcpy`.

---

**Q10. Explain the output of this code:**
```c
int arr[3] = {10, 20, 30};
int *p = arr;
printf("%d %d\n", *p++, *p);
```

This is undefined behaviour. `p` is both modified (`p++`) and read (`*p`) without a sequence point separating the two accesses. The compiler is free to evaluate the arguments in any order. Never write this kind of expression.

---

**Q11. What is `restrict` and when would you use it?**

`restrict` (C99) tells the compiler that within the current scope, this pointer is the only way to access the memory it points to — no aliasing. This lets the compiler perform optimisations it could not otherwise do safely. It is used in performance-critical code: `memcpy` in the standard library is declared with `restrict` on both parameters.

---

*— Pavan Shetty H S*
