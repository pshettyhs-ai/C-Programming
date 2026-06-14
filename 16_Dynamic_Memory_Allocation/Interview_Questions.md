# Interview Questions — Dynamic Memory Allocation

## 🟢 Basic
**Q1. What is the difference between malloc and calloc?**
> `malloc(n)` allocates n bytes of uninitialized memory — content is garbage. `calloc(count, size)` allocates `count × size` bytes and zero-initializes all bytes. `calloc` is useful when you need a zeroed array. `malloc` is slightly faster since it skips zeroing.

**Q2. What is a memory leak?**
> A memory leak occurs when dynamically allocated memory is never freed — the heap grows and is never reclaimed. Over time, the program consumes more and more RAM. In long-running programs (servers, daemons), leaks cause eventual OOM crashes. Detect with Valgrind or AddressSanitizer.

**Q3. What should you do immediately after calling malloc?**
> Check for NULL: `if (ptr == NULL) { /* handle error */ }`. malloc returns NULL when the OS cannot allocate requested memory. Dereferencing NULL is a segfault. After `free()`, set the pointer to NULL to prevent use-after-free bugs.

## 🟡 Intermediate
**Q4. Why should you use `int *p = malloc(sizeof(*p))` instead of `malloc(sizeof(int))`?**
> `sizeof(*p)` automatically uses the correct type even if `p`'s type changes later. If you change `int *p` to `long *p`, `sizeof(*p)` correctly becomes `sizeof(long)` without any other changes. Reduces maintenance bugs.

**Q5. What is the correct way to use realloc?**
```c
/* WRONG — if realloc fails, ptr becomes NULL and original memory is lost */
ptr = realloc(ptr, new_size);

/* CORRECT */
void *tmp = realloc(ptr, new_size);
if (tmp == NULL) {
    free(ptr);   /* clean up original */
    return NULL; /* report error */
}
ptr = tmp;
```

**Q6. What is a dangling pointer in the context of dynamic memory?**
> After `free(ptr)`, the pointer still holds the old address — but that memory may have been reallocated for something else. Accessing `*ptr` after `free(ptr)` reads/writes arbitrary memory (use-after-free). Fix: always set `ptr = NULL` after `free(ptr)`.

## 🔴 Advanced
**Q7. How does malloc work internally?**
> malloc typically gets large memory regions from the OS via `sbrk()` or `mmap()`, then subdivides them using free lists. Small allocations use a slab allocator or buddy system. When you `free()`, the block is returned to the free list for reuse. Different implementations (glibc ptmalloc, jemalloc, tcmalloc) use different strategies for performance.

**Q8. What is heap fragmentation?**
> After many allocations and frees of different sizes, the heap may have many small free gaps between live allocations. Even if total free memory is sufficient, there may be no single contiguous free block large enough for a new allocation. Solutions: pool allocators, arena allocators, custom memory managers.

**Q9. What is an arena (or pool) allocator and when would you use it?**
> An arena allocator pre-allocates a large block and hands out sub-blocks from it with no per-allocation overhead. All memory is freed at once by freeing the arena. Use when: many small objects of known lifetimes (parsing, game frames), performance-critical code where `malloc` overhead matters, or fragmentation must be avoided.

---

*— Pavan Shetty H S*
