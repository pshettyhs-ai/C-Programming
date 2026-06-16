# Top 100 C Interview Questions and Answers

> **Author: Pavan Shetty H S**
>
> I collected these from placement drives, seniors, and online resources.
> Every answer is written in my own words — the way I would explain it in an interview room.

---

## Section 1 — Fundamentals (Q1–Q20)

---

**Q1. What is C? Who created it and when?**

C is a general-purpose, compiled, procedural programming language created by Dennis Ritchie at Bell Labs in 1972. It was built to rewrite the Unix operating system, which was previously written in assembly. C is special because it gives you low-level control over memory while still providing the structure of a high-level language — functions, loops, conditionals, and modularity.

---

**Q2. Why is C still relevant today?**

Because the things that made C valuable in 1972 are still valuable now. Operating system kernels (Linux, Windows, macOS) are written in C. Embedded systems — everything from your microwave to car ECUs — run C. Database engines like MySQL and SQLite are C. The Python interpreter is C. Every language that claims to be fast is either written in C or competes against it. If you understand C deeply, you understand how computers actually work.

---

**Q3. What are the four stages of C compilation?**

1. **Preprocessing** — expands `#include` and `#define`, removes comments, handles `#ifdef`
2. **Compilation** — checks syntax, converts C code to assembly language
3. **Assembling** — converts assembly to binary machine code (`.o` object file)
4. **Linking** — combines object files with libraries to produce the final executable

Each stage can be stopped manually:
```bash
gcc -E program.c    # stop after preprocessing (.i file)
gcc -S program.c    # stop after compilation  (.s file)
gcc -c program.c    # stop after assembling   (.o file)
gcc    program.c    # full pipeline to executable
```

---

**Q4. What is the difference between a declaration and a definition?**

A **declaration** tells the compiler that something exists — its name and type. No memory is allocated.
A **definition** creates the thing — allocates memory for variables, or provides the body for functions.

```c
extern int count;          /* declaration — no memory here */
int count = 0;             /* definition — memory allocated */

int square(int n);         /* declaration (prototype) */
int square(int n) { return n*n; }   /* definition */
```

You can declare something many times. You can define it only once.

---

**Q5. What does `return 0` in main() mean?**

It signals to the operating system that the program finished successfully. By convention, `0` means success and any non-zero value means something went wrong. Shell scripts use this value: `if [ $? -eq 0 ]; then echo "Success"; fi`. Using `EXIT_SUCCESS` and `EXIT_FAILURE` from `<stdlib.h>` is more readable and portable.

---

**Q6. What is the difference between `int main()` and `int main(void)` in C?**

In C (not C++), `int main()` means the parameters are unspecified — the compiler will accept calls with any number of arguments. `int main(void)` explicitly states no parameters are accepted. The difference matters for type checking. In modern C, always write `main(void)` unless you need command-line arguments, in which case write `int main(int argc, char *argv[])`.

---

**Q7. What are C keywords? Name any ten.**

Keywords are reserved words with special meaning — you cannot use them as variable names. C89 has 32 keywords:

`int  float  double  char  void  if  else  for  while  do  switch  case  break  continue  return  struct  union  enum  typedef  static  extern  auto  register  const  volatile  sizeof  unsigned  signed  long  short  goto  default`

---

**Q8. What is an identifier in C? What are the naming rules?**

An identifier is any name you give to a variable, function, macro, or type. Rules:
- Must start with a letter (a–z, A–Z) or underscore `_`
- Can contain letters, digits, and underscores
- Cannot be a keyword
- Case-sensitive: `count` and `Count` are different
- No spaces or special characters

---

**Q9. What is `sizeof`? Is it a function or an operator?**

`sizeof` is a **compile-time operator** — not a function. No function call happens at runtime. It returns the size in bytes of a type or variable as a `size_t` value.

