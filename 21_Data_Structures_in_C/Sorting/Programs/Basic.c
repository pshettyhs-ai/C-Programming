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
#include <string.h>
#include <time.h>

/* ── Utility ──────────────────────────────────────────────────────────── */
void swap(int *a, int *b) { int t=*a; *a=*b; *b=t; }

void print_arr(const char *label, int a[], int n) {
    printf("%-18s ", label);
    for (int i=0;i<n;i++) printf("%3d",a[i]);
    printf("\n");
}

void copy_arr(int dst[], const int src[], int n) {
    memcpy(dst, src, n * sizeof(int));
}

/* ── Bubble Sort ──────────────────────────────────────────────────────── */
void bubble_sort(int a[], int n) {
    for (int i=0;i<n-1;i++) {
        int swapped = 0;
        for (int j=0;j<n-i-1;j++)
            if (a[j]>a[j+1]) { swap(&a[j],&a[j+1]); swapped=1; }
        if (!swapped) break;  /* already sorted — O(n) best case */
    }
}

/* ── Selection Sort ───────────────────────────────────────────────────── */
void selection_sort(int a[], int n) {
    for (int i=0;i<n-1;i++) {
        int min_idx=i;
        for (int j=i+1;j<n;j++)
            if (a[j]<a[min_idx]) min_idx=j;
        if (min_idx!=i) swap(&a[i],&a[min_idx]);
    }
}

/* ── Insertion Sort ───────────────────────────────────────────────────── */
void insertion_sort(int a[], int n) {
    for (int i=1;i<n;i++) {
        int key=a[i], j=i-1;
        while (j>=0 && a[j]>key) { a[j+1]=a[j]; j--; }
        a[j+1]=key;
    }
}

/* ── Merge Sort ───────────────────────────────────────────────────────── */
void merge(int a[], int l, int m, int r) {
    int n1=m-l+1, n2=r-m;
    int *L=malloc(n1*sizeof(int)), *R=malloc(n2*sizeof(int));
    memcpy(L, a+l, n1*sizeof(int));
    memcpy(R, a+m+1, n2*sizeof(int));
    int i=0,j=0,k=l;
    while (i<n1&&j<n2) a[k++]=(L[i]<=R[j])?L[i++]:R[j++];
    while (i<n1) a[k++]=L[i++];
    while (j<n2) a[k++]=R[j++];
    free(L); free(R);
}
void merge_sort(int a[], int l, int r) {
    if (l<r) {
        int m=l+(r-l)/2;
        merge_sort(a,l,m);
        merge_sort(a,m+1,r);
        merge(a,l,m,r);
    }
}

/* ── Quick Sort ───────────────────────────────────────────────────────── */
int partition(int a[], int lo, int hi) {
    /* Median-of-three pivot */
    int mid=lo+(hi-lo)/2;
    if (a[lo]>a[mid]) swap(&a[lo],&a[mid]);
    if (a[lo]>a[hi])  swap(&a[lo],&a[hi]);
    if (a[mid]>a[hi]) swap(&a[mid],&a[hi]);
    int pivot=a[mid];
    swap(&a[mid],&a[hi-1]);
    int i=lo, j=hi-1;
    while (1) {
        while (a[++i]<pivot);
        while (a[--j]>pivot);
        if (i>=j) break;
        swap(&a[i],&a[j]);
    }
    swap(&a[i],&a[hi-1]);
    return i;
}
void quick_sort(int a[], int lo, int hi) {
    if (hi-lo<2) {
        if (hi>lo && a[lo]>a[hi]) swap(&a[lo],&a[hi]);
        return;
    }
    int p=partition(a,lo,hi);
    quick_sort(a,lo,p-1);
    quick_sort(a,p+1,hi);
}

/* ── Counting Sort ────────────────────────────────────────────────────── */
void counting_sort(int a[], int n) {
    int max=a[0];
    for(int i=1;i<n;i++) if(a[i]>max) max=a[i];
    int *cnt=calloc(max+1,sizeof(int));
    for(int i=0;i<n;i++) cnt[a[i]]++;
    int idx=0;
    for(int i=0;i<=max;i++) while(cnt[i]--) a[idx++]=i;
    free(cnt);
}

/* ── Performance Benchmark ────────────────────────────────────────────── */
double bench(void (*sort)(int*,int), int a[], int n) {
    clock_t s=clock();
    sort(a,n);
    return (double)(clock()-s)/CLOCKS_PER_SEC*1000;
}

/* ── Main ─────────────────────────────────────────────────────────────── */
int main(void) {
    int original[] = {64,25,12,22,11,90,3,47,38,76,55,8,19,42,67};
    int n = sizeof(original)/sizeof(original[0]);
    int a[20];

    printf("=== Sorting Algorithms Demo ===\n");
    print_arr("Original:", original, n);
    printf("\n");

    copy_arr(a,original,n); bubble_sort(a,n);     print_arr("Bubble Sort:",   a,n);
    copy_arr(a,original,n); selection_sort(a,n);  print_arr("Selection Sort:",a,n);
    copy_arr(a,original,n); insertion_sort(a,n);  print_arr("Insertion Sort:",a,n);
    copy_arr(a,original,n); merge_sort(a,0,n-1);  print_arr("Merge Sort:",    a,n);
    copy_arr(a,original,n); quick_sort(a,0,n-1);  print_arr("Quick Sort:",    a,n);
    copy_arr(a,original,n); counting_sort(a,n);   print_arr("Counting Sort:", a,n);

    /* Benchmark on large array */
    printf("\n=== Benchmark (n=10000) ===\n");
    int N=10000;
    int *big=malloc(N*sizeof(int));
    srand(42);
    for(int i=0;i<N;i++) big[i]=rand()%100000;

    int *tmp=malloc(N*sizeof(int));
    void (*sorts[])(int*,int) = {bubble_sort,selection_sort,insertion_sort,counting_sort};
    const char *names[]={"Bubble","Selection","Insertion","Counting"};
    for(int i=0;i<4;i++){
        copy_arr(tmp,big,N);
        printf("%-15s %.3f ms\n",names[i],bench(sorts[i],tmp,N));
    }
    /* Merge/Quick need different signature — inline bench */
    copy_arr(tmp,big,N);
    clock_t s=clock(); merge_sort(tmp,0,N-1);
    printf("%-15s %.3f ms\n","Merge",(double)(clock()-s)/CLOCKS_PER_SEC*1000);
    copy_arr(tmp,big,N);
    s=clock(); quick_sort(tmp,0,N-1);
    printf("%-15s %.3f ms\n","Quick",(double)(clock()-s)/CLOCKS_PER_SEC*1000);

    free(big); free(tmp);
    return 0;
}
