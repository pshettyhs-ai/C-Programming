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

#define CAP 8
typedef struct { int data[CAP]; int front,rear,size; } Queue;

void q_init(Queue *q){q->front=q->rear=q->size=0;}
int  q_empty(Queue *q){return q->size==0;}
int  q_full(Queue *q){return q->size==CAP;}

void enqueue(Queue *q, int v){
    if(q_full(q)){printf("Queue full!\n");return;}
    q->data[q->rear]= v;
    q->rear = (q->rear+1)%CAP;
    q->size++;
}
int dequeue(Queue *q){
    if(q_empty(q)){printf("Queue empty!\n");return -1;}
    int v=q->data[q->front];
    q->front=(q->front+1)%CAP;
    q->size--;
    return v;
}
void q_print(Queue *q){
    printf("[size=%d] front→",q->size);
    for(int i=0;i<q->size;i++) printf("%d ",q->data[(q->front+i)%CAP]);
    printf("←rear\n");
}

int main(void){
    Queue q; q_init(&q);
    printf("=== Circular Queue ===\n");
    for(int i=1;i<=5;i++){enqueue(&q,i*10);q_print(&q);}
    printf("Dequeue: %d\n",dequeue(&q)); q_print(&q);
    printf("Dequeue: %d\n",dequeue(&q)); q_print(&q);
    enqueue(&q,60); enqueue(&q,70); q_print(&q);
    while(!q_empty(&q)) printf("Dequeue: %d\n",dequeue(&q));
    return 0;
}
