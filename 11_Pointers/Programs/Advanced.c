/*
 * ===================================================================
 *  File    : Advanced.c
 *  Topic   : 11 Pointers
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

/* ── 1. Function pointer table (command dispatch) ─────────────────────── */
typedef void (*CmdFunc)(const char *arg);

void cmd_print(const char *a)  { printf("PRINT: %s\n", a); }
void cmd_upper(const char *a)  {
    char buf[100]; strncpy(buf,a,99);
    for(char*p=buf;*p;p++) if(*p>='a'&&*p<='z') *p-=32;
    printf("UPPER: %s\n", buf);
}
void cmd_len(const char *a)    { printf("LENGTH: %zu\n", strlen(a)); }
void cmd_rev(const char *a)    {
    char buf[100]; strncpy(buf,a,99); int n=strlen(buf);
    for(int i=0,j=n-1;i<j;i++,j--){char t=buf[i];buf[i]=buf[j];buf[j]=t;}
    printf("REVERSED: %s\n", buf);
}

typedef struct { const char *name; CmdFunc func; } Command;
Command dispatch[] = {
    {"print", cmd_print}, {"upper", cmd_upper},
    {"len",   cmd_len},   {"rev",   cmd_rev},
};

void dispatch_cmd(const char *cmd, const char *arg) {
    int n = sizeof(dispatch)/sizeof(dispatch[0]);
    for (int i=0;i<n;i++)
        if (strcmp(dispatch[i].name,cmd)==0) { dispatch[i].func(arg); return; }
    printf("Unknown command: %s\n", cmd);
}

/* ── 2. Generic linked list using void pointers ───────────────────────── */
typedef struct GNode { void *data; struct GNode *next; } GNode;

GNode *gnode_new(void *data, size_t size) {
    GNode *n = malloc(sizeof(GNode));
    n->data = malloc(size);
    memcpy(n->data, data, size);
    n->next = NULL;
    return n;
}
void glist_push(GNode **head, void *data, size_t size) {
    GNode *n = gnode_new(data, size);
    n->next = *head; *head = n;
}
void glist_print_int(GNode *head) {
    for(GNode *cur=head; cur; cur=cur->next)
        printf("%d ", *(int*)cur->data);
    printf("\n");
}
void glist_free(GNode *head) {
    while(head) { GNode *t=head->next; free(head->data); free(head); head=t; }
}

/* ── 3. Memory pool allocator ─────────────────────────────────────────── */
#define POOL_SIZE 4096
typedef struct {
    unsigned char buf[POOL_SIZE];
    size_t used;
} Pool;

void  pool_init(Pool *p) { p->used = 0; }
void *pool_alloc(Pool *p, size_t size) {
    /* 8-byte alignment */
    size_t aligned = (size + 7) & ~7u;
    if (p->used + aligned > POOL_SIZE) return NULL;
    void *ptr = p->buf + p->used;
    p->used += aligned;
    return ptr;
}
void pool_reset(Pool *p) { p->used = 0; }

/* ── 4. Pointer-based merge sort ──────────────────────────────────────── */
typedef struct LNode { int val; struct LNode *next; } LNode;

LNode *lnew(int v){ LNode*n=malloc(sizeof(LNode));n->val=v;n->next=NULL;return n; }

LNode *merge_lists(LNode *a, LNode *b) {
    if (!a) return b;
    if (!b) return a;
    if (a->val <= b->val) { a->next = merge_lists(a->next, b); return a; }
    else { b->next = merge_lists(a, b->next); return b; }
}

void split_list(LNode *head, LNode **a, LNode **b) {
    LNode *slow=head, *fast=head->next;
    while (fast && fast->next) { slow=slow->next; fast=fast->next->next; }
    *a=head; *b=slow->next; slow->next=NULL;
}

LNode *mergesort_list(LNode *head) {
    if (!head || !head->next) return head;
    LNode *a, *b;
    split_list(head, &a, &b);
    return merge_lists(mergesort_list(a), mergesort_list(b));
}

void lprint(LNode *n){ while(n){printf("%d ",n->val);n=n->next;}printf("\n"); }
void lfree(LNode *n){ while(n){LNode*t=n->next;free(n);n=t;} }

int main(void) {
    /* 1. Dispatch table */
    printf("=== Function Pointer Dispatch Table ===\n");
    dispatch_cmd("print", "Hello C!");
    dispatch_cmd("upper", "hello world");
    dispatch_cmd("len",   "programming");
    dispatch_cmd("rev",   "abcdef");
    dispatch_cmd("quit",  "");

    /* 2. Generic list */
    printf("\n=== Generic Linked List (void*) ===\n");
    GNode *glist = NULL;
    for(int i=5;i>=1;i--) glist_push(&glist,&i,sizeof(int));
    printf("List: "); glist_print_int(glist);
    glist_free(glist);

    /* 3. Memory pool */
    printf("\n=== Memory Pool Allocator ===\n");
    Pool pool; pool_init(&pool);
    int   *a = pool_alloc(&pool, 5*sizeof(int));
    float *b = pool_alloc(&pool, 3*sizeof(float));
    char  *c = pool_alloc(&pool, 20);
    if (a && b && c) {
        for(int i=0;i<5;i++) a[i]=i*10;
        b[0]=1.1f; b[1]=2.2f; b[2]=3.3f;
        strcpy(c,"Pool allocated!");
        printf("ints:   "); for(int i=0;i<5;i++) printf("%d ",a[i]); printf("\n");
        printf("floats: %.1f %.1f %.1f\n",b[0],b[1],b[2]);
        printf("string: %s\n",c);
        printf("Pool used: %zu/%d bytes\n", pool.used, POOL_SIZE);
    }
    pool_reset(&pool);
    printf("Pool reset. Used: %zu\n", pool.used);

    /* 4. Merge sort on linked list */
    printf("\n=== Linked List Merge Sort ===\n");
    LNode *list = NULL;
    int vals[]={5,1,8,3,9,2,7,4,6};
    for(int i=0;i<9;i++){LNode*n=lnew(vals[i]);n->next=list;list=n;}
    printf("Before: "); lprint(list);
    list=mergesort_list(list);
    printf("After:  "); lprint(list);
    lfree(list);

    return 0;
}
