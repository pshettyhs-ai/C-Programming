# Theory — Searching Algorithms

> **Author: Pavan Shetty H S**

---

## Linear Search — O(n)

Check every element from the start until you find the target or reach the end.

```c
int linear_search(int arr[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (arr[i] == key) return i;
    return -1;
}
```

Works on any array — sorted or unsorted. Inefficient for large arrays.

---

## Binary Search — O(log n)

Requires sorted array. Repeatedly halves the search space.

```c
int binary_search(int arr[], int n, int key) {
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;   /* not (lo+hi)/2 — avoids overflow */
        if (arr[mid] == key) return mid;
        if (arr[mid] <  key) lo = mid + 1;
        else                 hi = mid - 1;
    }
    return -1;
}
```

Each step eliminates half the remaining elements. For n=1,000,000, at most 20 comparisons.

Why `lo + (hi-lo)/2` instead of `(lo+hi)/2`? If lo and hi are both large, `lo+hi` can overflow a 32-bit int. The first form avoids this.

---

## Jump Search — O(√n)

Jump forward by √n steps until you overshoot, then linear search backward.

Useful when jumping backward is cheaper than jumping forward (like in magnetic tape storage).

---

## Interpolation Search — O(log log n) for uniform data

Like binary search but estimates where the target is likely to be based on its value, not just the midpoint.

```c
int pos = lo + ((hi - lo) * (key - arr[lo])) / (arr[hi] - arr[lo]);
```

Works best on uniformly distributed sorted data. Degrades to O(n) on non-uniform data.

---

## Which to Use?

| Situation | Algorithm |
|-----------|-----------|
| Unsorted array | Linear search |
| Sorted array, general case | Binary search |
| Sorted, uniformly distributed data | Interpolation search |
| External storage with seek cost | Jump search |
| Need first/last occurrence of duplicate | Modified binary search |
