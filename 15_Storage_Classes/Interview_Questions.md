# Interview Questions — Storage Classes

## 🟢 Basic
**Q1. What are the four storage classes in C?**
> `auto` (default local), `register` (CPU register hint), `static` (persistent/file-private), `extern` (cross-file sharing). They control where a variable is stored, its default initial value, its scope, and its lifetime.

**Q2. What is the difference between a static local variable and a global variable?**
> Both persist for the entire program lifetime and are zero-initialized by default. Difference: a static local is accessible only within its block (function/scope), while a global is accessible throughout the entire file (and other files if not static). Static local gives you persistence without polluting the global namespace.

**Q3. What does `extern` mean?**
> `extern` declares that a variable or function is defined in another translation unit (another `.c` file). It does NOT allocate memory — it just tells the compiler the variable exists elsewhere. Without `extern`, each file that defines a global with the same name creates a separate variable.

## 🟡 Intermediate
**Q4. Can you take the address of a register variable?**
> No. The `register` keyword is a hint to store the variable in a CPU register rather than memory. Since registers have no memory address, `&register_var` is a compile error. In practice, modern compilers ignore the `register` keyword and optimize register allocation themselves.

**Q5. What happens if you don't initialize a static variable?**
> Static variables (both global and static local) are automatically initialized to zero by the C runtime before `main()` starts. Pointers become `NULL`, integers become `0`, floats become `0.0`. This is guaranteed by the C standard — unlike auto local variables which have garbage values.

## 🔴 Advanced
**Q6. What is the difference between `static` applied to a function vs a variable?**
> For **variables**: `static` at file scope means internal linkage (not visible outside the translation unit). `static` at block scope means the variable persists across function calls. For **functions**: `static` always means internal linkage — the function is private to the `.c` file and cannot be called from other files. Helps avoid naming conflicts in large projects.

**Q7. Explain the One Definition Rule (ODR) in C.**
> Each variable or function can only be DEFINED once across all translation units. It can be DECLARED many times (via `extern`). Violating ODR (defining `int x = 5;` in two different `.c` files without `static`) causes a linker error: "multiple definition of x". Use `static` to give file scope, or `extern` to share one definition.

---

*— Pavan Shetty H S*
