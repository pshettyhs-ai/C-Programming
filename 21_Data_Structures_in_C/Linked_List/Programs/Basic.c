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

typedef struct Node { int data; struct Node *next; } Node;
typedef struct { Node *head; int size; } List;

Node *new_node(int d){Node*n=malloc(sizeof(Node));n->data=d;n->next=NULL;return n;}
void list_init(List *l){l->head=NULL;l->size=0;}

void push_front(List *l, int d){
    Node *n=new_node(d); n->next=l->head; l->head=n; l->size++;
}
void push_back(List *l, int d){
    Node *n=new_node(d);
    if(!l->head){l->head=n;l->size++;return;}
    Node *cur=l->head;
    while(cur->next) cur=cur->next;
    cur->next=n; l->size++;
}
void insert_at(List *l, int pos, int d){
    if(pos==0){push_front(l,d);return;}
    Node *cur=l->head;
    for(int i=0;i<pos-1&&cur;i++) cur=cur->next;
    if(!cur) return;
    Node *n=new_node(d); n->next=cur->next; cur->next=n; l->size++;
}
int  pop_front(List *l){
    if(!l->head) return -1;
    Node *tmp=l->head; int d=tmp->data;
    l->head=l->head->next; free(tmp); l->size--;
    return d;
}
void delete_val(List *l, int d){
    if(!l->head) return;
    if(l->head->data==d){pop_front(l);return;}
    Node *cur=l->head;
    while(cur->next && cur->next->data!=d) cur=cur->next;
    if(cur->next){Node *tmp=cur->next;cur->next=tmp->next;free(tmp);l->size--;}
}
void reverse(List *l){
    Node *prev=NULL,*cur=l->head,*nxt;
    while(cur){nxt=cur->next;cur->next=prev;prev=cur;cur=nxt;}
    l->head=prev;
}
void print_list(const List *l){
    printf("[size=%d] ",l->size);
    for(Node*c=l->head;c;c=c->next) printf("%d→",c->data);
    printf("NULL\n");
}
void free_list(List *l){
    Node *cur=l->head,*nxt;
    while(cur){nxt=cur->next;free(cur);cur=nxt;}
    l->head=NULL; l->size=0;
}

int main(void){
    List l; list_init(&l);
    printf("=== Linked List Operations ===\n");

    for(int i=1;i<=5;i++) push_back(&l,i*10);
    printf("After push_back 10-50: "); print_list(&l);

    push_front(&l,5);
    printf("After push_front 5:    "); print_list(&l);

    insert_at(&l,3,99);
    printf("After insert_at 3,99:  "); print_list(&l);

    delete_val(&l,99);
    printf("After delete_val 99:   "); print_list(&l);

    printf("pop_front: %d\n", pop_front(&l));
    print_list(&l);

    reverse(&l);
    printf("After reverse:         "); print_list(&l);

    free_list(&l);
    return 0;
}
/*
OUTPUT:
=== Linked List Operations ===
After push_back 10-50: [size=5] 10→20→30→40→50→NULL
After push_front 5:    [size=6] 5→10→20→30→40→50→NULL
After insert_at 3,99:  [size=7] 5→10→20→99→30→40→50→NULL
After delete_val 99:   [size=6] 5→10→20→30→40→50→NULL
pop_front: 5
[size=5] 10→20→30→40→50→NULL
After reverse:         [size=5] 50→40→30→20→10→NULL
*/
