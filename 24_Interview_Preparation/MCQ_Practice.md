# MCQ Practice — C Programming

> 100 Multiple Choice Questions. Answers at the bottom of each section.

---

## Section 1: Basics (Q1–Q25)

**Q1.** What is the correct syntax for the main function?
- (a) `void main()`
- (b) `int main(void)` ✅
- (c) `main(int argc)`
- (d) `int main;`

**Q2.** Which of these is NOT a keyword in C?
- (a) `register`
- (b) `volatile`
- (c) `then` ✅
- (d) `typedef`

**Q3.** What is the size of `int` on a 64-bit system (most common)?
- (a) 2 bytes
- (b) 4 bytes ✅
- (c) 8 bytes
- (d) Depends on compiler

**Q4.** Which format specifier is used to print a `double` in `scanf`?
- (a) `%f`
- (b) `%d`
- (c) `%lf` ✅
- (d) `%g`

**Q5.** What is the value of `7 % 3`?
- (a) 2 ✅
- (b) 1
- (c) 3
- (d) 0

**Q6.** Which storage class variable is initialized to zero automatically?
- (a) auto
- (b) register
- (c) static ✅
- (d) Both (a) and (b)

**Q7.** What does `&&` represent?
- (a) Bitwise AND
- (b) Logical AND ✅
- (c) Address operator
- (d) Double reference

**Q8.** Which escape sequence represents a newline?
- (a) `\r`
- (b) `\t`
- (c) `\n` ✅
- (d) `\0`

**Q9.** What is the output of `printf("%d", 10/3);`?
- (a) 3.33
- (b) 3 ✅
- (c) 4
- (d) 3.0

**Q10.** What is the correct way to declare a constant in C?
- (a) `constant int x = 5;`
- (b) `const int x = 5;` ✅
- (c) `final int x = 5;`
- (d) `define int x = 5;`

**Q11.** Which function reads a line of text from stdin safely?
- (a) `gets()`
- (b) `scanf("%s")`
- (c) `fgets()` ✅
- (d) `getline()`

**Q12.** What is the value of `sizeof(char)`?
- (a) 0
- (b) 1 ✅
- (c) 2
- (d) 4

**Q13.** Which operator has the highest precedence?
- (a) `+`
- (b) `*`
- (c) `++` (postfix) ✅
- (d) `=`

**Q14.** What does `#include <stdlib.h>` provide?
- (a) String functions
- (b) Math functions
- (c) `malloc`, `free`, `exit` ✅
- (d) I/O functions

**Q15.** A `do-while` loop executes its body:
- (a) Zero or more times
- (b) Exactly once
- (c) At least once ✅
- (d) Exactly twice

**Q16.** Which is a valid pointer declaration?
- (a) `int p*;`
- (b) `int *p;` ✅
- (c) `*int p;`
- (d) `pointer int p;`

**Q17.** What is `NULL` in C?
- (a) 0 casted to void pointer ✅
- (b) An empty string
- (c) Undefined macro
- (d) -1

**Q18.** What is the result of `(int)3.9`?
- (a) 4
- (b) 3 ✅
- (c) 3.9
- (d) Error

**Q19.** Which function computes the length of a string?
- (a) `length()`
- (b) `size()`
- (c) `strlen()` ✅
- (d) `count()`

**Q20.** What does `break` do inside a loop?
- (a) Restarts the loop
- (b) Exits the innermost loop ✅
- (c) Exits all loops
- (d) Goes to next iteration

**Q21.** What is `CHAR_BIT`?
- (a) Size of char
- (b) Number of bits in a char ✅
- (c) Maximum char value
- (d) Minimum char value

**Q22.** Which is the correct file for `printf`?
- (a) `<stdlib.h>`
- (b) `<string.h>`
- (c) `<stdio.h>` ✅
- (d) `<math.h>`

**Q23.** What does `continue` do in a loop?
- (a) Exits the loop
- (b) Skips current iteration and continues ✅
- (c) Terminates the program
- (d) Jumps to the next case

**Q24.** Which of these is a logical operator?
- (a) `&`
- (b) `|`
- (c) `!` ✅
- (d) `~`

**Q25.** What is the default value of a global int variable?
- (a) Garbage
- (b) -1
- (c) 1
- (d) 0 ✅

---

## Section 2: Pointers & Memory (Q26–Q50)

**Q26.** What does `*p` mean when `p` is a pointer?
- (a) Multiply by p
- (b) Address of p
- (c) Value at address p ✅
- (d) Pointer to p

**Q27.** What is `&x`?
- (a) Bitwise AND of x
- (b) Address of x ✅
- (c) Reference to x
- (d) Value of x

