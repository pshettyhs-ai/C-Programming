# Practice Problems — Introduction to C

> **Author: Pavan Shetty H S**
>
> These are problems I solved while learning this chapter. I have arranged them from easy to hard. Try each one before reading the hint.

---

## 🟢 Easy Problems

**P1. Your First Program**
Write a program that prints your name, your college, and "I am learning C!" on three separate lines.

*What you practice:* printf, \n escape sequence.

---

**P2. Personal Info Card**
Display a formatted card in the terminal using printf:
```
================================
  Name   : Pavan Shetty H S
  Course : B.Tech CSE
  Year   : 2nd Year
================================
```
*What you practice:* Multi-line printf, text formatting.

---

**P3. Type Size Table**
Print a table showing the size of every fundamental data type using `sizeof`. Format it nicely with column alignment.

*Hint:* Use `%zu` to print `sizeof` values. Use `%-20s` to left-align strings.

---

**P4. ASCII Exploration**
Print the characters and ASCII values for:
- All uppercase letters A to Z
- All digits 0 to 9
- Some special characters: ! @ # $ %

*Hint:* You can assign a char and print it with both `%c` and `%d`.

---

**P5. Compilation Stages**
Write a program that uses `__FILE__`, `__DATE__`, `__TIME__`, and `__func__` to print information about when and where the code was compiled.

---

## 🟡 Medium Problems

**P6. Simple Arithmetic Report**
Hardcode two numbers (try 19 and 4). Print a full arithmetic report: addition, subtraction, multiplication, integer division, modulo, and float division. Format the output in a table.

---

**P7. Temperature Conversion Table**
Print a conversion table showing Celsius to Fahrenheit for 0°C to 100°C in steps of 10. Use the formula: `F = (C * 9/5) + 32`.

```
Celsius    Fahrenheit
-------    ----------
  0          32.0
 10          50.0
 20          68.0
...
```

---

**P8. Architecture Detection**
Check if the system is 32-bit or 64-bit using `sizeof(void *)`. Print an appropriate message.

*Hint:* If `sizeof(void *)` is 8, the system is 64-bit.

---

**P9. Macro Calculator**
Define macros `SQUARE(x)`, `CUBE(x)`, `MAX(a,b)`, and `ABS(x)`. Use them in a program and print the results for several test values.

*Important:* Always put parentheses around every parameter and the whole expression in a macro.

---

**P10. Platform Reporter**
Use `#ifdef` to write a program that detects the operating system at compile time and prints "Running on Linux", "Running on Windows", or "Running on macOS".

*Hint:* Check for `__linux__`, `_WIN32`, and `__APPLE__`.

---

## 🔴 Hard Problems

**P11. Simplified printf**
Write your own `my_print_int(int n)` function that prints an integer to the terminal using only `putchar()` — no printf allowed inside it. Handle negative numbers too.

*Hint:* Extract digits using `% 10`, reverse them using a small array.

---

**P12. Standard Detector**
Write a program that uses `__STDC_VERSION__` to detect which C standard it was compiled under (C89, C99, C11, C17, C23) and prints the result.

*Hint:* Use `#if __STDC_VERSION__ >= 201710L` style checks.

---

**P13. Predict the Output**
Before compiling, predict the output of each expression:
```c
printf("%zu\n", sizeof(int) + sizeof(char));
printf("%zu\n", sizeof("Hello"));
printf("%zu\n", sizeof('A'));
int arr[5];
printf("%zu\n", sizeof(arr));
printf("%zu\n", sizeof(arr) / sizeof(arr[0]));
```
Then compile and verify your predictions.

---

**P14. Token Counter**
Write a program that counts how many of these appear in a given string: keywords (hardcode a few to check), operators, and identifiers. Use string comparison functions.

---

## 💡 Challenge Problem

**P15. Compile-time Static Assert**
In C11, you can use `_Static_assert` to cause a compile error if a condition is false. Write a program that uses it to assert that `sizeof(int) == 4`. Then intentionally break the condition and observe the compiler error message.

```c
_Static_assert(sizeof(int) == 4, "This code needs 4-byte integers");
```

Try to implement the same thing for C89 using the negative-array-size trick:
```c
typedef char static_assert_int_is_4[(sizeof(int) == 4) ? 1 : -1];
```

---

## ✅ Self-Check Before Moving On

Make sure you can do these without looking at notes:

- [ ] Write and compile a C program from scratch
- [ ] Use printf with %d, %f, %c, %s, %p, %zu
- [ ] Explain the 4 compilation stages in order
- [ ] Draw the 5 memory segments of a running C program
- [ ] Use predefined macros like `__FILE__` and `__LINE__`
- [ ] Explain why `sizeof` is an operator, not a function

---

*— Pavan Shetty H S*