```c
sizeof(int)          /* 4 on most systems */
sizeof(double)       /* 8 */
sizeof("Hello")      /* 6 — includes the null terminator */
int arr[10];
sizeof(arr)          /* 40 — total array size */
sizeof(arr[0])       /* 4 — size of one element */
sizeof(arr)/sizeof(arr[0])   /* 10 — number of elements */
```

---

**Q10. What is the difference between `=`, `==`, and `===` in C?**

There is no `===` in C. `=` is the assignment operator — it stores a value. `==` is the equality comparison operator — it returns 0 or 1.

The classic bug: `if (x = 5)` assigns 5 to x and the condition is always true. `if (x == 5)` tests whether x equals 5. Some programmers write `if (5 == x)` as a safety habit — writing `if (5 = x)` by accident gives a compile error.

---

**Q11. What is the difference between `++i` and `i++`?**

Both increment `i` by 1. The difference is what value the expression itself evaluates to:
- `++i` (pre-increment): increments first, returns the new value
- `i++` (post-increment): returns the current value, then increments

```c
int i = 5;
int a = ++i;   /* a = 6, i = 6 */
int b = i++;   /* b = 6, i = 7 */
```

As standalone statements (`i++;` or `++i;`) they are identical.

---

**Q12. What is operator precedence? Give an example where it matters.**

Precedence determines which operator is applied first when an expression has multiple operators without explicit parentheses. `*` and `/` have higher precedence than `+` and `-`.

```c
int result = 2 + 3 * 4;    /* 14, not 20 — * applied first */
int clear  = (2 + 3) * 4;  /* 20 — parentheses override */
```

My rule: when in doubt, use parentheses. Clarity beats cleverness.

---

**Q13. Explain short-circuit evaluation.**

In logical `&&` and `||`, the right operand is not evaluated if the left operand already determines the result.

- `false && expr` — expr is never evaluated (result is always false)
- `true  || expr` — expr is never evaluated (result is always true)

This is used for safe null-pointer checks:
```c
if (ptr != NULL && ptr->value > 0) { }
/* ptr->value is only accessed if ptr is not NULL */
```

---

**Q14. What is the modulo operator? Does it work on floats?**

`%` returns the remainder of integer division: `17 % 5 = 2`. It only works on integer types — applying it to `float` or `double` is a compile error. For floating-point remainder, use `fmod()` from `<math.h>`.

---

**Q15. What is the ternary operator? Write an example.**

`condition ? value_if_true : value_if_false` — a compact inline conditional:

```c
int abs_val = (n < 0) ? -n : n;
char *result = (score >= 50) ? "Pass" : "Fail";
```

Use it when the logic is simple and fits on one readable line. For complex conditions, a regular if-else is clearer.

---

**Q16. What is a variable's scope?**

Scope is the region of code where a variable is visible and can be used. In C:
- **Block scope**: variables declared inside `{ }` — visible only within that block
- **File scope**: variables declared outside all functions — visible throughout the file
- **Function prototype scope**: parameter names in a prototype — visible only in the prototype

---

**Q17. What is the difference between local and global variables?**

| Feature | Local | Global |
|---------|-------|--------|
| Declared | Inside a function or block | Outside all functions |
| Stored | Stack | Data segment (initialised) or BSS (uninitialised) |
| Default value | Garbage (undefined) | Zero |
| Scope | Block it is declared in | Entire file (and other files with `extern`) |
| Lifetime | Until block ends | Entire program |

---

**Q18. What are escape sequences? List five.**

Sequences starting with `\` that represent special characters:

| Sequence | Meaning |
|----------|---------|
| `\n` | Newline |
| `\t` | Horizontal tab |
| `\\` | Backslash |
| `\"` | Double quote |
| `\0` | Null character (string terminator) |

---

**Q19. What is the purpose of `#include`?**

`#include` tells the preprocessor to paste the contents of a header file at that point. `#include <stdio.h>` pastes the standard I/O header (contains declarations of `printf`, `scanf`, etc.). Without it, the compiler does not know these functions exist. The angle-bracket form searches system paths; the quoted form searches the current directory first.

