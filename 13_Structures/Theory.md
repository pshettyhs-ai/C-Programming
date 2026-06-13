# Theory — Structures

> **Author: Pavan Shetty H S**

---

## 1. What is a Structure?

A structure groups variables of different types together under one name. Where an array holds many values of the same type, a struct holds different types that logically belong together.

```c
/* Without struct — these variables are unrelated to the compiler */
char  student_name[50];
int   student_roll;
float student_gpa;

/* With struct — clearly grouped, can be passed as one unit */
struct Student {
    char  name[50];
    int   roll;
    float gpa;
};
```

---

## 2. Defining, Declaring, and Using Structs

```c
/* Define the structure type */
struct Point {
    int x;
    int y;
};

/* Declare variables of that type */
struct Point p1;
struct Point p2 = { 3, 7 };    /* positional initialization */

/* Access members with the dot operator */
p1.x = 10;
p1.y = 20;
printf("(%d, %d)\n", p1.x, p1.y);
```

**typedef removes the need to write `struct` every time:**
```c
typedef struct {
    char  name[50];
    int   roll;
    float gpa;
} Student;

Student s1;                              /* no 'struct' keyword needed */
Student s2 = { "Pavan", 101, 9.1f };    /* positional */
Student s3 = { .name="Ravi", .gpa=8.5f, .roll=102 };  /* designated — preferred */
```

---

## 3. Passing Structs to Functions

**By value — function gets a full copy:**
```c
void print_student(Student s) {
    printf("%s: %.1f\n", s.name, s.gpa);
}
/* Works, but copies the entire struct onto the stack */
/* For large structs, this wastes memory and time */
```

**By pointer — efficient, allows modification:**
```c
void update_gpa(Student *s, float new_gpa) {
    s->gpa = new_gpa;    /* arrow operator for pointer to struct */
}

Student st = { "Pavan", 101, 9.1f };
update_gpa(&st, 9.5f);
```

**By const pointer — efficient read-only access:**
```c
void display(const Student *s) {
    printf("%-20s %3d  %.2f\n", s->name, s->roll, s->gpa);
    /* s->roll = 0;  would be a compile error — const prevents this */
}
```

**My rule:** pass structs by pointer almost always. Use `const Student *` when the function only reads, `Student *` when it needs to modify.

---

## 4. Arrays of Structures

```c
Student class[5] = {
    { "Alice",  101, 9.2f },
    { "Bob",    102, 8.5f },
    { "Carol",  103, 9.8f },
    { "Dave",   104, 7.9f },
    { "Eve",    105, 8.1f }
};

/* Sort by GPA descending */
for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4 - i; j++) {
        if (class[j].gpa < class[j+1].gpa) {
            Student tmp  = class[j];
            class[j]     = class[j+1];
            class[j+1]   = tmp;
        }
    }
}
```

---

## 5. Nested Structures

```c
typedef struct {
    int day, month, year;
} Date;

typedef struct {
    char  name[50];
    Date  date_of_birth;
    Date  enrollment_date;
    float gpa;
} Student;

Student s = {
    .name = "Pavan",
    .date_of_birth   = { 15, 8, 2002 },
    .enrollment_date = { 1,  7, 2021 },
    .gpa = 9.1f
};

printf("Born: %02d/%02d/%04d\n",
       s.date_of_birth.day,
       s.date_of_birth.month,
       s.date_of_birth.year);
```

---

## 6. Memory Layout and Padding

This is something that surprises most people. The compiler adds padding bytes between struct members to align them on their natural boundaries.

```c
struct Padded {
    char  a;     /* 1 byte  + 3 bytes padding */
    int   b;     /* 4 bytes */
    char  c;     /* 1 byte  + 3 bytes padding */
    int   d;     /* 4 bytes */
};
/* sizeof = 16, not 10! */

struct Efficient {
    int   b;     /* 4 bytes */
    int   d;     /* 4 bytes */
    char  a;     /* 1 byte */
    char  c;     /* 1 byte  + 2 bytes padding */
};
/* sizeof = 12 — same members, less waste, just reordered */
```

**Rule of thumb:** declare members from largest to smallest type to minimise padding.

---

## 7. Self-Referential Struct — Used for Linked Lists

A struct cannot contain itself by value (that would be infinite size), but it can contain a pointer to itself:

```c
typedef struct Node {
    int          data;
    struct Node *next;    /* pointer to same type — this is fine */
} Node;

Node *new_node(int val) {
    Node *n  = malloc(sizeof(Node));
    n->data  = val;
    n->next  = NULL;
    return n;
}
```

This is the building block of linked lists, trees, and every other pointer-based data structure.