**Q28.** What is wrong with: `int *p; *p = 10;`?
- (a) Nothing
- (b) p is uninitialized (wild pointer) ✅
- (c) Cannot assign to pointer
- (d) Wrong type

**Q29.** What does `p++` do when p is `int *p`?
- (a) Increments p by 1 byte
- (b) Increments p by sizeof(int) bytes ✅
- (c) Increments *p
- (d) Error

**Q30.** What is `malloc` return type?
- (a) `int *`
- (b) `char *`
- (c) `void *` ✅
- (d) `void`

**Q31.** What happens if `malloc` fails?
- (a) Program crashes
- (b) Returns -1
- (c) Returns NULL ✅
- (d) Returns 0 pointer

**Q32.** What is a memory leak?
- (a) Data overwrite
- (b) Allocated memory never freed ✅
- (c) Buffer overflow
- (d) Stack overflow

**Q33.** What is `sizeof(int *)` on a 64-bit system?
- (a) 4
- (b) 8 ✅
- (c) 2
- (d) Depends on int type

**Q34.** What is a double pointer?
- (a) Pointer to float
- (b) Pointer to pointer ✅
- (c) Two pointers
- (d) 64-bit pointer

**Q35.** Which function frees heap memory?
- (a) `delete()`
- (b) `dealloc()`
- (c) `free()` ✅
- (d) `release()`

**Q36.** What does `calloc(5, sizeof(int))` do?
- (a) Allocates 5 bytes
- (b) Allocates 20 bytes, zeroed ✅
- (c) Allocates 5 ints, uninitialized
- (d) Allocates 5 pointers

**Q37.** What is `arr[i]` equivalent to?
- (a) `*(arr) + i`
- (b) `*(arr + i)` ✅
- (c) `arr + i`
- (d) `&arr[i]`

**Q38.** What is a void pointer used for?
- (a) Null pointer checks
- (b) Generic pointer, holds any type ✅
- (c) Function return type
- (d) Stack allocation

**Q39.** A function returns `int *`. What should the caller do?
- (a) Use directly
- (b) Free after use (if heap-allocated) ✅
- (c) Convert to int
- (d) Pass to printf

**Q40.** What is `realloc(ptr, 0)` equivalent to?
- (a) `malloc(0)`
- (b) `free(ptr)` ✅
- (c) `calloc(0, 0)`
- (d) No effect

---

## Section 3: Functions, Arrays, Strings (Q41–Q75)

**Q41.** What is the return type of `strlen()`?
- (a) `int`
- (b) `long`
- (c) `size_t` ✅
- (d) `unsigned int`

**Q42.** How do you pass an array to a function?
- (a) `func(arr[])`
- (b) `func(arr)` ✅ (decays to pointer)
- (c) `func(&arr[])`
- (d) `func(*arr)`

**Q43.** What is `strcmp("abc", "abc")` return value?
- (a) 1
- (b) -1
- (c) 0 ✅
- (d) True

**Q44.** What does `strtok` do to the original string?
- (a) Nothing
- (b) Makes a copy
- (c) Modifies it (inserts \0) ✅
- (d) Reverses it

**Q45.** What is the base case in recursion?
- (a) Recursive call
- (b) Termination condition ✅
- (c) Return statement
- (d) Loop condition

**Q46.** What is a function prototype?
- (a) Function definition
- (b) Forward declaration of function signature ✅
- (c) Function call
- (d) Inline function

**Q47.** How many values can a C function return directly?
- (a) Multiple
- (b) Two
- (c) One ✅
- (d) None

**Q48.** What is the correct way to declare a 2D array of 3 rows, 4 cols?
- (a) `int arr[4][3]`
- (b) `int arr[3][4]` ✅
- (c) `int arr[3,4]`
- (d) `int arr[12]`

**Q49.** `strcat(s1, s2)` appends `s2` to:
- (a) s2
- (b) a new string
- (c) s1 ✅
- (d) Both

**Q50.** What is the output: `printf("%d", strlen("C\0prog"));`?
- (a) 6
- (b) 1 ✅
- (c) 7
- (d) 2

---

## Section 4: Structs, File I/O, Advanced (Q51–Q100)

**Q51.** What is the size of `struct { char a; int b; }`?
- (a) 5 bytes
- (b) 8 bytes ✅ (1 + 3 padding + 4)
- (c) 4 bytes
- (d) 6 bytes

**Q52.** How do you access struct member through pointer `p`?
- (a) `p.member`
- (b) `(*p).member` or `p->member` ✅
- (c) `&p.member`
- (d) `p=>member`

**Q53.** What mode opens a file for both reading and writing (file must exist)?
- (a) `"w+"`
- (b) `"a"`
- (c) `"r+"` ✅
- (d) `"rw"`

