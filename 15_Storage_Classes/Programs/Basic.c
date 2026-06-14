/*
 * ===================================================================
 *  File    : Basic.c
 *  Topic   : 15 Storage Classes
 *  Level   : Beginner
 *  Author  : PAVAN SHETTY H S
 *
 *  Notes   : Written as part of my personal C programming study.
 *            Comments explain the reasoning, not just the syntax.
 *            Run with: gcc Basic.c -o out -lm && ./out
 * ===================================================================
 */

#include <stdio.h>

/* Global — external linkage by default */
int global_var = 100;

/* Static global — internal linkage (file-private) */
static int file_private = 42;

/* Static local counter */
void call_counter(void) {
    static int count = 0;
    count++;
    printf("Function called %d time(s)\n", count);
}

/* Static memoization cache */
long long fib(int n) {
    static long long cache[50] = {0};
    if (n <= 1) return n;
    if (cache[n]) return cache[n];
    return cache[n] = fib(n-1) + fib(n-2);
}

int main(void) {
    printf("=== auto (default local) ===\n");
    {
        auto int local = 10;   /* auto is default, rarely explicit */
        printf("local = %d\n", local);
    }
    /* local is gone here */

    printf("\n=== static local ===\n");
    call_counter();
    call_counter();
    call_counter();

    printf("\n=== global vs static-global ===\n");
    printf("global_var    = %d\n", global_var);
    printf("file_private  = %d\n", file_private);

    printf("\n=== static cache (fibonacci) ===\n");
    for(int i=0;i<=10;i++)
        printf("fib(%2d) = %lld\n", i, fib(i));

    printf("\n=== register (hint only) ===\n");
    register int sum = 0;
    for(register int i=1;i<=100;i++) sum+=i;
    printf("Sum 1-100 = %d\n", sum);

    return 0;
}
/*
OUTPUT:
=== auto (default local) ===
local = 10

=== static local ===
Function called 1 time(s)
Function called 2 time(s)
Function called 3 time(s)
...
*/
