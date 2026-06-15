# Theory — Binary Search Tree

> **Author: Pavan Shetty H S**

---

## What is a BST?

A Binary Search Tree is a binary tree with one rule: for every node, all values in its left subtree are smaller, and all values in its right subtree are larger.

```
         50
        /  \
      30    70
     /  \  /  \
   20   40 60  80
```

This property makes search fast — at each node you eliminate half the remaining tree.

---

## Node Structure

```c
typedef struct Node {
    int          data;
    struct Node *left;
    struct Node *right;
} Node;
```

---

## Core Operations

```c
/* Insert — O(log n) average, O(n) worst case (skewed tree) */
Node *insert(Node *root, int data) {
    if (!root) return new_node(data);
    if (data < root->data)       root->left  = insert(root->left,  data);
    else if (data > root->data)  root->right = insert(root->right, data);
    return root;   /* duplicate: do nothing */
}

/* Search — O(log n) average */
Node *search(Node *root, int data) {
    if (!root || root->data == data) return root;
    if (data < root->data) return search(root->left,  data);
    return                        search(root->right, data);
}
```

---

## Tree Traversals

All three traversals are recursive and visit every node exactly once — O(n):

```c
void inorder(Node *root) {         /* Left → Root → Right */
    if (!root) return;             /* gives SORTED output for BST */
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(Node *root) {        /* Root → Left → Right */
    if (!root) return;             /* useful for copying a tree */
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root) {       /* Left → Right → Root */
    if (!root) return;             /* useful for deleting a tree */
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
```

---

## Complexity

| Operation | Average | Worst case (skewed tree) |
|-----------|---------|--------------------------|
| Search | O(log n) | O(n) |
| Insert | O(log n) | O(n) |
| Delete | O(log n) | O(n) |
| Traversal | O(n) | O(n) |

The worst case happens when you insert already-sorted data — the tree becomes a linked list. AVL trees and Red-Black trees fix this by self-balancing.
