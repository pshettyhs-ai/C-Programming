/*
 * ===================================================================
 *  File    : Intermediate.c
 *  Topic   : 11 Pointers
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
#include <string.h>

/* Pointer-based string reverse */
void str_reverse(char *s) {
    char *lo = s, *hi = s + strlen(s) - 1;
    while (lo < hi) { char t=*lo; *lo++=*hi--; *hi=t; } /* careful: hi-- then assign */
}
/* Fix: */
void str_rev(char *s) {
    char *lo = s, *hi = s + strlen(s) - 1;
    while (lo < hi) { char t=*lo; *lo=*hi; *hi=t; lo++; hi--; }
}

/* Pointer-based array rotation */
void rotate_left(int *arr, int n, int k) {
    k %= n;
    /* Reverse three segments */
    void rev(int *a, int *b) { while(a<b){int t=*a;*a++=*b--;*b=t;} /* buggy inline */}
    /* Use proper approach */
    int *tmp = malloc(k * sizeof(int));
    memcpy(tmp, arr, k * sizeof(int));
    memmove(arr, arr + k, (n - k) * sizeof(int));
    memcpy(arr + n - k, tmp, k * sizeof(int));
    free(tmp);
}

/* Generic pointer to print array of any int type */
void print_int_arr(void *arr, int n, size_t elem_size) {
    unsigned char *p = arr;
    for (int i = 0; i < n; i++) {
        int val = 0;
        memcpy(&val, p + i * elem_size, elem_size);
        printf("%d ", val);
    }
    printf("\n");
}

/* Pointer chain: build a number triangle */
void pointer_triangle(int n) {
    int **tri = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        tri[i] = malloc((i + 1) * sizeof(int));
        for (int j = 0; j <= i; j++)
            tri[i][j] = (j == 0 || j == i) ? 1 : tri[i-1][j-1] + tri[i-1][j];
    }
    printf("Pascal's Triangle:\n");
    for (int i = 0; i < n; i++) {
        for (int sp = 0; sp < n-i-1; sp++) printf("  ");
        for (int j = 0; j <= i; j++) printf("%4d", tri[i][j]);
        printf("\n");
        free(tri[i]);
    }
    free(tri);
}

/* Const correctness demonstration */
void print_matrix(const int (*mat)[4], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 4; j++) printf("%4d", mat[i][j]);
        printf("\n");
    }
}

int main(void) {
    printf("=== Pointer-based String Operations ===\n");
    char s[] = "Hello, World!";
    printf("Before: %s\n", s);
    str_rev(s);
    printf("After:  %s\n", s);
    str_rev(s);
    printf("Restored: %s\n", s);

    printf("\n=== Array Rotation via Pointer ===\n");
    int arr[] = {1,2,3,4,5,6,7,8};
    int n = 8;
    printf("Original: ");
    for(int i=0;i<n;i++) printf("%d ",arr[i]); printf("\n");
    rotate_left(arr, n, 3);
    printf("Left by 3: ");
    for(int i=0;i<n;i++) printf("%d ",arr[i]); printf("\n");

    printf("\n=== Pascal's Triangle (Dynamic 2D via double pointer) ===\n");
    pointer_triangle(6);

    printf("\n=== Const Pointer to 2D Array ===\n");
    int mat[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    print_matrix(mat, 3);

    printf("\n=== Pointer Arithmetic on Different Types ===\n");
    double da[] = {1.1, 2.2, 3.3, 4.4};
    double *dp = da;
    for (int i = 0; i < 4; i++)
        printf("da[%d] at %p = %.1f\n", i, (void*)(dp+i), *(dp+i));

    return 0;
}
