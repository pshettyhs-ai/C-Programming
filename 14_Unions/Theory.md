# Theory — Unions

> **Author: Pavan Shetty H S**

---

## 1. What is a Union?

A union looks like a struct, but all members share the same memory location. Only one member holds a valid value at any time. The size of a union is the size of its largest member.

```c
union Data {
    int    i;       /* 4 bytes */
    float  f;       /* 4 bytes */
    char   str[20]; /* 20 bytes */
};
/* sizeof(union Data) = 20 — size of largest member */

union Data d;
d.i = 42;
printf("%d\n", d.i);    /* 42 — valid */

d.f = 3.14f;            /* now f is active, i is no longer valid */
printf("%f\n", d.f);    /* 3.14 — valid */
printf("%d\n", d.i);    /* garbage — f's bytes read as int */
```

---

## 2. Struct vs Union — Side by Side

```
struct Example:                    union Example:
┌──────────┬──────────┬──────────┐  ┌──────────────────────────┐
│  char c  │  int  i  │ double d │  │  char c / int i / double │
│  1 byte  │  4 bytes │  8 bytes │  │       all start at [0]   │
└──────────┴──────────┴──────────┘  └──────────────────────────┘
  sizeof = 16 (with padding)          sizeof = 8 (largest member)
  All members valid simultaneously    Only one member valid at a time
```

---

## 3. The Safe Way — Tagged Union

The main risk with unions is reading the wrong member. The solution is to always pair a union with an enum tag that records which member is currently active:

```c
typedef enum { T_INT, T_FLOAT, T_STRING } ValueType;

typedef struct {
    ValueType type;
    union {
        int    i;
        float  f;
        char   s[32];
    } val;
} Variant;

/* Writing */
Variant v;
v.type  = T_FLOAT;
v.val.f = 3.14f;

/* Reading — always check the tag first */
switch (v.type) {
    case T_INT:    printf("int:   %d\n",   v.val.i); break;
    case T_FLOAT:  printf("float: %.2f\n", v.val.f); break;
    case T_STRING: printf("str:   %s\n",   v.val.s); break;
}
```

This pattern is how you implement variant types in C — JSON parsers, interpreters, and scripting language runtimes use it constantly.

---

## 4. Type Punning — Reading One Type as Another

Unions can be used to inspect the raw bytes of a floating-point number:

```c
union FloatBits {
    float    f;
    uint32_t bits;
};

union FloatBits fb;
fb.f = -1.0f;
printf("IEEE 754 bits of -1.0f: 0x%08X\n", fb.bits);
/* Output: 0xBF800000  (sign=1, exp=127, mantissa=0) */
```

---

## 5. Endianness Detection

```c
union EndianTest {
    uint32_t word;
    uint8_t  bytes[4];
};

union EndianTest e;
e.word = 0x01020304;

if (e.bytes[0] == 0x04)
    printf("Little-endian (x86, most modern CPUs)\n");
else
    printf("Big-endian (some RISC architectures, network byte order)\n");
```

---

## 6. Anonymous Unions (C11)

When a union has no name, its members are accessed directly without the intermediate union name:

```c
typedef struct {
    int type;
    union {          /* anonymous union */
        int   idata;
        float fdata;
        char  sdata[32];
    };               /* note: no name after the closing brace */
} Packet;

Packet pkt;
pkt.type  = 1;
pkt.idata = 42;    /* accessed directly — no pkt.u.idata needed */
```

---

## 7. When to Use Unions

| Use case | Why a union helps |
|----------|------------------|
| Variant types (int OR float OR string) | One field, multiple interpretations |
| Protocol packet decoding | Same bytes, different field layouts |
| Type punning | Inspect raw bytes of a float |
| Memory-constrained embedded code | Save memory when only one field needed |
| Endianness detection | Access individual bytes of a multi-byte value |
