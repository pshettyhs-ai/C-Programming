# Theory — Queue

> **Author: Pavan Shetty H S**

---

## What is a Queue?

A queue is a FIFO (First In, First Out) data structure. The first item enqueued is the first item dequeued. Think of a queue at a ticket counter.

```
ENQUEUE 10 → front:[10]:rear
ENQUEUE 20 → front:[10][20]:rear
ENQUEUE 30 → front:[10][20][30]:rear
DEQUEUE    → returns 10, front:[20][30]:rear
```

---

## Circular Array Queue

A naive array queue wastes space as elements are dequeued from the front. A circular queue fixes this by wrapping around:

```c
#define CAP 8
typedef struct {
    int data[CAP];
    int front, rear, size;
} Queue;

void enqueue(Queue *q, int v) {
    if (q->size == CAP) { printf("Full\n"); return; }
    q->data[q->rear] = v;
    q->rear  = (q->rear  + 1) % CAP;   /* wrap around */
    q->size++;
}

int dequeue(Queue *q) {
    if (q->size == 0) { printf("Empty\n"); return -1; }
    int v    = q->data[q->front];
    q->front = (q->front + 1) % CAP;   /* wrap around */
    q->size--;
    return v;
}
```

The key insight: `(index + 1) % CAPACITY` wraps from the last position back to 0.

---

## Real Uses

| Use case | Why queue fits |
|----------|---------------|
| CPU process scheduling | Processes served in arrival order |
| Printer job queue | First document sent prints first |
| BFS (graph traversal) | Process nodes level by level |
| Network packet buffers | Packets processed in order received |
| Producer-consumer problems | Buffer between fast producer and slow consumer |
