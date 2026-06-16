# Project Report — File Compressor

> **Author: Pavan Shetty H S**

---

## Overview

File Compressor is a console-based C application that demonstrates practical use of multiple C programming concepts together. Building this helped me understand how theoretical concepts become working software.

---

## Key Design Decisions

- Used structures to model the core data entities cleanly
- File I/O with binary mode for fast, exact persistence
- Menu-driven interface using do-while loop
- Input validation before every write operation

---

## Main Concepts Applied

| Concept | How it is used |
|---------|---------------|
| Structures | Core data model |
| File I/O | Data persistence between runs |
| Arrays / Linked Lists | In-memory data storage |
| Functions | Each operation in its own function |
| String handling | Name search and display |
| Sorting | List ordering features |

---

## What I Learned

Every project teaches something that isolated exercises cannot. The main lesson here was integrating file I/O with in-memory structures reliably — making sure saves always happen before the function returns, and that reads handle missing files gracefully.

---

## How to Compile

```bash
gcc Source_Code/main.c -o program
./program
```

---

## Possible Improvements

- Replace linear search with binary search on sorted data
- Add undo functionality for delete operations
- Export data to CSV for use in spreadsheets
- Add pagination for long lists

---

*— Pavan Shetty H S*
