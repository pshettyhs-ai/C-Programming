# Interview Questions — Bitwise Programming

## 🟢 Basic
**Q1. What is the difference between logical AND (`&&`) and bitwise AND (`&`)?**
> `&&` is logical — returns 0 or 1, short-circuits (right side not evaluated if left is 0). `&` is bitwise — operates on each corresponding pair of bits, always evaluates both operands. `5 && 3` = 1 (true). `5 & 3` = 1 (0b101 & 0b011 = 0b001). Never confuse them in conditions.

**Q2. How do you set, clear, toggle, and check a specific bit?**
```c
x |=  (1 << n);   /* set bit n */
x &= ~(1 << n);   /* clear bit n */
x ^=  (1 << n);   /* toggle bit n */
bit = (x >> n) & 1;  /* check bit n */
```

**Q3. What does `x & (x-1)` do?**
> Clears the rightmost (lowest) set bit. If x=0b10110, x-1=0b10101, AND=0b10100 — the rightmost 1 is cleared. Used in Kernighan's bit counting algorithm (loop until x==0, each iteration removes one set bit, count iterations).

## 🟡 Intermediate
**Q4. How do you check if a number is a power of 2 using bitwise?**
```c
int is_power_of_2 = (n > 0) && ((n & (n-1)) == 0);
```
> A power of 2 has exactly one bit set. Subtracting 1 flips all lower bits: `1000 - 1 = 0111`. AND of these two is always 0 for powers of 2.

**Q5. How do you find the only non-duplicate in an array where all other elements appear twice?**
```c
int result = 0;
for (int i = 0; i < n; i++) result ^= arr[i];
/* x ^ x = 0 (cancel pairs), x ^ 0 = x (unique survives) */
```
> Time O(n), Space O(1). A classic interview trick question.

**Q6. How would you store Unix file permissions (rwxrwxrwx) compactly?**
> In 9 bits of an integer. Each group of 3 bits encodes rwx for owner/group/other. `chmod 755` = `111 101 101` binary = 0755 octal. Check: `if (mode & 0x100)` = owner read. Set: `mode |= 0x001` = other execute. Clear: `mode &= ~0x040` = remove group write.

## 🔴 Advanced
**Q7. What is the fast inverse square root from Quake III and how does it use bit manipulation?**
> The infamous hack interprets a float's bits as an integer for an initial approximation:
```c
float Q_rsqrt(float number) {
    long i = *(long*)&number;        /* type pun: float bits as int */
    i = 0x5f3759df - (i >> 1);     /* magic constant + bit shift */
    float y = *(float*)&i;          /* convert back to float */
    return y * (1.5f - 0.5f * number * y * y);  /* Newton's method */
}
```
> Exploits IEEE 754 floating-point representation. The integer value of a float approximates its logarithm, so halving the integer approximates half the log (= log of square root). Now mostly a historical curiosity — CPUs have hardware rsqrt instructions.

**Q8. How do you reverse all bits in a 32-bit integer?**
```c
uint32_t reverse_bits(uint32_t n) {
    n = ((n & 0xffff0000) >> 16) | ((n & 0x0000ffff) << 16);
    n = ((n & 0xff00ff00) >>  8) | ((n & 0x00ff00ff) <<  8);
    n = ((n & 0xf0f0f0f0) >>  4) | ((n & 0x0f0f0f0f) <<  4);
    n = ((n & 0xcccccccc) >>  2) | ((n & 0x33333333) <<  2);
    n = ((n & 0xaaaaaaaa) >>  1) | ((n & 0x55555555) <<  1);
    return n;
}
/* Divide-and-conquer: swap halves, then quarters, then bytes, etc. O(log bits) */
```

---

*— Pavan Shetty H S*
