/*
 * ===================================================================
 *  File    : Advanced.c
 *  Topic   : 09 Arrays
 *  Level   : Advanced
 *  Author  : PAVAN SHETTY H S
 *
 *  Notes   : Written as part of my personal C programming study.
 *            Comments explain the reasoning, not just the syntax.
 *            Run with: gcc Advanced.c -o out -lm && ./out
 * ===================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/* ── 1. Two-sum problem — O(n) using hashing simulation ──────────────── */
int two_sum(int arr[], int n, int target, int *idx1, int *idx2) {
    /* Simple O(n²) for demo — for O(n) use hash table */
    for (int i=0;i<n-1;i++)
        for (int j=i+1;j<n;j++)
            if (arr[i]+arr[j]==target) { *idx1=i; *idx2=j; return 1; }
    return 0;
}

/* ── 2. Spiral matrix traversal ───────────────────────────────────────── */
void spiral_print(int mat[][5], int rows, int cols) {
    int top=0, bot=rows-1, left=0, right=cols-1;
    while (top<=bot && left<=right) {
        for(int i=left;i<=right;i++) printf("%3d",mat[top][i]); top++;
        for(int i=top;i<=bot;i++)   printf("%3d",mat[i][right]); right--;
        if(top<=bot){ for(int i=right;i>=left;i--) printf("%3d",mat[bot][i]); bot--; }
        if(left<=right){ for(int i=bot;i>=top;i--) printf("%3d",mat[i][left]); left++; }
    }
    printf("\n");
}

/* ── 3. Sparse matrix representation ─────────────────────────────────── */
typedef struct { int row, col, val; } Element;

int sparse_compress(int mat[][6], int rows, int cols, Element out[], int *size) {
    *size = 0;
    for(int i=0;i<rows;i++) for(int j=0;j<cols;j++)
        if(mat[i][j]) { out[(*size)].row=i; out[(*size)].col=j; out[(*size)++].val=mat[i][j]; }
    return *size;
}

/* ── 4. Longest increasing subsequence (LIS) — O(n²) DP ──────────────── */
int lis(int arr[], int n) {
    int *dp = calloc(n, sizeof(int));
    for(int i=0;i<n;i++) dp[i]=1;
    for(int i=1;i<n;i++)
        for(int j=0;j<i;j++)
            if(arr[j]<arr[i] && dp[j]+1>dp[i]) dp[i]=dp[j]+1;
    int max=1;
    for(int i=0;i<n;i++) if(dp[i]>max) max=dp[i];
    free(dp);
    return max;
}

/* ── 5. Prefix sum array — range sum query O(1) ───────────────────────── */
void build_prefix(int arr[], int prefix[], int n) {
    prefix[0] = arr[0];
    for(int i=1;i<n;i++) prefix[i] = prefix[i-1] + arr[i];
}
int range_sum(int prefix[], int l, int r) {
    return l == 0 ? prefix[r] : prefix[r] - prefix[l-1];
}

int main(void) {
    printf("=== Two Sum ===\n");
    int a[]={2,7,11,15,1,8}, target=9;
    int i1,i2;
    if(two_sum(a,6,target,&i1,&i2))
        printf("Target %d: a[%d]=%d + a[%d]=%d\n",target,i1,a[i1],i2,a[i2]);

    printf("\n=== Spiral Matrix Traversal ===\n");
    int mat[4][5];
    for(int i=0;i<4;i++) for(int j=0;j<5;j++) mat[i][j]=i*5+j+1;
    printf("Matrix:\n");
    for(int i=0;i<4;i++){for(int j=0;j<5;j++)printf("%3d",mat[i][j]);printf("\n");}
    printf("Spiral: "); spiral_print(mat,4,5);

    printf("\n=== Sparse Matrix Compression ===\n");
    int sparse[4][6]={{0,0,3,0,0,0},{0,4,0,0,0,0},{0,0,0,5,0,0},{0,0,0,0,0,6}};
    Element elems[10]; int sz;
    sparse_compress(sparse,4,6,elems,&sz);
    printf("Non-zero elements:\n");
    for(int i=0;i<sz;i++) printf("  (%d,%d) = %d\n",elems[i].row,elems[i].col,elems[i].val);

    printf("\n=== Longest Increasing Subsequence ===\n");
    int b[]={10,9,2,5,3,7,101,18};
    printf("Array: "); for(int i=0;i<8;i++)printf("%d ",b[i]); printf("\n");
    printf("LIS length: %d\n", lis(b,8));

    printf("\n=== Prefix Sum (Range Queries) ===\n");
    int c[]={3,2,4,1,5,7,2,3};
    int prefix[8]; int nc=8;
    build_prefix(c,prefix,nc);
    printf("Array:  "); for(int i=0;i<nc;i++)printf("%d ",c[i]); printf("\n");
    printf("Prefix: "); for(int i=0;i<nc;i++)printf("%d ",prefix[i]); printf("\n");
    int queries[][2]={{0,3},{2,5},{1,6},{0,7}};
    for(int i=0;i<4;i++)
        printf("Sum [%d..%d] = %d\n",queries[i][0],queries[i][1],
               range_sum(prefix,queries[i][0],queries[i][1]));

    return 0;
}
