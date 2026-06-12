/*
 * ===================================================================
 *  File    : Intermediate.c
 *  Topic   : 07 Functions
 *  Level   : Intermediate
 *  Author  : PAVAN SHETTY H S
 *
 *  Notes   : Written as part of my personal C programming study.
 *            Comments explain the reasoning, not just the syntax.
 *            Run with: gcc Intermediate.c -o out -lm && ./out
 * ===================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/* Higher-order function: apply a function to each array element */
void map(int arr[], int n, int (*func)(int)) {
    for (int i = 0; i < n; i++) arr[i] = func(arr[i]);
}

int double_it(int x) { return x * 2; }
int square(int x)    { return x * x; }
int negate(int x)    { return -x; }

/* Reduce: fold array to single value */
int reduce(int arr[], int n, int init, int (*func)(int, int)) {
    int acc = init;
    for (int i = 0; i < n; i++) acc = func(acc, arr[i]);
    return acc;
}
int add(int a, int b) { return a + b; }
int mul(int a, int b) { return a * b; }

/* Filter: count elements matching predicate */
int filter_count(int arr[], int n, int (*pred)(int)) {
    int count = 0;
    for (int i = 0; i < n; i++) if (pred(arr[i])) count++;
    return count;
}
int is_even(int x) { return x % 2 == 0; }
int is_pos(int x)  { return x > 0; }

/* Memoized power function */
double memo_power(double base, int exp) {
    static double cache_base = -1;
    static int    cache_exp  = -1;
    static double cache_val  = 0;
    if (base == cache_base && exp == cache_exp) {
        printf("  [cache hit: %.1f^%d]\n", base, exp);
        return cache_val;
    }
    double result = pow(base, exp);
    cache_base = base; cache_exp = exp; cache_val = result;
    return result;
}

void print_arr(int a[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}

int main(void) {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 10;

    printf("=== Higher-Order Functions ===\n");
    printf("Original: "); print_arr(arr, n);

    int doubled[10]; memcpy(doubled, arr, sizeof(arr));
    map(doubled, n, double_it);
    printf("Doubled:  "); print_arr(doubled, n);

    int squared[10]; memcpy(squared, arr, sizeof(arr));
    map(squared, n, square);
    printf("Squared:  "); print_arr(squared, n);

    printf("\n=== Reduce ===\n");
    printf("Sum:     %d\n", reduce(arr, n, 0, add));
    printf("Product: %d\n", reduce(arr, n, 1, mul));

    printf("\n=== Filter Count ===\n");
    printf("Even count: %d\n", filter_count(arr, n, is_even));
    printf("Pos count:  %d\n", filter_count(arr, n, is_pos));

    printf("\n=== Memoized Power ===\n");
    printf("2^10 = %.0f\n", memo_power(2.0, 10));
    printf("2^10 = %.0f\n", memo_power(2.0, 10)); /* cache hit */
    printf("3^5  = %.0f\n", memo_power(3.0, 5));

    return 0;
}
