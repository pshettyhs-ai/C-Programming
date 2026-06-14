/*
 * ===================================================================
 *  File    : Basic.c
 *  Topic   : 16 Dynamic Memory Allocation
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

/* Dynamic array with grow capability */
typedef struct {
    int  *data;
    int   size;
    int   capacity;
} DynArray;

DynArray *da_create(int initial_capacity) {
    DynArray *da = malloc(sizeof(DynArray));
    da->data     = malloc(initial_capacity * sizeof(int));
    da->size     = 0;
    da->capacity = initial_capacity;
    return da;
}

void da_push(DynArray *da, int val) {
    if (da->size == da->capacity) {
        da->capacity *= 2;
        int *tmp = realloc(da->data, da->capacity * sizeof(int));
        if (!tmp) { free(da->data); exit(1); }
        da->data = tmp;
        printf("  [resized to capacity %d]\n", da->capacity);
    }
    da->data[da->size++] = val;
}

void da_print(const DynArray *da) {
    printf("DynArray[%d/%d]: ", da->size, da->capacity);
    for(int i=0;i<da->size;i++) printf("%d ", da->data[i]);
    printf("\n");
}

void da_free(DynArray *da) {
    free(da->data);
    free(da);
}

int main(void) {
    /* Basic malloc/free */
    printf("=== malloc / free ===\n");
    int n = 5;
    int *arr = malloc(n * sizeof(*arr));
    if(!arr){fprintf(stderr,"malloc failed\n");return 1;}
    for(int i=0;i<n;i++) arr[i]=(i+1)*10;
    printf("arr: ");
    for(int i=0;i<n;i++) printf("%d ", arr[i]);
    printf("\n");
    free(arr); arr=NULL;

    /* calloc — zero initialized */
    printf("\n=== calloc (zero-initialized) ===\n");
    int *zeros = calloc(5, sizeof(int));
    printf("calloc: ");
    for(int i=0;i<5;i++) printf("%d ", zeros[i]);
    printf("\n");
    free(zeros);

    /* realloc — dynamic resize */
    printf("\n=== realloc ===\n");
    int *buf = malloc(3 * sizeof(int));
    buf[0]=1; buf[1]=2; buf[2]=3;
    printf("Before realloc: ");
    for(int i=0;i<3;i++) printf("%d ",buf[i]); printf("\n");

    int *tmp = realloc(buf, 6 * sizeof(int));
    if(!tmp){free(buf);return 1;}
    buf=tmp;
    buf[3]=4; buf[4]=5; buf[5]=6;
    printf("After realloc:  ");
    for(int i=0;i<6;i++) printf("%d ",buf[i]); printf("\n");
    free(buf);

    /* Dynamic array with auto-grow */
    printf("\n=== Dynamic Array (auto-grow) ===\n");
    DynArray *da = da_create(4);
    for(int i=1;i<=10;i++) {
        da_push(da,i*i);
        da_print(da);
    }
    da_free(da);

    return 0;
}
