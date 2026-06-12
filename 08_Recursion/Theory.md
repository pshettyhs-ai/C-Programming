# Theory — Recursion

> **Author: Pavan Shetty H S**

---

## 1. What is Recursion?

Recursion is when a function calls itself to solve a smaller version of the same problem. The idea is: if you can solve the smallest possible case directly, and if you can express any larger case in terms of a smaller one, then recursion handles the rest.

When I first encountered recursion, it felt like a trick. After writing a few examples and tracing through the call stack by hand, it clicked.

---

## 2. The Two Rules — Follow These Every Time

1. **Every recursive function must have a base case** — the condition that stops the recursion. Without it, the function calls itself forever and the program crashes with a stack overflow.

2. **Each recursive call must make progress toward the base case** — the problem must get simpler with every call.

```c
return_type recursive_func(parameters) {

    /* BASE CASE — check this first */
    if (simplest_possible_case) {
        return base_value;
    }

    /* RECURSIVE CASE — make the problem smaller and call again */
    return recursive_func(smaller_problem);
}
```

---

## 3. Factorial — The Classic Starting Example

```c
/* n! = n × (n-1) × (n-2) × ... × 1, and 0! = 1 */
int factorial(int n) {
    if (n <= 1) return 1;               /* base case */
    return n * factorial(n - 1);        /* recursive case */
}
```

**Tracing factorial(4) by hand:**
```
factorial(4)
  = 4 × factorial(3)
  = 4 × (3 × factorial(2))
  = 4 × (3 × (2 × factorial(1)))
  = 4 × (3 × (2 × 1))           ← base case reached
  = 4 × (3 × 2)
  = 4 × 6
  = 24
```

Each call waits for the next one to return before finishing. This is what makes the call stack grow.

---

## 4. Fibonacci — Two Recursive Calls

```c
/* fib(0)=0, fib(1)=1, fib(n) = fib(n-1) + fib(n-2) */
int fib(int n) {
    if (n <= 1) return n;               /* base cases */
    return fib(n - 1) + fib(n - 2);    /* two recursive calls */
}
```

This works but is extremely slow. `fib(40)` makes over a billion function calls because the same subproblems are recalculated repeatedly.

**The fix — memoization (cache the results):**
```c
#define MAX 100
long long cache[MAX];

long long fib_fast(int n) {
    if (n <= 1) return n;
    if (cache[n] != -1) return cache[n];     /* already computed */
    cache[n] = fib_fast(n-1) + fib_fast(n-2);
    return cache[n];
}

/* Before first call: memset(cache, -1, sizeof(cache)); */
```

`fib_fast(40)` makes only 79 calls instead of over a billion. Same results, completely different performance.

---

## 5. How the Call Stack Works

Every function call pushes a **stack frame** onto the stack. The frame holds the function's local variables and the return address. When the function returns, the frame is popped off.

```
Calling factorial(3):

Stack (top = most recent call)
┌──────────────────────────────┐
│  factorial(1)  ← top         │  n=1, returns 1
│  factorial(2)                │  n=2, waiting for factorial(1)
│  factorial(3)                │  n=3, waiting for factorial(2)
│  main()        ← bottom      │  waiting for factorial(3)
└──────────────────────────────┘

As each call returns, its frame is removed.
After all returns, main() gets the result: 6.
```

**Stack overflow** happens when recursion goes too deep — too many frames, not enough stack memory. Typical stack size is 1–8 MB. For very deep recursion, convert to iteration.

---

## 6. GCD — Elegant Recursion

```c
/* Euclidean algorithm: gcd(a, b) = gcd(b, a % b), gcd(a, 0) = a */
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

/* gcd(48, 18):
   gcd(48, 18) → gcd(18, 12) → gcd(12, 6) → gcd(6, 0) → 6
*/
```

---

## 7. Tower of Hanoi — The Problem Recursion Was Born For

Move n disks from peg A to peg C using peg B as auxiliary. Rules: only move one disk at a time, never place a larger disk on top of a smaller one.

```c
void hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Move disk 1: %c → %c\n", from, to);
        return;
    }
    hanoi(n - 1, from, aux, to);         /* move top n-1 to auxiliary */
    printf("Move disk %d: %c → %c\n", n, from, to);
    hanoi(n - 1, aux, to, from);         /* move n-1 from auxiliary to destination */
}

/* hanoi(3, 'A', 'C', 'B') produces 7 moves = 2³ - 1 */
/* For n disks: always 2ⁿ - 1 moves — proved optimal */
```

---

## 8. Recursion vs Iteration

| Aspect | Recursion | Iteration |
|--------|-----------|-----------|
| Code clarity | Often cleaner for tree/divide-and-conquer problems | Clear for sequential tasks |
| Performance | Call overhead per frame | Usually faster |
| Memory | O(n) stack frames for depth n | O(1) usually |
| Stack overflow risk | Yes, for large n | No |
| Best for | Trees, graphs, divide-and-conquer | Arrays, known iteration counts |

---

## 9. Tail Recursion

A function is tail-recursive when the recursive call is the very last thing it does — no pending computation after it returns.

```c
/* NOT tail-recursive: must multiply after the recursive call returns */
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);    /* multiplication happens after return */
}

/* Tail-recursive: the recursive call IS the return */
int fact_tail(int n, int acc) {
    if (n <= 1) return acc;
    return fact_tail(n - 1, n * acc);    /* no pending work */
}
/* Usage: fact_tail(5, 1) */
```

Good compilers (GCC with `-O2`) convert tail recursion to a loop internally, eliminating stack growth. This makes deep recursion safe.
