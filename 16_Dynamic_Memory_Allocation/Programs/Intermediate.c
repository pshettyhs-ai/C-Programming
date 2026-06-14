/*
 * ===================================================================
 *  File    : Intermediate.c
 *  Topic   : 16 Dynamic Memory Allocation
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

/* Dynamic string builder */
typedef struct {
    char  *buf;
    size_t len;
    size_t cap;
} StringBuilder;

void sb_init(StringBuilder *sb) { sb->buf=malloc(64); sb->buf[0]='\0'; sb->len=0; sb->cap=64; }
void sb_append(StringBuilder *sb, const char *s) {
    size_t slen=strlen(s);
    while(sb->len+slen+1>sb->cap){
        sb->cap*=2;
        sb->buf=realloc(sb->buf,sb->cap);
    }
    memcpy(sb->buf+sb->len,s,slen+1);
    sb->len+=slen;
}
void sb_free(StringBuilder *sb){ free(sb->buf); sb->buf=NULL; sb->len=sb->cap=0; }

/* Dynamic matrix */
int **create_matrix(int rows, int cols) {
    int **m = malloc(rows * sizeof(int*));
    for(int i=0;i<rows;i++) { m[i]=calloc(cols,sizeof(int)); }
    return m;
}
void free_matrix(int **m, int rows){ for(int i=0;i<rows;i++) free(m[i]); free(m); }
void fill_matrix(int **m, int r, int c){for(int i=0;i<r;i++) for(int j=0;j<c;j++) m[i][j]=i*c+j+1;}
void print_matrix(int **m, int r, int c){for(int i=0;i<r;i++){for(int j=0;j<c;j++)printf("%4d",m[i][j]);printf("\n");}}

/* Dynamic array with operations */
typedef struct { int *data; int size; int cap; } Vec;
void vec_init(Vec *v){ v->data=malloc(4*sizeof(int)); v->size=0; v->cap=4; }
void vec_push(Vec *v, int x){
    if(v->size==v->cap){ v->cap*=2; v->data=realloc(v->data,v->cap*sizeof(int)); }
    v->data[v->size++]=x;
}
int vec_pop(Vec *v){ return v->size>0?v->data[--v->size]:-1; }
void vec_free(Vec *v){ free(v->data); v->data=NULL; v->size=v->cap=0; }

int main(void) {
    printf("=== String Builder (dynamic realloc) ===\n");
    StringBuilder sb; sb_init(&sb);
    const char *words[]={"Hello","", " ","World","!"," Cap=",NULL};
    sb_append(&sb,"Hello");
    sb_append(&sb,", ");
    sb_append(&sb,"World");
    sb_append(&sb,"! Dynamic string builder in C.");
    printf("String: '%s'\n", sb.buf);
    printf("Length: %zu, Capacity: %zu\n", sb.len, sb.cap);
    sb_free(&sb);

    printf("\n=== Dynamic Matrix ===\n");
    int **mat = create_matrix(3,4);
    fill_matrix(mat,3,4);
    print_matrix(mat,3,4);
    free_matrix(mat,3);

    printf("\n=== Dynamic Vector (auto-grow) ===\n");
    Vec v; vec_init(&v);
    printf("Pushing 1-12:\n");
    for(int i=1;i<=12;i++){
        vec_push(&v,i*i);
        printf("  [cap=%d size=%d] last=%d\n",v.cap,v.size,v.data[v.size-1]);
    }
    printf("Popping: ");
    while(v.size>0) printf("%d ",vec_pop(&v));
    printf("\n");
    vec_free(&v);

    return 0;
}
