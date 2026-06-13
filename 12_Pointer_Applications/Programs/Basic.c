/*
 * ===================================================================
 *  File    : Basic.c
 *  Topic   : 12 Pointer Applications
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

/* ── Function Pointers ────────────────────────────────────────────────── */
int add(int a,int b){return a+b;}
int sub(int a,int b){return a-b;}
int mul(int a,int b){return a*b;}
int dvd(int a,int b){return b?a/b:0;}

typedef int (*BinOp)(int,int);

void demo_function_pointers(void) {
    printf("=== Function Pointers ===\n");
    BinOp ops[]  = {add,sub,mul,dvd};
    const char *names[] = {"add","sub","mul","div"};
    int a=12, b=4;
    for(int i=0;i<4;i++)
        printf("%s(%d,%d) = %d\n", names[i], a, b, ops[i](a,b));
}

/* ── Void Pointer Generic Swap ────────────────────────────────────────── */
void generic_swap(void *a, void *b, size_t sz) {
    unsigned char tmp[256];
    memcpy(tmp, a, sz);
    memcpy(a,   b, sz);
    memcpy(b,  tmp, sz);
}

void demo_void_pointer(void) {
    printf("\n=== Void Pointer (Generic Swap) ===\n");
    int x=10,y=20;
    printf("Before: x=%d y=%d\n",x,y);
    generic_swap(&x,&y,sizeof(int));
    printf("After:  x=%d y=%d\n",x,y);

    double p=1.111,q=9.999;
    printf("Before: p=%.3f q=%.3f\n",p,q);
    generic_swap(&p,&q,sizeof(double));
    printf("After:  p=%.3f q=%.3f\n",p,q);
}

/* ── Double Pointer: Allocate Array Inside Function ───────────────────── */
void alloc_fill(int **arr, int n) {
    *arr = malloc(n * sizeof(int));
    for(int i=0;i<n;i++) (*arr)[i]=i*i;
}

void demo_double_pointer(void) {
    printf("\n=== Double Pointer ===\n");
    int *arr=NULL;
    alloc_fill(&arr, 6);
    printf("Squares: ");
    for(int i=0;i<6;i++) printf("%d ", arr[i]);
    printf("\n");
    free(arr); arr=NULL;
}

/* ── qsort with function pointer ──────────────────────────────────────── */
int cmp_asc(const void *a,const void *b){return *(int*)a-*(int*)b;}
int cmp_desc(const void *a,const void *b){return *(int*)b-*(int*)a;}

void demo_qsort(void) {
    printf("\n=== qsort with Function Pointers ===\n");
    int arr[]={5,2,8,1,9,3,7,4,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    qsort(arr,n,sizeof(int),cmp_asc);
    printf("Asc:  ");for(int i=0;i<n;i++)printf("%d ",arr[i]);printf("\n");
    qsort(arr,n,sizeof(int),cmp_desc);
    printf("Desc: ");for(int i=0;i<n;i++)printf("%d ",arr[i]);printf("\n");
}

int main(void){
    demo_function_pointers();
    demo_void_pointer();
    demo_double_pointer();
    demo_qsort();
    return 0;
}