**Q54.** What does `fseek(fp, 0, SEEK_END)` do?
- (a) Goes to beginning
- (b) Goes to end ✅
- (c) Goes to middle
- (d) Closes file

**Q55.** What is the advantage of binary file mode?
- (a) Human-readable
- (b) Faster, exact byte representation ✅
- (c) Platform-independent
- (d) Smaller files

**Q56.** What is `#pragma once` used for?
- (a) Optimization hint
- (b) Include guard ✅
- (c) Disable warnings
- (d) Set alignment

**Q57.** What is the output of `sizeof(union { int i; double d; })`?
- (a) 12
- (b) 4
- (c) 8 ✅
- (d) 16

**Q58.** What is `extern` used for?
- (a) External library
- (b) Declare variable defined in another file ✅
- (c) External function
- (d) Exit the program

**Q59.** Which sorting algorithm has O(n log n) worst-case time?
- (a) Quick Sort
- (b) Bubble Sort
- (c) Merge Sort ✅
- (d) Selection Sort

**Q60.** What does `&` do as a bitwise operator?
- (a) Logical AND
- (b) Bitwise AND — 1 only where both bits are 1 ✅
- (c) Address-of
- (d) Reference

**Q61.** What is `x ^ x` for any x?
- (a) x
- (b) 1
- (c) 0 ✅
- (d) -x

**Q62.** What is `1 << 4`?
- (a) 4
- (b) 8
- (c) 16 ✅
- (d) 2

**Q63.** What is a hash table's average time complexity for lookup?
- (a) O(n)
- (b) O(log n)
- (c) O(1) ✅
- (d) O(n²)

**Q64.** Which traversal of a BST gives sorted output?
- (a) Preorder
- (b) Postorder
- (c) Inorder ✅
- (d) Level-order

**Q65.** What is the time complexity of binary search?
- (a) O(n)
- (b) O(n²)
- (c) O(log n) ✅
- (d) O(1)

**Q66.** What does `volatile` prevent?
- (a) Type casting
- (b) Compiler optimizing away memory accesses ✅
- (c) Pointer arithmetic
- (d) Recursion

**Q67.** In a union, all members share:
- (a) Different memory addresses
- (b) The same memory address ✅
- (c) Consecutive addresses
- (d) Register storage

**Q68.** What is the purpose of `restrict`?
- (a) Prevent modification
- (b) Signal no pointer aliasing for optimization ✅
- (c) Limit scope
- (d) Disable warnings

**Q69.** What header is needed for `va_list`?
- (a) `<stdlib.h>`
- (b) `<string.h>`
- (c) `<stdarg.h>` ✅
- (d) `<varargs.h>`

**Q70.** What is tail recursion?
- (a) Recursion in a loop
- (b) Last operation is the recursive call ✅
- (c) Recursion without base case
- (d) Double recursion

**Q71.** What is `qsort`'s comparator expected to return?
- (a) bool
- (b) The larger element
- (c) Negative, zero, or positive ✅
- (d) Index of larger element

**Q72.** What is a flexible array member?
- (a) Dynamic-size array inside struct, declared last ✅
- (b) VLA
- (c) Pointer array
- (d) Array of pointers

**Q73.** What does `perror()` do?
- (a) Prints a custom error
- (b) Prints system error message for last errno ✅
- (c) Raises SIGSEGV
- (d) Calls exit()

**Q74.** In linked list, time complexity of insert at head?
- (a) O(n)
- (b) O(log n)
- (c) O(1) ✅
- (d) O(n²)

**Q75.** What is a sentinel value in a loop?
- (a) Initial value
- (b) Loop counter
- (c) Special value that signals termination ✅
- (d) Error code

**Q76–Q100:** Practice creating your own output-prediction questions from the `Programs/Advanced.c` files in each topic folder.

---

## ✅ Answer Key Summary
Q1:b Q2:c Q3:b Q4:c Q5:a Q6:c Q7:b Q8:c Q9:b Q10:b
Q11:c Q12:b Q13:c Q14:c Q15:c Q16:b Q17:a Q18:b Q19:c Q20:b
Q21:b Q22:c Q23:b Q24:c Q25:d Q26:c Q27:b Q28:b Q29:b Q30:c
Q31:c Q32:b Q33:b Q34:b Q35:c Q36:b Q37:b Q38:b Q39:b Q40:b
Q41:c Q42:b Q43:c Q44:c Q45:b Q46:b Q47:c Q48:b Q49:c Q50:b
Q51:b Q52:b Q53:c Q54:b Q55:b Q56:b Q57:c Q58:b Q59:c Q60:b
Q61:c Q62:c Q63:c Q64:c Q65:c Q66:b Q67:b Q68:b Q69:c Q70:b
Q71:c Q72:a Q73:b Q74:c Q75:c

---

*— Pavan Shetty H S*