---

**Q20. What is `void` in C?**

`void` serves three purposes:
1. **Return type**: `void func(void)` — function returns nothing
2. **Parameter list**: `int main(void)` — function takes no parameters
3. **Generic pointer**: `void *ptr` — can hold any pointer type, must cast before dereferencing

---

## Section 2 — Arrays and Strings (Q21–Q35)

---

**Q21. What is an array? How is it stored in memory?**

An array stores multiple values of the same type in contiguous (adjacent) memory locations. Each element is at address `base + i × sizeof(element_type)`. This makes random access O(1) — you compute the address directly.

---

**Q22. What is the difference between `int arr[5] = {0}` and `int arr[5]`?**

`int arr[5] = {0}` explicitly initialises all five elements to 0. `int arr[5]` as a local variable leaves all elements uninitialised — they contain whatever garbage was in that memory. Global and static arrays are always zero-initialised automatically.

---

**Q23. What happens when you access an array out of bounds in C?**

Undefined behaviour. C does not perform bounds checking. The program may read garbage, write to unrelated memory, crash immediately, or appear to work — all are possible. Use AddressSanitizer (`gcc -fsanitize=address`) or Valgrind to detect out-of-bounds access.

---

**Q24. How do you find the number of elements in an array without a separate size variable?**

```c
int arr[] = {10, 20, 30, 40, 50};
int n = sizeof(arr) / sizeof(arr[0]);   /* 5 */
```

This only works where the array is declared. Inside a function that receives the array as a parameter, the array has decayed to a pointer and `sizeof` gives the pointer size, not the array size.

---

**Q25. What is array decay?**

When an array name is used in an expression (other than with `sizeof` or `&`), it automatically converts to a pointer to its first element. This is called decay. The size information is lost after decay — which is why you must pass the size separately to functions.

---

**Q26. How are 2D arrays stored in memory?**

In row-major order — all elements of row 0 first, then row 1, and so on. `matrix[i][j]` is at offset `(i × cols + j) × sizeof(type)` from the start. Iterating row-by-row is cache-friendly (sequential memory access). Column-by-column iteration causes frequent cache misses on large matrices.

---

**Q27. What is the difference between `char arr[] = "Hello"` and `char *ptr = "Hello"`?**

`char arr[]` creates a modifiable copy of the string on the stack — you can change `arr[0]`. `char *ptr` points to a string literal in the read-only data segment — attempting to modify `ptr[0]` is undefined behaviour (usually a segfault). Always use `const char *ptr = "Hello"` for string literals.

---

**Q28. Why should you never use `gets()`?**

`gets()` reads from stdin with no limit on length. If the user enters more characters than the buffer can hold, it writes past the buffer end — a classic buffer overflow vulnerability. It was deprecated in C99 and removed in C11. Always use `fgets(buf, sizeof(buf), stdin)` instead.

---

**Q29. What does `strcmp` return and how do you use it correctly?**

`strcmp(s1, s2)` returns 0 if equal, a negative value if s1 < s2 lexicographically, and a positive value if s1 > s2. Never use `==` to compare strings — that compares pointer addresses, not contents.

```c
if (strcmp(name, "Pavan") == 0) { printf("Match!\n"); }
```

---

**Q30. What is `strlen` vs `sizeof` for strings?**

`strlen(s)` returns the number of characters before the null terminator — it is a runtime function that walks the string. `sizeof("Hello")` returns 6 at compile time — includes the null terminator. `sizeof` on a char array variable gives the total allocated size.

---

**Q31. What is `strtok` and what is its main limitation?**

`strtok` tokenises a string by replacing delimiter characters with null bytes and returning pointers to each token. Its limitation: it modifies the original string and uses internal static state — making it not thread-safe. Use `strtok_r` for thread-safe tokenisation.

---

**Q32. How do you safely copy a string?**

