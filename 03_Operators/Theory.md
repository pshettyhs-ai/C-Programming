# Theory — Operators in C

> **Author: Pavan Shetty H S**

---

## 1. Operator Categories at a Glance

| Category | Operators |
|----------|-----------|
| Arithmetic | `+  -  *  /  %  ++  --` |
| Relational | `==  !=  >  <  >=  <=` |
| Logical | `&&  \|\|  !` |
| Bitwise | `&  \|  ^  ~  <<  >>` |
| Assignment | `=  +=  -=  *=  /=  %=  &=  \|=  ^=  <<=  >>=` |
| Ternary | `? :` |
| sizeof | `sizeof` |
| Pointer | `*  &  ->  .` |
| Cast | `(type)` |

---

## 2. Arithmetic Operators

The basics — but with a few traps:

```c
int a = 17, b = 5;

printf("%d\n", a + b);   /* 22 */
printf("%d\n", a - b);   /* 12 */
printf("%d\n", a * b);   /* 85 */
printf("%d\n", a / b);   /* 3  -- integer division TRUNCATES toward zero */
printf("%d\n", a % b);   /* 2  -- modulo gives the remainder */
```

**The division trap:** `17 / 5` gives `3`, not `3.4`. If you want the decimal answer, at least one operand must be a float:
```c
printf("%.2f\n", 17.0 / 5);    /* 3.40 -- correct */
printf("%.2f\n", (float)17/5); /* 3.40 -- explicit cast */
```

**Negative modulo (C99 onward):** the sign of the result follows the dividend:
```c
printf("%d\n", -7 % 2);   /* -1 in C99+ */
printf("%d\n", 7 % -2);   /*  1 in C99+ */
```

---

## 3. Increment and Decrement — The Pre vs Post Difference

```c
int x = 5;

/* Pre-increment: increment FIRST, then return the new value */
printf("%d\n", ++x);   /* prints 6, x is now 6 */

/* Post-increment: return the current value FIRST, then increment */
printf("%d\n", x++);   /* prints 6, x becomes 7 after */

printf("%d\n", x);     /* prints 7 */
```

**When does the difference matter?**
```c
int a = 5;
int b = a++;   /* b = 5, a = 6  -- b gets old value */
int c = ++a;   /* c = 7, a = 7  -- c gets new value */
```

**One rule I follow:** never put `++` or `--` inside a larger expression. Use it as a standalone statement on its own line. It prevents confusing bugs.

---

## 4. Relational Operators

These compare two values and return 0 (false) or 1 (true):

```c
int x = 10, y = 20;
printf("%d\n", x == y);   /* 0 -- not equal */
printf("%d\n", x != y);   /* 1 -- they differ */
printf("%d\n", x <  y);   /* 1 -- x is less */
printf("%d\n", x >  y);   /* 0 */
printf("%d\n", x <= 10);  /* 1 */
```

**Classic bug — `=` vs `==`:**
```c
if (x = 10)   /* WRONG: assigns 10 to x, condition is always true */
if (x == 10)  /* CORRECT: comparison */
```

One trick some people use: `if (10 == x)` — this way, if you accidentally write `if (10 = x)`, the compiler gives an error because you cannot assign to a literal.

---

## 5. Logical Operators and Short-Circuit Evaluation

```c
int a = 1, b = 0;
printf("%d\n", a && b);   /* 0 -- AND: both must be true */
printf("%d\n", a || b);   /* 1 -- OR:  at least one must be true */
printf("%d\n", !a);       /* 0 -- NOT: inverts the truth value */
```

**Short-circuit evaluation** — this is really important:
- In `A && B`, if A is false, B is never evaluated
- In `A || B`, if A is true, B is never evaluated

This lets you write safe code like:
```c
/* Without short-circuit, this would crash when ptr is NULL */
if (ptr != NULL && ptr->value > 0) {
    /* ptr is guaranteed non-NULL before we dereference it */
}
```

---

## 6. Bitwise Operators

These work on the binary representation of integers:

```c
unsigned char a = 0b10110101;   /* 181 in decimal */
unsigned char b = 0b11001100;   /* 204 in decimal */

printf("%d\n", a & b);    /* AND:  10000100 = 132 */
printf("%d\n", a | b);    /* OR:   11111101 = 253 */
printf("%d\n", a ^ b);    /* XOR:  01111001 = 121 */
printf("%d\n", ~a);       /* NOT:  01001010 = 74  */
printf("%d\n", a << 2);   /* Left shift: multiply by 4 */
printf("%d\n", a >> 1);   /* Right shift: divide by 2 */
```

Most common uses: setting/clearing flags, fast multiply/divide by powers of 2, checking specific bits in hardware registers.

---

## 7. Operator Precedence — Read This Before Writing Complex Expressions

| Priority | Operators | Direction |
|----------|-----------|-----------|
| Highest | `()  []  ->  .` postfix `++  --` | Left to right |
| | prefix `++  --  +  -  !  ~  *  &  sizeof` | Right to left |
| | `*  /  %` | Left to right |
| | `+  -` | Left to right |
| | `<<  >>` | Left to right |
| | `<  <=  >  >=` | Left to right |
| | `==  !=` | Left to right |
| | `&` | Left to right |
| | `^` | Left to right |
| | `\|` | Left to right |
| | `&&` | Left to right |
| | `\|\|` | Left to right |
| | `?:` | Right to left |
| | `=  +=  -=` etc. | Right to left |
| Lowest | `,` | Left to right |

**My honest advice:** when in doubt, use parentheses. `(a + b) * c` is always clearer than relying on precedence.

---

## 8. The Ternary Operator

A compact way to write a simple if-else assignment:

```c
/* condition ? value_if_true : value_if_false */

int x = 10;
int abs_x = (x >= 0) ? x : -x;   /* absolute value */

int score = 72;
char *result = (score >= 50) ? "Pass" : "Fail";

/* Nested ternary — readable when aligned like this */
char *grade = (score >= 90) ? "A" :
              (score >= 80) ? "B" :
              (score >= 70) ? "C" :
              (score >= 60) ? "D" : "F";
```

Keep ternary expressions simple. If the logic gets complex, switch to a regular if-else block.

---

## 9. Compound Assignment Operators

These combine an operation and assignment in one step:

```c
int n = 20;
n += 5;    /* same as n = n + 5;  → 25 */
n -= 3;    /* same as n = n - 3;  → 22 */
n *= 2;    /* same as n = n * 2;  → 44 */
n /= 4;    /* same as n = n / 4;  → 11 */
n %= 4;    /* same as n = n % 4;  →  3 */
n <<= 1;   /* same as n = n << 1; →  6 */
n &= 5;    /* same as n = n & 5;  →  4 */
```
