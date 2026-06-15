# Theory — Linked List

> **Author: Pavan Shetty H S**

---

## What is a Linked List?

A linked list is a sequence of nodes where each node contains data and a pointer to the next node. Nodes are not stored contiguously — they are scattered in memory and connected by pointers.

```
Array (contiguous):   [10][20][30][40][50]

Linked List:          10 → 20 → 30 → 40 → 50 → NULL
                       ↑
                      Each arrow is a pointer stored in the node
```

---

## Node Structure

```c
typedef struct Node {
    int          data;
    struct Node *next;    /* self-referential pointer */
} Node;

Node *new_node(int data) {
    Node *n  = malloc(sizeof(Node));
    n->data  = data;
    n->next  = NULL;
    return n;
}
```

---

## Array vs Linked List

| Operation | Array | Linked List |
|-----------|-------|-------------|
| Access element i | O(1) | O(n) — must walk from head |
| Insert at front | O(n) — shift all elements | O(1) — just change head pointer |
| Insert at back | O(1) amortised | O(n) unless tail pointer kept |
| Delete from front | O(n) — shift all | O(1) |
| Search | O(n) | O(n) |
| Memory | Contiguous block | Scattered, each node individually allocated |
| Cache performance | Excellent | Poor — pointer chasing causes cache misses |
| Size flexibility | Fixed (or expensive resize) | Grows freely |

---

## Types of Linked Lists

**Singly linked:** each node has one `next` pointer. Traversal in one direction only.

**Doubly linked:** each node has `next` and `prev` pointers. Can traverse either direction. Deletion is O(1) when you have a pointer to the node.

**Circular linked:** last node's `next` points back to head. No NULL at the end. Used in round-robin scheduling.

---

## Essential Operations

```c
/* Insert at head — O(1) */
void push_front(Node **head, int data) {
    Node *n  = new_node(data);
    n->next  = *head;
    *head    = n;
}

/* Insert at tail — O(n) without tail pointer */
void push_back(Node **head, int data) {
    Node *n = new_node(data);
    if (*head == NULL) { *head = n; return; }
    Node *cur = *head;
    while (cur->next) cur = cur->next;
    cur->next = n;
}

/* Delete by value — O(n) */
void delete_val(Node **head, int val) {
    if (!*head) return;
    if ((*head)->data == val) {
        Node *tmp = *head;
        *head = (*head)->next;
        free(tmp);
        return;
    }
    Node *cur = *head;
    while (cur->next && cur->next->data != val)
        cur = cur->next;
    if (cur->next) {
        Node *tmp = cur->next;
        cur->next = tmp->next;
        free(tmp);
    }
}

/* Reverse in place — O(n) */
void reverse(Node **head) {
    Node *prev = NULL, *cur = *head, *next;
    while (cur) {
        next      = cur->next;
        cur->next = prev;
        prev      = cur;
        cur       = next;
    }
    *head = prev;
}
```

---

## Common Mistakes

```c
/* Mistake 1: Memory leak — forgetting to free */
Node *n = *head;
*head = (*head)->next;
/* forgot: free(n); */

/* Mistake 2: Losing the list */
*head = (*head)->next;  /* head now points to second node */
/* first node is leaked — no pointer to it anymore */
/* always save a temp pointer before changing head */

/* Mistake 3: Accessing next on NULL */
while (cur->next != NULL)  /* correct */
while (cur != NULL)        /* check cur, not cur->next */
    cur = cur->next;       /* before accessing cur->next */
```
