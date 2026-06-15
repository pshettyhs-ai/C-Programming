# 21 — Data Structures in C

> **Author: Pavan Shetty H S**

---

## Why Implement Data Structures Yourself?

Libraries exist for all of these. But implementing them from scratch in C teaches you things you cannot learn any other way — how pointers actually build connections between memory locations, how dynamic allocation underlies every "automatic" container in higher-level languages, and how algorithmic complexity shows up as real runtime differences.

Every data structure here is built from the ground up. No shortcuts.

---

## What's Covered

| Folder | Data Structure | Key Operations |
|--------|---------------|----------------|
| `Linked_List/` | Singly and doubly linked list | Insert, delete, search, reverse |
| `Stack/` | Array-based and linked-list stack | Push, pop, peek — balanced brackets |
| `Queue/` | Circular array queue | Enqueue, dequeue, circular index |
| `Tree/` | Binary Search Tree | Insert, search, delete, all traversals |
| `Hash_Table/` | Separate chaining hash table | Insert, lookup, delete — word frequency |
| `Sorting/` | 6 sorting algorithms | Bubble, selection, insertion, merge, quick, counting |
| `Searching/` | 4 searching algorithms | Linear, binary, jump, interpolation |

---

## Complexity Quick Reference

| Structure | Access | Search | Insert | Delete |
|-----------|--------|--------|--------|--------|
| Array | O(1) | O(n) | O(n) | O(n) |
| Linked List | O(n) | O(n) | O(1) head | O(1) with ptr |
| Stack | O(1) top | O(n) | O(1) | O(1) |
| Queue | O(1) front | O(n) | O(1) | O(1) |
| BST (avg) | O(log n) | O(log n) | O(log n) | O(log n) |
| Hash Table | O(1) avg | O(1) avg | O(1) avg | O(1) avg |

---

## Recommended Order

1. Linked List — builds the pointer manipulation skills everything else needs
2. Stack and Queue — straightforward, rewarding to build
3. Tree — recursion-heavy, very satisfying once it works
4. Hash Table — teaches hashing and collision handling
5. Sorting — implement all of them, benchmark them, observe the differences
6. Searching — binary search and its variants

---

*— Pavan Shetty H S*
