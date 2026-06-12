/*
 * ===================================================================
 *  File    : Basic.c
 *  Topic   : 03 Operators
 *  Level   : Beginner
 *  Author  : PAVAN SHETTY H S
 *
 *  Notes   : Written as part of my personal C programming study.
 *            Comments explain the reasoning, not just the syntax.
 *            Run with: gcc Basic.c -o out -lm && ./out
 * ===================================================================
 */

#include <stdio.h>

int main(void) {
    /* ── Arithmetic ──────────────────────────────────────────────────── */
    int a = 17, b = 5;
    printf("=== Arithmetic Operators ===\n");
    printf("%d + %d = %d\n", a, b, a + b);
    printf("%d - %d = %d\n", a, b, a - b);
    printf("%d * %d = %d\n", a, b, a * b);
    printf("%d / %d = %d  (integer division)\n", a, b, a / b);
    printf("%d %% %d = %d  (modulo)\n", a, b, a % b);

    /* ── Relational ──────────────────────────────────────────────────── */
    printf("\n=== Relational Operators ===\n");
    printf("10 == 10: %d\n", 10 == 10);
    printf("10 != 20: %d\n", 10 != 20);
    printf("10 <  20: %d\n", 10 <  20);
    printf("10 >  20: %d\n", 10 >  20);

    /* ── Logical ─────────────────────────────────────────────────────── */
    printf("\n=== Logical Operators ===\n");
    printf("1 && 0: %d\n", 1 && 0);
    printf("1 || 0: %d\n", 1 || 0);
    printf("!1:     %d\n", !1);
    printf("!0:     %d\n", !0);

    /* ── Increment/Decrement ─────────────────────────────────────────── */
    int x = 5;
    printf("\n=== Increment/Decrement ===\n");
    printf("x = %d\n", x);
    printf("x++ = %d (post), x now = %d\n", x++, x);
    printf("++x = %d (pre),  x now = %d\n", ++x, x);

    /* ── Ternary ─────────────────────────────────────────────────────── */
    int num = -7;
    int abs_num = (num >= 0) ? num : -num;
    printf("\n=== Ternary Operator ===\n");
    printf("Absolute value of %d = %d\n", num, abs_num);

    /* ── Compound Assignment ─────────────────────────────────────────── */
    int n = 20;
    printf("\n=== Compound Assignment ===\n");
    printf("n = %d\n", n);
    n += 5;  printf("n += 5 → %d\n", n);
    n -= 3;  printf("n -= 3 → %d\n", n);
    n *= 2;  printf("n *= 2 → %d\n", n);
    n /= 4;  printf("n /= 4 → %d\n", n);
    n %= 5;  printf("n %%= 5 → %d\n", n);

    return 0;
}
