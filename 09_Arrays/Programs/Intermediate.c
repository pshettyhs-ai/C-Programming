/*
 * ===================================================================
 *  File    : Intermediate.c
 *  Topic   : 09 Arrays
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
#include <time.h>

/* Merge two sorted arrays into a third */
void merge_sorted(int a[], int na, int b[], int nb, int out[]) {
    int i = 0, j = 0, k = 0;
    while (i < na && j < nb)
        out[k++] = (a[i] <= b[j]) ? a[i++] : b[j++];
    while (i < na) out[k++] = a[i++];
    while (j < nb) out[k++] = b[j++];
}

/* Dutch National Flag — sort 0s, 1s, 2s in O(n) */
void dutch_flag(int a[], int n) {
    int lo = 0, mid = 0, hi = n - 1;
    while (mid <= hi) {
        if      (a[mid] == 0) { int t=a[lo];a[lo]=a[mid];a[mid]=t; lo++;mid++; }
        else if (a[mid] == 1) { mid++; }
        else                  { int t=a[mid];a[mid]=a[hi];a[hi]=t; hi--; }
    }
}

/* Kadane's algorithm — max subarray sum O(n) */
int max_subarray(int a[], int n, int *start, int *end) {
    int max_sum = a[0], curr = a[0];
    *start = *end = 0;
    int s = 0;
    for (int i = 1; i < n; i++) {
        if (curr + a[i] < a[i]) { curr = a[i]; s = i; }
        else                    { curr += a[i]; }
        if (curr > max_sum) { max_sum = curr; *start = s; *end = i; }
    }
    return max_sum;
}

/* Matrix multiplication O(n³) */
void mat_mul(int a[][3], int b[][3], int c[][3], int n) {
    for (int i=0;i<n;i++) for (int j=0;j<n;j++) {
        c[i][j]=0;
        for (int k=0;k<n;k++) c[i][j]+=a[i][k]*b[k][j];
    }
}

void print_arr(int a[], int n){ for(int i=0;i<n;i++)printf("%d ",a[i]);printf("\n"); }
void print_mat(int m[][3],int n){ for(int i=0;i<n;i++){for(int j=0;j<n;j++)printf("%4d",m[i][j]);printf("\n");} }

int main(void) {
    printf("=== Merge Sorted Arrays ===\n");
    int a[]={1,3,5,7,9}, b[]={2,4,6,8,10}, out[10];
    merge_sorted(a,5,b,5,out);
    printf("Merged: "); print_arr(out,10);

    printf("\n=== Dutch National Flag O(n) ===\n");
    int dnf[]={2,0,1,2,1,0,0,2,1,0,1};
    int dn=sizeof(dnf)/sizeof(dnf[0]);
    printf("Before: "); print_arr(dnf,dn);
    dutch_flag(dnf,dn);
    printf("After:  "); print_arr(dnf,dn);

    printf("\n=== Kadane's Max Subarray ===\n");
    int k[]={-2,1,-3,4,-1,2,1,-5,4};
    int kn=sizeof(k)/sizeof(k[0]),ks,ke;
    int kmax=max_subarray(k,kn,&ks,&ke);
    printf("Array:       "); print_arr(k,kn);
    printf("Max sum:     %d (indices %d to %d)\n",kmax,ks,ke);
    printf("Subarray:    "); print_arr(k+ks,ke-ks+1);

    printf("\n=== Matrix Multiplication ===\n");
    int A[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int B[3][3]={{9,8,7},{6,5,4},{3,2,1}};
    int C[3][3];
    mat_mul(A,B,C,3);
    printf("A:\n"); print_mat(A,3);
    printf("B:\n"); print_mat(B,3);
    printf("A×B:\n"); print_mat(C,3);

    return 0;
}
