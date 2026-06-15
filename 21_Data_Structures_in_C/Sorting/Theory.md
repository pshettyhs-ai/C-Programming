# Theory — Sorting Algorithms

> **Author: Pavan Shetty H S**

---

## Why Learn Multiple Sorting Algorithms?

Different algorithms are better for different situations. Knowing why — not just how they work — is what interviewers want to see.

---

## The Six Algorithms I Implemented

### Bubble Sort — O(n²)
Repeatedly compares adjacent elements and swaps them if out of order. The largest unsorted element "bubbles" to the end each pass.

```c
void bubble_sort(int a[], int n) {
    for (int i = 0; i < n-1; i++) {
        int swapped = 0;
        for (int j = 0; j < n-i-1; j++)
            if (a[j] > a[j+1]) { swap(&a[j], &a[j+1]); swapped = 1; }
        if (!swapped) break;   /* already sorted — O(n) best case */
    }
}
```

Use when: small arrays, or when you need to detect an already-sorted array.

---

### Selection Sort — O(n²) always
Finds the minimum of the unsorted portion and swaps it to its correct position.

```c
void selection_sort(int a[], int n) {
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++)
            if (a[j] < a[min_idx]) min_idx = j;
        if (min_idx != i) swap(&a[i], &a[min_idx]);
    }
}
```

Use when: minimising the number of swaps matters (swaps are expensive).

---

### Insertion Sort — O(n²) worst, O(n) best
Builds the sorted array one element at a time, inserting each into its correct position.

```c
void insertion_sort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i], j = i-1;
        while (j >= 0 && a[j] > key) { a[j+1] = a[j]; j--; }
        a[j+1] = key;
    }
}
```

Use when: nearly-sorted data, or small arrays (used in practice as a base case for merge/quick sort).

---

### Merge Sort — O(n log n) guaranteed
Divide: split array in half recursively. Conquer: merge two sorted halves.

Stable, predictable O(n log n) always. Costs O(n) extra memory for the merge.

Use when: guaranteed performance needed, stability matters, sorting linked lists.

---

### Quick Sort — O(n log n) average, O(n²) worst
Pick a pivot, partition elements smaller-than and larger-than the pivot, recurse on each side.

Fastest in practice for random data. Worst case (already sorted + bad pivot) is O(n²). Median-of-three pivot selection largely avoids the worst case.

Use when: general-purpose sorting, in-place sorting needed.

---

### Counting Sort — O(n+k)
Not comparison-based. Count occurrences of each value, then reconstruct the sorted array.

Faster than O(n log n) when k (value range) is small compared to n.

Use when: sorting integers in a known small range (like exam scores 0-100).

---

## Complexity Summary

| Algorithm | Best | Average | Worst | Space | Stable |
|-----------|------|---------|-------|-------|--------|
| Bubble | O(n) | O(n²) | O(n²) | O(1) | ✅ |
| Selection | O(n²) | O(n²) | O(n²) | O(1) | ❌ |
| Insertion | O(n) | O(n²) | O(n²) | O(1) | ✅ |
| Merge | O(n log n) | O(n log n) | O(n log n) | O(n) | ✅ |
| Quick | O(n log n) | O(n log n) | O(n²) | O(log n) | ❌ |
| Counting | O(n+k) | O(n+k) | O(n+k) | O(k) | ✅ |
