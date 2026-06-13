# Interview Questions — Structures

## 🟢 Basic

**Q1. What is a structure in C? How is it different from an array?**
> A structure groups variables of DIFFERENT types under one name. An array groups variables of the SAME type. `struct Student { char name[50]; int roll; float gpa; }` — three different types in one unit. Arrays: `int scores[5]` — all same type, indexed numerically.

**Q2. What is the difference between `.` and `->` operators?**
> `.` accesses a struct member through a struct variable: `s.name`. `->` accesses through a pointer: `ptr->name` which is shorthand for `(*ptr).name`. Use `.` with values, `->` with pointers.

**Q3. Can a struct contain another struct?**
> Yes — nested structures. A struct can contain any type including other structs (by value). It CANNOT contain itself by value (infinite size), but CAN contain a pointer to itself (for linked lists, trees, etc.).

## 🟡 Intermediate

**Q4. What is struct padding and why does the compiler add it?**
> Processors access data most efficiently when it is aligned to its natural boundary (an `int` at a 4-byte boundary, `double` at 8-byte). The compiler inserts padding bytes between struct members to ensure alignment. This means `sizeof(struct)` ≥ sum of member sizes. Reorder members from largest to smallest type to minimize padding.

**Q5. How do you pass a struct to a function — by value or by pointer?**
> By value: the entire struct is copied onto the stack — safe but expensive for large structs. By pointer: only the pointer (8 bytes) is copied — efficient, but allows modification. Best practice: use `const Struct *` for read-only, `Struct *` when modification is needed. Pass by value only for very small structs.

**Q6. What is `offsetof` and when is it used?**
> `offsetof(type, member)` macro from `<stddef.h>` gives the byte offset of a member within a struct. Used in serialization, network protocols, and the container_of trick in Linux kernel to get the enclosing struct from a member pointer.

## 🔴 Advanced

**Q7. What are bit fields in structures? Give a use case.**
> Bit fields pack multiple small integer values into a single word, saving memory:
```c
struct Pixel { unsigned r:5; unsigned g:6; unsigned b:5; }; /* 16 bits */
```
> Used in: embedded device registers (reading hardware flags), network packet headers (IP flags, fragment offset), OS structures (file permission bits). Caveat: bit field layout is implementation-defined — not portable across compilers/platforms.

**Q8. What is a flexible array member (C99)?**
```c
typedef struct {
    int count;
    int data[];    /* flexible array — zero-length, must be last member */
} DynArray;
/* Allocate: DynArray *a = malloc(sizeof(DynArray) + n * sizeof(int)); */
/* a->data[0..n-1] are valid */
```
> Allows structs with variable-length trailing data in one allocation — used in protocol buffers, OS kernel structures.

**Q9. Explain the "container_of" pattern used in the Linux kernel.**
```c
#define container_of(ptr, type, member) \
    ((type*)((char*)(ptr) - offsetof(type, member)))
```
> Given a pointer to a struct member, recover the pointer to the enclosing struct. Used in Linux kernel to implement generic linked lists: the list node is embedded IN the structure, and container_of retrieves the outer struct from the node pointer.

---

*— Pavan Shetty H S*