```c
/* Best: snprintf guarantees null-termination and respects buffer size */
snprintf(dst, sizeof(dst), "%s", src);

/* Or: strncpy but you must null-terminate yourself */
strncpy(dst, src, sizeof(dst) - 1);
dst[sizeof(dst) - 1] = '\0';
```

Never use `strcpy` on user input.

---

**Q33. What is a null-terminated string?**

A sequence of characters followed by a null character `'\0'` (ASCII 0). All standard string functions use this convention to find where the string ends. Without the null terminator, functions like `printf("%s")` and `strlen` would read past the end of the array.

---

**Q34. How would you reverse a string in C?**

```c
void reverse(char *s) {
    int lo = 0, hi = strlen(s) - 1;
    while (lo < hi) {
        char t = s[lo]; s[lo] = s[hi]; s[hi] = t;
        lo++; hi--;
    }
}
/* Time: O(n), Space: O(1) */
```

---

**Q35. How do you check if a string is a palindrome?**

```c
int is_palindrome(const char *s) {
    int lo = 0, hi = strlen(s) - 1;
    while (lo < hi) {
        if (s[lo] != s[hi]) return 0;
        lo++; hi--;
    }
    return 1;
}
```

---

## Section 3 — Pointers (Q36–Q55)

---

**Q36. What is a pointer?**

A pointer is a variable that stores a memory address. It does not hold a value directly — it holds the location of a value. You access the value through the pointer using the dereference operator `*`.

---

**Q37. What is the difference between `*` in a declaration and `*` in an expression?**

In `int *p`, the `*` is part of the type — it declares p as a pointer to int.
In `*p = 5`, the `*` is the dereference operator — it accesses the value at the address stored in p.

Same character, completely different meaning depending on context.

---

**Q38. What is a NULL pointer? Why is it useful?**

NULL is a macro defined as `(void*)0` — a pointer that does not point to any valid memory location. It is useful as a "not set" or "not found" indicator. Always check `if (ptr != NULL)` before dereferencing, and always set pointers to NULL after freeing them.

---

**Q39. What is a wild pointer?**

An uninitialised pointer — it was declared but never assigned an address. It contains whatever garbage was in that memory. Dereferencing it writes to a random location. Always initialise pointers: `int *p = NULL;` or `int *p = &variable;`.

---

**Q40. What is a dangling pointer?**

A pointer that once pointed to valid memory but no longer does — because the memory was freed or the variable went out of scope. Accessing a dangling pointer is undefined behaviour.

Prevention: set to NULL after `free()`, never return the address of a local variable.

---

**Q41. What is pointer arithmetic?**

Adding or subtracting an integer from a pointer moves it by that many elements, not bytes. `p + 1` for `int *p` moves 4 bytes forward. This is why array traversal with pointers works: `*(arr + i)` is equivalent to `arr[i]`.

---

**Q42. Explain `const int *p` vs `int * const p` vs `const int * const p`.**

```c
const int *p;          /* value locked: *p can't change, p can be reassigned */
int * const p;         /* pointer locked: p can't be reassigned, *p can change */
const int * const p;   /* both locked: neither *p nor p can change */
```

Mnemonic: read right-to-left. `const int *p` — p is a pointer to (const int). `int * const p` — p is a (const pointer) to int.

---

**Q43. What is the size of any pointer on a 64-bit system?**

8 bytes, regardless of what type it points to. `sizeof(int*)`, `sizeof(char*)`, `sizeof(void*)` are all 8 on a 64-bit system, and all 4 on a 32-bit system.

---

**Q44. What is a double pointer? Give a use case.**

A pointer to a pointer (`int **pp`). Main use cases:
1. Modify a pointer variable inside a function: `void alloc(int **pp)` — pass `&ptr`
2. Dynamic 2D arrays: `int **matrix = malloc(rows * sizeof(int*))`
3. `char **argv` — array of strings for command-line arguments

---

**Q45. What is a void pointer? When would you use it?**

