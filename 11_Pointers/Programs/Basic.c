/*
 * ===================================================================
 *  File    : Basic.c
 *  Topic   : 11 Pointers
 *  Level   : Beginner
 *  Author  : PAVAN SHETTY H S
 *
 *  Notes   : Written as part of my personal C programming study.
 *            Comments explain the reasoning, not just the syntax.
 *            Run with: gcc Basic.c -o out -lm && ./out
 * ===================================================================
 */

#include <stdio.h>

void increment(int *p) { (*p)++; }
void swap(int *a, int *b) { int t=*a; *a=*b; *b=t; }

int main(void) {
    /* ── Basics ──────────────────────────────────────────────────────── */
    printf("=== Pointer Basics ===\n");
    int x = 42;
    int *p = &x;
    printf("x    = %d\n", x);
    printf("&x   = %p\n", (void*)&x);
    printf("p    = %p\n", (void*)p);
    printf("*p   = %d\n", *p);
    *p = 100;
    printf("After *p=100: x = %d\n", x);

    /* ── Pointer arithmetic ──────────────────────────────────────────── */
    printf("\n=== Pointer Arithmetic ===\n");
    int arr[] = {10, 20, 30, 40, 50};
    int *q = arr;
    printf("arr[0]=%d  *(q+0)=%d\n", arr[0], *q);
    printf("arr[1]=%d  *(q+1)=%d\n", arr[1], *(q+1));
    printf("arr[4]=%d  *(q+4)=%d\n", arr[4], *(q+4));
    printf("Element span: %td\n", (arr+5) - arr);

    /* ── Functions with pointers ─────────────────────────────────────── */
    printf("\n=== Pointer Parameters ===\n");
    int n = 5;
    printf("Before increment: %d\n", n);
    increment(&n);
    printf("After increment:  %d\n", n);

    int a=10, b=20;
    printf("Before swap: a=%d b=%d\n", a, b);
    swap(&a, &b);
    printf("After swap:  a=%d b=%d\n", a, b);

    /* ── Pointer traversal of array ──────────────────────────────────── */
    printf("\n=== Traverse Array via Pointer ===\n");
    for (int *ptr = arr; ptr < arr + 5; ptr++)
        printf("addr=%p  val=%d\n", (void*)ptr, *ptr);

    /* ── Double pointer ──────────────────────────────────────────────── */
    printf("\n=== Double Pointer ===\n");
    int  val  = 99;
    int *pv   = &val;
    int **ppv = &pv;
    printf("val=%d  *pv=%d  **ppv=%d\n", val, *pv, **ppv);
    **ppv = 777;
    printf("After **ppv=777: val=%d\n", val);

    /* ── NULL pointer check ──────────────────────────────────────────── */
    printf("\n=== NULL Pointer Check ===\n");
    int *np = NULL;
    printf("np = %p\n", (void*)np);
    if (np == NULL) printf("Pointer is NULL — not safe to dereference\n");

    return 0;
}
/*
OUTPUT:
=== Pointer Basics ===
x    = 42
&x   = 0x7ffd...
p    = 0x7ffd...
*p   = 42
After *p=100: x = 100
...
*/
