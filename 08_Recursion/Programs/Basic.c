/*
 * ===================================================================
 *  File    : Basic.c
 *  Topic   : 08 Recursion
 *  Level   : Beginner
 *  Author  : PAVAN SHETTY H S
 *
 *  Notes   : Written as part of my personal C programming study.
 *            Comments explain the reasoning, not just the syntax.
 *            Run with: gcc Basic.c -o out -lm && ./out
 * ===================================================================
 */

#include <stdio.h>
#include <string.h>

#define MAX 50

/* Factorial */
long long factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

/* Fibonacci (naive) */
int fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

/* Fibonacci (memoized) */
long long memo[MAX];
long long fib_memo(int n) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    return memo[n] = fib_memo(n-1) + fib_memo(n-2);
}

/* GCD */
int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}

/* Sum of array */
int array_sum(int arr[], int n) {
    if (n == 0) return 0;
    return arr[0] + array_sum(arr + 1, n - 1);
}

/* Power */
double power(double base, int exp) {
    if (exp == 0) return 1;
    if (exp < 0) return 1.0 / power(base, -exp);
    return base * power(base, exp - 1);
}

/* Tower of Hanoi */
int moves = 0;
void hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("  Move disk 1: %c → %c\n", from, to);
        moves++;
        return;
    }
    hanoi(n - 1, from, aux, to);
    printf("  Move disk %d: %c → %c\n", n, from, to);
    moves++;
    hanoi(n - 1, aux, to, from);
}

int main(void) {
    printf("=== Factorial ===\n");
    for (int i = 0; i <= 10; i++)
        printf("%2d! = %lld\n", i, factorial(i));

    printf("\n=== Fibonacci (naive) ===\n");
    for (int i = 0; i <= 10; i++)
        printf("fib(%2d) = %d\n", i, fib(i));

    printf("\n=== Fibonacci (memoized, up to 40) ===\n");
    memset(memo, -1, sizeof(memo));
    for (int i = 0; i <= 40; i += 5)
        printf("fib(%2d) = %lld\n", i, fib_memo(i));

    printf("\n=== GCD ===\n");
    printf("gcd(48, 18) = %d\n", gcd(48, 18));
    printf("gcd(100, 75) = %d\n", gcd(100, 75));

    printf("\n=== Power ===\n");
    printf("2^10 = %.0f\n", power(2, 10));
    printf("3^5  = %.0f\n", power(3, 5));

    printf("\n=== Tower of Hanoi (3 disks) ===\n");
    hanoi(3, 'A', 'C', 'B');
    printf("Total moves: %d (= 2^3 - 1)\n", moves);

    return 0;
}
/*
OUTPUT:
=== Factorial ===
 0! = 1
 1! = 1
 2! = 2
 ...
10! = 3628800
*/