`void *` is a generic pointer — it can hold any pointer type without a cast. Cannot be dereferenced directly (must cast first). Used for generic functions: `malloc` returns `void *`, `qsort` accepts `void *` array and comparator.

---

**Q46. What is the strict aliasing rule?**

The compiler assumes pointers of different types never point to the same memory. This allows aggressive optimisation. Accessing memory through a pointer of the wrong type violates this rule and causes undefined behaviour. Use `union` or `memcpy` for type punning — never cast pointer types.

---

**Q47. Explain the output of this code:**
```c
int arr[] = {10, 20, 30, 40, 50};
int *p = arr + 2;
printf("%d %d\n", *(p-1), *(p+2));
```

`p` points to `arr[2]` (value 30). `*(p-1)` is `arr[1]` = 20. `*(p+2)` is `arr[4]` = 50. Output: `20 50`.

---

**Q48. What is the difference between passing an array and a pointer to a function?**

Functionally identical in most cases — the array decays to a pointer. The difference is that `sizeof` inside the function gives the pointer size (not array size) for both forms. To convey that you expect an array of known size, some style guides use the `arr[]` form for clarity.

---

**Q49. What is a function pointer? Write the syntax.**

```c
/* Declare: return_type (*name)(param_types) */
int (*fp)(int, int);

int add(int a, int b) { return a + b; }
fp = add;
printf("%d\n", fp(3, 4));   /* 7 */

/* typedef makes it readable */
typedef int (*BinaryOp)(int, int);
BinaryOp ops[] = { add, sub, mul };
```

---

**Q50. What is a memory leak? How do you detect it?**

Allocated heap memory that is never freed. It accumulates over the program's lifetime and can exhaust available memory. Detect with:
- `valgrind --leak-check=full ./program`
- `gcc -fsanitize=address ./program` (AddressSanitizer)

---

## Section 4 — Structures, Unions, Files, Advanced (Q51–Q75)

---

**Q51. What is a structure? How does it differ from an array?**

A structure groups variables of **different types** under one name. An array holds many variables of the **same type**. `struct Student { char name[50]; int roll; float gpa; }` — three different types in one unit.

---

**Q52. What is struct padding and why does it happen?**

The compiler inserts padding bytes between struct members to align each member on its natural boundary (an `int` at a 4-byte boundary, a `double` at 8-byte). This makes memory access faster on most CPUs. As a result, `sizeof(struct)` can be larger than the sum of its members.

```c
struct S { char a; int b; };    /* sizeof = 8, not 5 */
/* 1 byte 'a' + 3 bytes padding + 4 bytes 'b' */
```

---

**Q53. How do `.` and `->` differ for struct access?**

`.` accesses a member through a struct variable directly. `->` accesses a member through a pointer to a struct. `p->member` is shorthand for `(*p).member`.

---

**Q54. What is a union? How is it different from a struct?**

In a struct, every member has its own memory location and all exist simultaneously. In a union, all members share the same memory — only one is valid at a time. `sizeof(union)` = size of its largest member. Useful for variant types and type punning.

---

**Q55. What is a tagged union? Why is it safer?**

A tagged union pairs a union with an enum that records which member is currently active:
```c
typedef struct {
    enum { T_INT, T_FLOAT } type;
    union { int i; float f; } val;
} Variant;
```
Always check the tag before accessing a member. Without the tag, you might read the wrong type.

---

**Q56. What are the four storage classes in C?**

1. `auto` — default for local variables, stack, uninitialized
2. `register` — hint to use CPU register (compilers ignore this now)
3. `static` — persistent across calls (local) or file-private (global)
4. `extern` — declares a variable defined in another translation unit

---

**Q57. What is the difference between `static` on a local variable vs a global?**

`static` local: variable persists between function calls instead of being recreated on the stack. Initialised once only.

`static` global: variable has internal linkage — not visible outside the file. Used to make implementation details private.

---

