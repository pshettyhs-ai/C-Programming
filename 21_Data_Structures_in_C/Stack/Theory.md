# Theory — Stack

> **Author: Pavan Shetty H S**

---

## What is a Stack?

A stack is a LIFO (Last In, First Out) data structure. The last item you push is the first item you pop. Think of a stack of plates — you add to the top and remove from the top.

```
PUSH 10 → [10]
PUSH 20 → [10][20]
PUSH 30 → [10][20][30]
POP    → returns 30, stack: [10][20]
POP    → returns 20, stack: [10]
```

---

## Two Implementations

**Array-based:** simple, fast, but limited to a fixed size.
```c
#define MAX 100
typedef struct { int data[MAX]; int top; } Stack;

void push(Stack *s, int v) { if (s->top < MAX-1) s->data[++s->top] = v; }
int  pop(Stack *s)         { return s->top >= 0 ? s->data[s->top--] : -1; }
int  peek(Stack *s)        { return s->top >= 0 ? s->data[s->top]   : -1; }
int  empty(Stack *s)       { return s->top == -1; }
```

**Linked-list based:** no size limit, slight overhead per node.
```c
typedef struct Node { int data; struct Node *next; } SNode;

void lstack_push(SNode **top, int v) {
    SNode *n = malloc(sizeof(SNode));
    n->data = v; n->next = *top; *top = n;
}
int lstack_pop(SNode **top) {
    if (!*top) return -1;
    int v = (*top)->data;
    SNode *tmp = *top; *top = (*top)->next; free(tmp);
    return v;
}
```

---

## Real Uses of Stacks

| Use case | How stack helps |
|----------|----------------|
| Function call management | CPU uses a stack for return addresses and local variables |
| Balanced bracket checking | Push open brackets, pop and compare on close bracket |
| Undo/redo in text editors | Each action pushed; undo pops and reverses |
| Expression evaluation | Operator stack, operand stack |
| Decimal to binary | Remainders in reverse order |
| Backtracking (DFS, maze) | Store path for backtrack |

---

## Complexity

| Operation | Array Stack | Linked Stack |
|-----------|-------------|--------------|
| Push | O(1) | O(1) |
| Pop | O(1) | O(1) |
| Peek | O(1) | O(1) |
| Space | O(n) fixed | O(n) dynamic |
