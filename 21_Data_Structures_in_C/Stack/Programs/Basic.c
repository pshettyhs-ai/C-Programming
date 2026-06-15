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

/* ── Array-based Stack ────────────────────────────────────────────────── */
#define MAX 100
typedef struct { int data[MAX]; int top; } ArrayStack;

void as_init(ArrayStack *s){s->top=-1;}
int  as_empty(ArrayStack *s){return s->top==-1;}
int  as_full(ArrayStack *s){return s->top==MAX-1;}
void as_push(ArrayStack *s,int v){if(!as_full(s))s->data[++s->top]=v;}
int  as_pop(ArrayStack *s){return as_empty(s)?-1:s->data[s->top--];}
int  as_peek(ArrayStack *s){return as_empty(s)?-1:s->data[s->top];}

/* ── Stack Applications ───────────────────────────────────────────────── */

/* Balanced parentheses checker */
int is_balanced(const char *expr){
    ArrayStack s; as_init(&s);
    for(int i=0;expr[i];i++){
        char c=expr[i];
        if(c=='('||c=='['||c=='{') as_push(&s,c);
        else if(c==')'||c==']'||c=='}'){
            if(as_empty(&s)) return 0;
            int top=as_pop(&s);
            if((c==')'&&top!='(')||(c==']'&&top!='[')||(c=='}'&&top!='{')) return 0;
        }
    }
    return as_empty(&s);
}

/* Decimal to Binary */
void dec_to_bin(int n){
    ArrayStack s; as_init(&s);
    if(n==0){printf("0");return;}
    while(n){as_push(&s,n%2);n/=2;}
    while(!as_empty(&s)) printf("%d",as_pop(&s));
}

int main(void){
    ArrayStack s; as_init(&s);
    printf("=== Array Stack ===\n");
    for(int i=1;i<=5;i++){as_push(&s,i*10);printf("Push %d\n",i*10);}
    printf("Peek: %d\n",as_peek(&s));
    while(!as_empty(&s)) printf("Pop: %d\n",as_pop(&s));

    printf("\n=== Balanced Parentheses ===\n");
    const char *tests[]={"({[]})", "([)]", "{{{}}}", "(((" };
    for(int i=0;i<4;i++)
        printf("%-12s → %s\n",tests[i],is_balanced(tests[i])?"Balanced":"NOT Balanced");

    printf("\n=== Decimal to Binary ===\n");
    int nums[]={0,1,10,42,255};
    for(int i=0;i<5;i++){printf("%3d = ",nums[i]);dec_to_bin(nums[i]);printf("\n");}

    return 0;
}