**Q58. What is the difference between `malloc`, `calloc`, and `realloc`?**

- `malloc(n)` — allocates n bytes, content is uninitialised garbage
- `calloc(count, size)` — allocates count×size bytes, all zeroed
- `realloc(ptr, new_size)` — resizes an existing allocation; preserves existing content

Always check the return value for NULL before using the result.

---

**Q59. Why should you never do `ptr = realloc(ptr, size)`?**

If `realloc` fails, it returns NULL and leaves the original allocation intact. But assigning NULL to `ptr` loses your only reference to the original memory — a memory leak. Always use a temporary: `tmp = realloc(ptr, size); if (tmp) ptr = tmp;`.

---

**Q60. What is the difference between text mode and binary mode in file I/O?**

Text mode (`"r"`, `"w"`) performs newline translation — on Windows `\n` becomes `\r\n` on write and vice-versa on read. Binary mode (`"rb"`, `"wb"`) writes bytes exactly as they are, with no translation. For struct data, always use binary mode. On Linux the difference is invisible — but using `"rb"`/`"wb"` makes code portable.

---

**Q61. What does `fseek(fp, 0, SEEK_END)` followed by `ftell(fp)` give you?**

The file size in bytes. `fseek` to the end positions the file pointer at the last byte. `ftell` returns the current byte offset from the beginning — which equals the file size.

---

**Q62. What is `volatile` and when do you use it?**

`volatile` tells the compiler that a variable may change outside normal program flow — hardware register, signal handler, or another thread. The compiler must read/write actual memory every time instead of caching in a register. Used for: memory-mapped hardware registers, variables modified by interrupt handlers.

---

**Q63. What is `restrict`?**

A C99 qualifier that promises the pointer is the only way to access the data it points to in the current scope. Lets the compiler assume no aliasing and apply vectorisation and reordering optimisations it otherwise cannot. Used in `memcpy`'s declaration.

---

**Q64. What is undefined behaviour in C? Give three examples.**

Behaviour that the C standard explicitly does not define — the compiler may produce any result.

Examples:
1. Reading an uninitialised local variable
2. Signed integer overflow (`INT_MAX + 1`)
3. Dereferencing a NULL pointer
4. Out-of-bounds array access
5. Modifying a string literal

UB is dangerous because it can look like it works in debug builds and silently fail in optimised builds.

---

**Q65. What is the One Definition Rule?**

Every variable and function must be **defined** exactly once across all translation units. It can be **declared** many times with `extern`. Defining `int x = 5;` in two `.c` files (without `static`) causes a linker error: "multiple definition of x".

---

## Section 5 — Data Structures and Algorithms (Q66–Q85)

---

**Q66. What is the time complexity of binary search? Why?**

O(log n). Each comparison eliminates half the remaining elements: n → n/2 → n/4 → … → 1. That is log₂(n) steps. For n = 1,000,000: at most 20 comparisons.

---

**Q67. When can you NOT use binary search?**

When the array is not sorted. Binary search requires sorted data. If you need to search unsorted data, use linear search O(n) or sort first O(n log n) then binary search.

---

**Q68. What is the difference between a stack and a queue?**

Stack is LIFO (Last In, First Out) — push and pop from the same end. Queue is FIFO (First In, First Out) — enqueue at one end, dequeue from the other. Stack is used for function calls, undo operations. Queue is used for scheduling, BFS traversal.

---

**Q69. What is a linked list? When is it better than an array?**

A sequence of nodes connected by pointers. Better than an array when: frequent insert/delete at the front is needed (O(1) vs O(n)), size is highly variable and unknown in advance, you do not need random access by index.

---

**Q70. What is a BST? What is its average time complexity for search?**

A Binary Search Tree is a binary tree where every node's left subtree contains only smaller values and right subtree only larger values. Average search time is O(log n). Worst case (perfectly skewed tree) is O(n).

---

**Q71. What is the difference between inorder, preorder, and postorder BST traversal?**

