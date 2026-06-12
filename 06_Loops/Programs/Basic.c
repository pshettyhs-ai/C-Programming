/*
 * ===================================================================
 *  File    : Basic.c
 *  Topic   : 06 Loops
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
    /* ── for loop ────────────────────────────────────────────────────── */
    printf("=== for loop (1 to 5) ===\n");
    for (int i = 1; i <= 5; i++)
        printf("%d ", i);
    printf("\n");

    /* ── while loop (sum of digits) ─────────────────────────────────── */
    printf("\n=== while loop (sum of digits of 9876) ===\n");
    int n = 9876, sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    printf("Sum = %d\n", sum);   /* 30 */

    /* ── do-while (input validation) ────────────────────────────────── */
    printf("\n=== do-while (count from 1 to 3) ===\n");
    int count = 1;
    do {
        printf("Count: %d\n", count++);
    } while (count <= 3);

    /* ── Nested loops (multiplication table) ────────────────────────── */
    printf("\n=== Multiplication Table (1-5) ===\n");
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++)
            printf("%4d", i * j);
        printf("\n");
    }

    /* ── break and continue ──────────────────────────────────────────── */
    printf("\n=== break: stop at first multiple of 7 >= 20 ===\n");
    for (int i = 20; i <= 100; i++) {
        if (i % 7 == 0) { printf("Found: %d\n", i); break; }
    }

    printf("\n=== continue: print odd numbers 1-10 ===\n");
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) continue;
        printf("%d ", i);
    }
    printf("\n");

    /* ── Star pattern ────────────────────────────────────────────────── */
    printf("\n=== Right Triangle Pattern ===\n");
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= i; j++) printf("* ");
        printf("\n");
    }

    return 0;
}
/*
OUTPUT:
=== for loop (1 to 5) ===
1 2 3 4 5
=== while loop (sum of digits of 9876) ===
Sum = 30
...
*/
