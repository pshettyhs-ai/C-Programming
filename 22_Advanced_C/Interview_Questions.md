# Interview Questions — Advanced C

## 🟢 Basic
**Q1. What is the purpose of `volatile` in C?**
> `volatile` tells the compiler that the variable's value can change at any time without the program explicitly changing it — e.g., a hardware register, a variable modified by an interrupt handler, or a signal handler. Without `volatile`, the compiler might cache the variable in a register and never re-read memory, missing updates. With `volatile`, every read/write goes to actual memory.

**Q2. What is `restrict` in C99?**
> `restrict` is a qualifier on pointers that promises to the compiler that the memory it points to will only be accessed through that pointer within the current scope — no aliasing. This allows the compiler to make optimizations (reordering loads/stores, vectorization) it couldn't make if the pointers might overlap. Used in `memcpy` declarations.

## 🟡 Intermediate
**Q3. What is a flexible array member?**
> A zero-length array as the LAST member of a struct (C99). Allows you to allocate a struct followed by a variable-length array in one `malloc` call: `malloc(sizeof(Struct) + n * sizeof(Type))`. `sizeof(Struct)` does NOT include the flexible member. Used in network packets, OS kernel data structures, and binary file formats.

**Q4. What is `setjmp`/`longjmp` and when should you use it?**
> `setjmp(env)` saves the program state (registers, stack pointer) into `env` and returns 0. `longjmp(env, val)` restores that state, making `setjmp` return `val` again. It's a non-local goto — can jump out of deeply nested calls. Use sparingly: for error recovery in parsers/interpreters, as a primitive exception mechanism. Caveats: local variables not declared `volatile` may have indeterminate values after `longjmp`.

## 🔴 Advanced
**Q5. What is `_Generic` in C11?**
> `_Generic` is a compile-time type selection expression. Based on the type of the controlling expression, it selects one of several expressions — similar to `switch` but for types. Enables type-generic macros without `_Bool`/runtime overhead. Used to implement `<tgmath.h>` type-generic math functions.

**Q6. What are C11 atomics and when do you need them?**
> `<stdatomic.h>` provides atomic types and operations that are guaranteed to be indivisible on multi-core CPUs. Without atomics, reading/writing shared variables across threads can see torn values (partial writes). Atomics ensure visibility and ordering without a full mutex. Use for simple counters, flags, and lock-free data structures. For complex invariants, still use mutexes.

---

*— Pavan Shetty H S*