- Inorder (Left-Root-Right): produces sorted output for BST
- Preorder (Root-Left-Right): useful for copying a tree structure
- Postorder (Left-Right-Root): useful for deleting a tree (children freed before parent)

---

**Q72. What is a hash collision and how is it handled?**

A collision occurs when two keys hash to the same array index. Two resolution strategies:
1. **Separate chaining**: each slot holds a linked list of all entries that hash there
2. **Open addressing**: probe for the next available slot (linear, quadratic, or double-hash probing)

---

**Q73. What is the time complexity of merge sort? Is it stable?**

O(n log n) in all cases — best, average, and worst. It is **stable** (equal elements preserve their original order). It requires O(n) extra space for the merge step. Preferred when stability is required or for linked lists.

---

**Q74. What is the worst case of quicksort and how do you avoid it?**

O(n²) when the pivot is always the smallest or largest element — happens on already-sorted data with a naive first/last element pivot. Avoid with: median-of-three pivot selection (pick median of first, middle, last), random pivot selection, or Introsort (hybrid that switches to heapsort after deep recursion).

---

**Q75. What is the difference between linear search and binary search?**

| Feature | Linear | Binary |
|---------|--------|--------|
| Requirement | Any array | Sorted array only |
| Time | O(n) | O(log n) |
| Implementation | Trivial | Requires sorted data |
| Best for | Small/unsorted data | Large sorted data |

---

## Section 6 — Output Prediction (Q76–Q100)

---

**Q76. What is the output?**
```c
int a = 5, b = 10;
printf("%d\n", a++ + ++b);
```
`b` is pre-incremented to 11. `a++` uses 5 then increments. Output: **16**. After: a=6, b=11.

---

**Q77. What is the output?**
```c
printf("%d\n", sizeof('A'));
```
In C, character literals have type `int`, not `char`. So **4** (on most systems — `sizeof(int)`). Note: in C++ it would be 1.

---

**Q78. What is the output?**
```c
int arr[] = {1, 2, 3, 4, 5};
printf("%d\n", *(arr + 3));
```
`arr + 3` points to `arr[3]`. Dereferenced: **4**.

---

**Q79. What is the output?**
```c
int x = 10;
int *p = &x;
*p = 20;
printf("%d %d\n", x, *p);
```
Both `x` and `*p` refer to the same memory location. Output: **20 20**.

---

**Q80. What is the output?**
```c
union U { int i; char c[4]; };
union U u;
u.i = 0x41424344;
printf("%c\n", u.c[0]);
```
On a little-endian system (x86), the least significant byte (0x44 = 'D') is stored first. Output: **D**.

---

**Q81. What does this print?**
```c
int x = 5;
printf("%d %d %d\n", x, x++, ++x);
```
Undefined behaviour — the order of evaluation of function arguments is unspecified in C. **Do not write this.** Any output is technically correct because the behaviour is undefined.

---

**Q82. What is the output?**
```c
int arr[5] = {0};
printf("%d\n", arr[5]);
```
`arr[5]` is one past the end — out-of-bounds access. **Undefined behaviour**. May print 0, garbage, or crash.

---

**Q83. What is the output?**
```c
static int x = 5;
if (x > 0) {
    static int x = 10;
    printf("%d\n", x);
}
printf("%d\n", x);
```
The inner `x` (static, value 10) shadows the outer one inside the block. Output: **10** then **5**.

---

**Q84. What is the output?**
```c
int i = 0;
while (i++ < 3)
    printf("%d ", i);
```
`i++` uses current value for comparison then increments. Iterations: compare 0<3 (true, i→1, print 1), compare 1<3 (true, i→2, print 2), compare 2<3 (true, i→3, print 3), compare 3<3 (false, stop). Output: **1 2 3**.

---

**Q85–Q100.** Practice these with the Advanced.c programs in each chapter folder. Trace through the code by hand, predict the output, then run it and compare.

---

*— Pavan Shetty H S*
