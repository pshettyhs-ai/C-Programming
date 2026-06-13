# Interview Questions — Unions

## 🟢 Basic
**Q1. What is the difference between a struct and a union?**
> In a `struct`, each member has its own memory — all members exist simultaneously. In a `union`, all members share the same memory — only one member can hold a valid value at a time. `sizeof(union)` = size of its largest member. `sizeof(struct)` = sum of member sizes (+ padding).

**Q2. What is the size of this union?**
```c
union U { char c; int i; double d; };
```
> `sizeof(double)` = 8 bytes — the size of the largest member. All three members start at the same address.

**Q3. Why is it dangerous to read a union member that wasn't the last one written?**
> The bytes at the union's address only make sense when interpreted as the type that was last written. Reading through a different member reinterprets those same bytes as a different type — the result is garbage or implementation-defined. Exception: reading `char`/`unsigned char` members is always defined (byte-level access).

## 🟡 Intermediate
**Q4. What is a tagged union and why is it useful?**
> A tagged union is a struct containing a union plus an enum "tag" that records which union member is currently valid. This makes variant types safe — always check the tag before accessing any member. Used to implement sum types, JSON parsers, interpreter value types.

**Q5. How can unions be used for type punning?**
> Writing to one union member and reading from another (of different type) to inspect the raw bytes is called type punning. C11 allows this through union (unlike C++). Commonly used to inspect floating-point bit patterns, convert between network byte-order types, and implement fast inverse square root tricks.

## 🔴 Advanced
**Q6. What is an anonymous union?**
```c
struct Packet {
    int type;
    union {            /* anonymous — no union tag name */
        int   idata;
        float fdata;
    };                 /* members accessed directly: pkt.idata */
};
struct Packet pkt;
pkt.idata = 42;       /* no pkt.u.idata needed */
```
> Anonymous unions/structs (C11) let you access members of nested unions/structs without the intermediate name — cleaner syntax for tagged unions.

---

*— Pavan Shetty H S*
