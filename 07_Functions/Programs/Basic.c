/*
 * ===================================================================
 *  File    : Basic.c
 *  Topic   : 07 Functions
 *  Level   : Beginner
 *  Author  : PAVAN SHETTY H S
 *
 *  Notes   : Written as part of my personal C programming study.
 *            Comments explain the reasoning, not just the syntax.
 *            Run with: gcc Basic.c -o out -lm && ./out
 * ===================================================================
 */

#include <stdio.h>

/* ── Prototypes ──────────────────────────────────────────────────────── */
int    add(int a, int b);
int    factorial(int n);
void   swap_by_value(int a, int b);
void   swap_by_ref(int *a, int *b);
double circle_area(double radius);
int    is_prime(int n);
void   min_max(int arr[], int len, int *min, int *max);

/* ── Function Definitions ─────────────────────────────────────────────── */

int add(int a, int b) { return a + b; }

int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; i++) result *= i;
    return result;
}

void swap_by_value(int a, int b) {
    int temp = a; a = b; b = temp;
    printf("  Inside swap_by_value: a=%d b=%d\n", a, b);
}

void swap_by_ref(int *a, int *b) {
    int temp = *a; *a = *b; *b = temp;
}

double circle_area(double r) { return 3.14159265 * r * r; }

int is_prime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return 0;
    return 1;
}

void min_max(int arr[], int len, int *min, int *max) {
    *min = *max = arr[0];
    for (int i = 1; i < len; i++) {
        if (arr[i] < *min) *min = arr[i];
        if (arr[i] > *max) *max = arr[i];
    }
}

/* ── Main ─────────────────────────────────────────────────────────────── */
int main(void) {
    printf("=== Basic Functions ===\n");
    printf("add(7, 3) = %d\n", add(7, 3));
    printf("5! = %d\n", factorial(5));
    printf("Circle area (r=5) = %.2f\n", circle_area(5.0));

    printf("\n=== Call by Value vs Reference ===\n");
    int x = 10, y = 20;
    printf("Before swap: x=%d y=%d\n", x, y);
    swap_by_value(x, y);
    printf("After by-value: x=%d y=%d  (unchanged!)\n", x, y);
    swap_by_ref(&x, &y);
    printf("After by-ref:   x=%d y=%d  (swapped!)\n", x, y);

    printf("\n=== Primes up to 30 ===\n");
    for (int i = 2; i <= 30; i++)
        if (is_prime(i)) printf("%d ", i);
    printf("\n");

    printf("\n=== Min and Max ===\n");
    int arr[] = {5, 3, 8, 1, 9, 2, 7};
    int lo, hi;
    min_max(arr, 7, &lo, &hi);
    printf("Array min=%d, max=%d\n", lo, hi);

    return 0;
}
/*
OUTPUT:
=== Basic Functions ===
add(7, 3) = 10
5! = 120
Circle area (r=5) = 78.54

=== Call by Value vs Reference ===
Before swap: x=10 y=20
  Inside swap_by_value: a=20 b=10
After by-value: x=10 y=20  (unchanged!)
After by-ref:   x=20 y=10  (swapped!)
...
*/
