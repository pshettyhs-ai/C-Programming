/*
 * ===================================================================
 *  File    : Basic.c
 *  Topic   : 21 Data Structures in C
 *  Level   : Beginner
 *  Author  : PAVAN SHETTY H S
 *
 *  Notes   : Written as part of my personal C programming study.
 *            Comments explain the reasoning, not just the syntax.
 *            Run with: gcc Basic.c -o out -lm && ./out
 * ===================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/* ── Linear Search — O(n) ─────────────────────────────────────────────── */
int linear_search(int a[], int n, int key) {
    for (int i=0;i<n;i++) if (a[i]==key) return i;
    return -1;
}

/* ── Binary Search (Iterative) — O(log n) ────────────────────────────── */
int binary_search(int a[], int n, int key) {
    int lo=0, hi=n-1;
    while (lo<=hi) {
        int mid=lo+(hi-lo)/2;         /* prevents overflow vs (lo+hi)/2 */
        if (a[mid]==key) return mid;
        else if (a[mid]<key) lo=mid+1;
        else hi=mid-1;
    }
    return -1;
}

/* ── Binary Search (Recursive) ────────────────────────────────────────── */
int binary_search_rec(int a[], int lo, int hi, int key) {
    if (lo>hi) return -1;
    int mid=lo+(hi-lo)/2;
    if (a[mid]==key) return mid;
    if (a[mid]<key)  return binary_search_rec(a,mid+1,hi,key);
    return binary_search_rec(a,lo,mid-1,key);
}

/* ── Jump Search — O(√n) ──────────────────────────────────────────────── */
int jump_search(int a[], int n, int key) {
    int step=(int)sqrt(n), prev=0;
    while (step<n && a[step]<key) { prev=step; step+=( int)sqrt(n); }
    for (int i=prev; i<n&&i<step; i++)
        if (a[i]==key) return i;
    return -1;
}

/* ── Interpolation Search — O(log log n) for uniform data ─────────────── */
int interpolation_search(int a[], int n, int key) {
    int lo=0, hi=n-1;
    while (lo<=hi && key>=a[lo] && key<=a[hi]) {
        if (lo==hi) { return (a[lo]==key)?lo:-1; }
        int pos = lo + (int)(((double)(hi-lo)/(a[hi]-a[lo]))*(key-a[lo]));
        if (a[pos]==key) return pos;
        if (a[pos]<key)  lo=pos+1;
        else             hi=pos-1;
    }
    return -1;
}

/* ── First and Last occurrence (Binary Search variant) ────────────────── */
int first_occurrence(int a[], int n, int key) {
    int lo=0,hi=n-1,res=-1;
    while (lo<=hi) {
        int mid=lo+(hi-lo)/2;
        if (a[mid]==key) { res=mid; hi=mid-1; }
        else if (a[mid]<key) lo=mid+1;
        else hi=mid-1;
    }
    return res;
}
int last_occurrence(int a[], int n, int key) {
    int lo=0,hi=n-1,res=-1;
    while (lo<=hi) {
        int mid=lo+(hi-lo)/2;
        if (a[mid]==key) { res=mid; lo=mid+1; }
        else if (a[mid]<key) lo=mid+1;
        else hi=mid-1;
    }
    return res;
}

int main(void) {
    int sorted[] = {2,5,8,12,16,23,38,42,55,67,72,88,94,99,101};
    int n = sizeof(sorted)/sizeof(sorted[0]);

    printf("=== Searching Algorithms ===\n");
    printf("Array: ");
    for(int i=0;i<n;i++) printf("%d ",sorted[i]); printf("\n\n");

    int keys[]={42,55,1,101,67};
    for(int k=0;k<5;k++){
        int key=keys[k];
        printf("Search %3d:\n",key);
        printf("  Linear:        idx=%2d\n", linear_search(sorted,n,key));
        printf("  Binary (iter): idx=%2d\n", binary_search(sorted,n,key));
        printf("  Binary (rec):  idx=%2d\n", binary_search_rec(sorted,0,n-1,key));
        printf("  Jump:          idx=%2d\n", jump_search(sorted,n,key));
        printf("  Interpolation: idx=%2d\n", interpolation_search(sorted,n,key));
    }

    /* Duplicates: first/last occurrence */
    printf("\n=== First/Last Occurrence ===\n");
    int dups[]={1,2,2,3,3,3,4,4,4,4,5};
    int dn=sizeof(dups)/sizeof(dups[0]);
    int targets[]={3,4,1,5,6};
    for(int i=0;i<5;i++){
        int t=targets[i];
        printf("Target %d: first=%d last=%d\n",
               t,first_occurrence(dups,dn,t),last_occurrence(dups,dn,t));
    }
    return 0;
}
