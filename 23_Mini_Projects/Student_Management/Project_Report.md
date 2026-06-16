# Project Report — Student Management System

> **Author: Pavan Shetty H S**

---

## Overview

This was one of the first complete projects I built after finishing the core C chapters. The goal was to combine structures, file I/O, sorting, and menu-driven programming into one working application — not just isolated exercises.

The system manages student records with full CRUD operations and persists data to a binary file so records survive between runs.

---

## Data Model

```c
typedef struct {
    int   roll;           /* unique identifier — no two students share this */
    char  name[50];       /* full name */
    char  branch[20];     /* department: CSE, ECE, ME, etc. */
    int   semester;       /* 1 to 8 */
    float gpa;            /* 0.0 to 10.0 */
    int   active;         /* 1 = exists, 0 = soft-deleted */
} Student;
```

I use a soft delete (setting `active = 0`) rather than physically removing records from the file. This is simpler and preserves the file's structure — shifting records on disk every delete would be expensive.

---

## Features Implemented

| Feature | How it works |
|---------|-------------|
| Add student | Validates roll uniqueness, GPA range, semester range before inserting |
| View all | Iterates active records, prints formatted table |
| Search | Linear scan for matching roll number |
| Update | Locate by roll, modify selected fields, save |
| Delete | Set `active = 0`, no physical removal |
| Sort | Builds active-only temp array, bubble sorts by chosen field |
| Statistics | Single pass: sum, min, max, grade distribution bar chart |
| Persistence | `fwrite`/`fread` of entire struct array to binary file |

---

## What I Learned Building This

- **Soft delete** is much simpler than shifting records in a flat binary file
- **Binary file I/O** with `fwrite(struct_array, sizeof(struct), count, fp)` is fast and exact
- **Input validation** must happen before writing — garbage in, garbage out
- **Formatted output** with `printf("%-25s %5d %.2f\n", ...)` is worth the effort

---

## Complexity Analysis

| Operation | Time | Space |
|-----------|------|-------|
| Add | O(n) — scan for duplicate roll | O(1) |
| View all | O(n) | O(1) |
| Search | O(n) — linear scan | O(1) |
| Sort | O(n²) — bubble sort | O(n) temp array |
| Statistics | O(n) — single pass | O(1) |
| Save to file | O(n) | O(1) |
| Load from file | O(n) | O(n) |

For this project size (max ~100 records), O(n²) sort is perfectly fine. For thousands of records, I would switch to merge sort or use `qsort`.

---

## How to Compile and Run

```bash
gcc Source_Code/main.c -o sms
./sms
```

Data is saved to `/tmp/students_sms.dat`. To reset, delete that file.

---

## Possible Improvements

- Replace bubble sort with `qsort` for larger datasets
- Add pagination for viewing many records
- Support searching by name substring, not just exact roll number
- Export records to a human-readable CSV file

---

*— Pavan Shetty H S*
