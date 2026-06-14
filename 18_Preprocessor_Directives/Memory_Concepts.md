# Memory Concepts — Preprocessor Directives

## Variable Storage

All variables related to this topic follow C's memory model:

| Storage | Location | Initialized | Lifetime |
|---------|----------|-------------|----------|
| Local variables | Stack | Garbage | Block |
| Global variables | Data/BSS | Zero | Program |
| Dynamic allocations | Heap | Garbage | Until free() |
| String literals | Text (read-only) | As written | Program |

## Stack Frame Example



## Heap Considerations



## Key Rules
1. Never return pointer to local variable (dangling pointer)
2. Always initialize pointers before use
3. Every malloc must have a corresponding free
4. Use const to protect read-only data

---

*— Pavan Shetty H S*
