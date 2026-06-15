# Theory — Hash Table

> **Author: Pavan Shetty H S**

---

## What is a Hash Table?

A hash table maps keys to values for O(1) average-case lookup. A hash function converts the key to an array index — that index is where the value is stored.

```
Key: "apple"
Hash function → index 7
Array[7] → stores the value associated with "apple"
```

---

## Hash Function

A good hash function distributes keys uniformly across the array. For strings, the djb2 function works well:

```c
unsigned int hash(const char *key, int table_size) {
    unsigned int h = 5381;
    while (*key) h = ((h << 5) + h) + (*key++);   /* h*33 + c */
    return h % table_size;
}
```

---

## Collision Handling — Separate Chaining

Two different keys can hash to the same index — a collision. Separate chaining handles this by storing a linked list at each array slot:

```c
#define BUCKETS 17   /* prime number — better distribution */

typedef struct Entry {
    char         key[50];
    int          value;
    struct Entry *next;
} Entry;

Entry *table[BUCKETS] = {NULL};
```

Every slot is the head of a linked list. Keys that collide share the same list.

---

## Operations

```c
void ht_set(const char *key, int val) {
    int idx = hash(key, BUCKETS);
    /* Check if key already exists — update */
    for (Entry *e = table[idx]; e; e = e->next)
        if (strcmp(e->key, key) == 0) { e->value = val; return; }
    /* New key — prepend to list */
    Entry *e = malloc(sizeof(Entry));
    strncpy(e->key, key, 49);
    e->value = val;
    e->next  = table[idx];
    table[idx] = e;
}

int ht_get(const char *key, int *out) {
    for (Entry *e = table[hash(key, BUCKETS)]; e; e = e->next)
        if (strcmp(e->key, key) == 0) { *out = e->value; return 1; }
    return 0;   /* not found */
}
```

---

## Complexity

| Operation | Average | Worst case (all collide) |
|-----------|---------|--------------------------|
| Insert | O(1) | O(n) |
| Lookup | O(1) | O(n) |
| Delete | O(1) | O(n) |

With a good hash function and load factor (items/buckets) below ~0.75, the average case holds reliably.
