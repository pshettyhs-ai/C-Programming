/*
 * ===================================================================
 *  File    : Basic.c
 *  Topic   : 09 Arrays
 *  Level   : Beginner
 *  Author  : PAVAN SHETTY H S
 *
 *  Notes   : Written as part of my personal C programming study.
 *            Comments explain the reasoning, not just the syntax.
 *            Run with: gcc Basic.c -o out -lm && ./out
 * ===================================================================
 */

#include <stdio.h>

#define N 8

void print_arr(int arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++)
        printf(i < n-1 ? "%d, " : "%d", arr[i]);
    printf("]\n");
}

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1]) {
                int t=arr[j]; arr[j]=arr[j+1]; arr[j+1]=t;
            }
}

int linear_search(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) if (arr[i]==key) return i;
    return -1;
}

int main(void) {
    int arr[N] = {64, 25, 12, 22, 11, 90, 3, 47};
    printf("=== 1D Array ===\n");
    printf("Original: "); print_arr(arr, N);

    /* Sorted */
    bubble_sort(arr, N);
    printf("Sorted:   "); print_arr(arr, N);

    /* Search */
    int key = 22;
    int idx = linear_search(arr, N, key);
    printf("Search %d: index %d\n", key, idx);

    /* Statistics */
    int sum=0, min=arr[0], max=arr[0];
    for (int i=0; i<N; i++) {
        sum += arr[i];
        if (arr[i]<min) min=arr[i];
        if (arr[i]>max) max=arr[i];
    }
    printf("Sum=%d, Min=%d, Max=%d, Avg=%.2f\n", sum, min, max, (float)sum/N);

    /* 2D array */
    printf("\n=== 2D Array (Matrix) ===\n");
    int mat[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    printf("Matrix:\n");
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) printf("%4d", mat[i][j]);
        printf("\n");
    }

    /* Transpose */
    printf("Transpose:\n");
    for (int j=0; j<3; j++) {
        for (int i=0; i<3; i++) printf("%4d", mat[i][j]);
        printf("\n");
    }

    return 0;
}
/*
OUTPUT:
=== 1D Array ===
Original: [64, 25, 12, 22, 11, 90, 3, 47]
Sorted:   [3, 11, 12, 22, 25, 47, 64, 90]
Search 22: index 3
Sum=274, Min=3, Max=90, Avg=34.25

=== 2D Array (Matrix) ===
Matrix:
   1   2   3
   4   5   6
   7   8   9
Transpose:
   1   4   7
   2   5   8
   3   6   9
*/
