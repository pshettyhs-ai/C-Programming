# Theory — Bitwise Programming

> **Author: Pavan Shetty H S**

---

## 1. Why Bitwise Operations?

Every value in your computer is stored as bits. Bitwise operations let you work at that level directly — set individual flags, pack data tightly, or perform fast arithmetic. These operations appear constantly in embedded systems, operating systems, network code, and interview questions.

---

## 2. The Six Bitwise Operators

| Operator | Name | What it does |
|----------|------|-------------|
| `&` | AND | 1 only where both bits are 1 |
| `\|` | OR | 1 where at least one bit is 1 |
| `^` | XOR | 1 where exactly one bit is 1 |
| `~` | NOT | Flips every bit |
| `<<` | Left shift | Shifts bits left, fills with 0 |
| `>>` | Right shift | Shifts bits right |

```c
unsigned char a = 0b10110101;   /* 181 */
unsigned char b = 0b11001100;   /* 204 */

a & b   /* 10000100 = 132   bits that are 1 in BOTH */
a | b   /* 11111101 = 253   bits that are 1 in EITHER */
a ^ b   /* 01111001 = 121   bits that are 1 in EXACTLY ONE */
~a      /* 01001010 = 74    every bit flipped */
a << 2  /* shift left 2 positions = multiply by 4 */
a >> 1  /* shift right 1 position = divide by 2 */
```

---

## 3. The Four Essential Bit Tricks

Memorise these. They appear in virtually every bitwise interview question.

```c
unsigned int x = 0b10110100;
int n = 2;    /* bit position — 0 is the rightmost (least significant) bit */

/* SET bit n — force it to 1 */
x |= (1u << n);

/* CLEAR bit n — force it to 0 */
x &= ~(1u << n);

/* TOGGLE bit n — flip it */
x ^= (1u << n);

/* CHECK bit n — is it 1 or 0? */
int is_set = (x >> n) & 1;
```

---

## 4. Shift-Based Arithmetic

```c
/* Left shift = multiply by power of 2 (usually faster than *) */
int x = 5;
printf("%d\n", x << 1);   /* 10 — multiply by 2 */
printf("%d\n", x << 3);   /* 40 — multiply by 8 */

/* Right shift = divide by power of 2 (for non-negative values) */
printf("%d\n", 64 >> 1);  /* 32 — divide by 2 */
printf("%d\n", 64 >> 3);  /* 8  — divide by 8 */

/* Important: right-shifting a negative signed integer is implementation-defined */
/* For safe bit shifting, always use unsigned types */
```

---

## 5. Bit Flags — How Permissions Work

This is the exact technique Unix file permissions use:

```c
#define PERM_READ    (1u << 0)    /* 001 = 1 */
#define PERM_WRITE   (1u << 1)    /* 010 = 2 */
#define PERM_EXEC    (1u << 2)    /* 100 = 4 */

unsigned int perms = 0;

/* Grant permissions */
perms |= PERM_READ | PERM_WRITE;    /* perms = 011 = 3 */

/* Check a permission */
if (perms & PERM_READ)
    printf("Can read\n");

/* Revoke a permission */
perms &= ~PERM_WRITE;    /* perms = 001 = 1 */

/* Check multiple at once */
if ((perms & (PERM_READ | PERM_WRITE)) == (PERM_READ | PERM_WRITE))
    printf("Has both read and write\n");
```

---

## 6. Useful Tricks

**Check if a number is a power of 2:**
```c
int is_power_of_2 = (n > 0) && ((n & (n - 1)) == 0);
/* A power of 2 has exactly one bit set: 1000 & 0111 = 0 */
```

**Clear the lowest set bit:**
```c
x &= (x - 1);    /* 1010 → 1000,  1100 → 1000 */
```

**Count set bits — Kernighan's method:**
```c
int count_bits(unsigned int n) {
    int count = 0;
    while (n) {
        n &= (n - 1);    /* clears lowest set bit each iteration */
        count++;
    }
    return count;
}
/* Runs in O(number of set bits) — faster than checking every bit */
```

**XOR swap — swap without a temp variable:**
```c
a ^= b;
b ^= a;
a ^= b;
/* Works but is slower than using a temp variable on modern CPUs */
/* Do not use this in real code — it only exists in interviews */
```

**Find the unique element in an array (all others appear twice):**
```c
int find_unique(int arr[], int n) {
    int result = 0;
    for (int i = 0; i < n; i++) result ^= arr[i];
    return result;
    /* x ^ x = 0, x ^ 0 = x — pairs cancel, unique survives */
}
int arr[] = {3, 5, 3, 7, 5};
printf("%d\n", find_unique(arr, 5));    /* 7 */
```

---

## 7. Common Mistakes

```c
/* Mistake 1: Bitwise vs logical — easy to confuse */
if (a & b)    /* bitwise AND — result may be non-zero but non-1 */
if (a && b)   /* logical AND — result is always 0 or 1 */

/* Mistake 2: Left-shifting into sign bit */
int x = 1;
x = x << 31;    /* undefined behaviour for signed int */
/* Fix: use unsigned int: (1u << 31) */

/* Mistake 3: Applying bitwise NOT to a small type */
unsigned char x = 0b00001111;
unsigned char result = ~x;    /* result = 11110000 = 240 — correct */
int wrong = ~x;               /* int ~x is 0xFFFFFFF0 — different! */

/* Mistake 4: Using % instead of & for power-of-2 modulo */
int rem1 = n % 8;     /* correct but slower */
int rem2 = n & 7;     /* same result, faster for powers of 2 */
```
