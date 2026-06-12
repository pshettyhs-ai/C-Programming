/*
 * ===================================================================
 *  File    : Advanced.c
 *  Topic   : 08 Recursion
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

/* ── 1. Merge Sort (recursive) ────────────────────────────────────────── */
void merge(int a[], int l, int m, int r) {
    int n1=m-l+1, n2=r-m;
    int *L=malloc(n1*sizeof(int)), *R=malloc(n2*sizeof(int));
    memcpy(L,a+l,n1*sizeof(int)); memcpy(R,a+m+1,n2*sizeof(int));
    int i=0,j=0,k=l;
    while(i<n1&&j<n2) a[k++]=(L[i]<=R[j])?L[i++]:R[j++];
    while(i<n1) a[k++]=L[i++]; while(j<n2) a[k++]=R[j++];
    free(L); free(R);
}
void mergesort(int a[], int l, int r) {
    if(l<r){int m=l+(r-l)/2;mergesort(a,l,m);mergesort(a,m+1,r);merge(a,l,m,r);}
}

/* ── 2. Permutations of a string ──────────────────────────────────────── */
int perm_count = 0;
void permutations(char *s, int lo, int hi) {
    if (lo == hi) { printf("%s\n", s); perm_count++; return; }
    for (int i = lo; i <= hi; i++) {
        char t=s[lo]; s[lo]=s[i]; s[i]=t;
        permutations(s, lo+1, hi);
        t=s[lo]; s[lo]=s[i]; s[i]=t;
    }
}

/* ── 3. N-Queens problem ──────────────────────────────────────────────── */
#define QUEENS 8
int board[QUEENS];
int solutions = 0;

int safe(int row, int col) {
    for (int i = 0; i < row; i++)
        if (board[i]==col || abs(board[i]-col)==abs(i-row)) return 0;
    return 1;
}
void solve_nqueens(int row) {
    if (row == QUEENS) { solutions++; return; }
    for (int col = 0; col < QUEENS; col++)
        if (safe(row, col)) { board[row]=col; solve_nqueens(row+1); }
}

/* ── 4. Flood fill (recursive) ────────────────────────────────────────── */
#define ROWS 6
#define COLS 8
char grid[ROWS][COLS+1];

void flood_fill(int r, int c, char old, char new) {
    if (r<0||r>=ROWS||c<0||c>=COLS) return;
    if (grid[r][c]!=old||grid[r][c]==new) return;
    grid[r][c]=new;
    flood_fill(r-1,c,old,new); flood_fill(r+1,c,old,new);
    flood_fill(r,c-1,old,new); flood_fill(r,c+1,old,new);
}

void print_grid(void) {
    for(int i=0;i<ROWS;i++) printf("%s\n",grid[i]);
}

int main(void) {
    /* Merge sort */
    printf("=== Recursive Merge Sort ===\n");
    int arr[]={38,27,43,3,9,82,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("Before: "); for(int i=0;i<n;i++)printf("%d ",arr[i]); printf("\n");
    mergesort(arr,0,n-1);
    printf("After:  "); for(int i=0;i<n;i++)printf("%d ",arr[i]); printf("\n");

    /* Permutations */
    printf("\n=== Permutations of 'ABC' ===\n");
    char s[]="ABC";
    perm_count=0;
    permutations(s,0,2);
    printf("Total: %d permutations\n",perm_count);

    /* N-Queens */
    printf("\n=== N-Queens (8×8) ===\n");
    solve_nqueens(0);
    printf("Solutions for 8-Queens: %d\n", solutions);

    /* Flood fill */
    printf("\n=== Flood Fill ===\n");
    strcpy(grid[0],"########");
    strcpy(grid[1],"#......#");
    strcpy(grid[2],"#.####.#");
    strcpy(grid[3],"#.#..#.#");
    strcpy(grid[4],"#......#");
    strcpy(grid[5],"########");
    printf("Before:\n"); print_grid();
    flood_fill(1,1,'.','+');
    printf("After flood fill from (1,1):\n"); print_grid();

    return 0;
}
