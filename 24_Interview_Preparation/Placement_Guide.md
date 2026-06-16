# Placement Guide — C Programming

> **Author: Pavan Shetty H S**

---

## Company-Wise C Question Patterns

Based on what I collected from friends and seniors who sat for these drives.

### TCS (NQT)
- **Focus:** Output prediction, loops, basic pointer questions
- **What I saw:** Tricky switch fall-through questions, integer promotion, sizeof
- **Style:** MCQ + 1-2 coding problems under time pressure
- **Tip:** Practice reading code and predicting output without running it

### Infosys (InfyTQ)
- **Focus:** Logic, functions, sorting algorithms
- **What I saw:** Array manipulation, recursive functions, basic file I/O
- **Style:** Coding test + MCQ
- **Tip:** Strong focus on clean, working code — not just algorithm knowledge

### Wipro (NLTH)
- **Focus:** C fundamentals, control flow, operators
- **What I saw:** Tricky operator precedence, post vs pre increment
- **Style:** Mostly MCQ
- **Tip:** Go through the operator precedence table carefully

### Samsung (SSAT / Research)
- **Focus:** Data structures, pointers, memory management
- **What I saw:** Linked list operations, BST traversal, bit manipulation
- **Style:** Full coding test — 3 problems in 3 hours
- **Tip:** Must be able to implement data structures completely from scratch

### Qualcomm / Texas Instruments
- **Focus:** Embedded C, bitwise operations, volatile, hardware concepts
- **What I saw:** Memory-mapped I/O simulation, register manipulation, endianness
- **Style:** Technical interview rounds
- **Tip:** Know volatile, const, bitfields, and hardware register patterns deeply

### ISRO / DRDO
- **Focus:** Systems programming, algorithms, memory management
- **What I saw:** Custom allocator design, process memory model, file parsing
- **Style:** Written test + interview
- **Tip:** Broader and deeper than campus placements — prepare for 2-3 months minimum

---

## Most Tested Topics by Frequency

| Rank | Topic | Why it is tested |
|------|-------|-----------------|
| 1 | Pointers | Core differentiator — shows real C knowledge |
| 2 | Recursion | Tests logical thinking and base case reasoning |
| 3 | Arrays and Strings | Manipulation, search, sort — universal |
| 4 | Dynamic Memory | malloc/free — separates beginners from intermediates |
| 5 | Structures | Data modelling — used in every project |
| 6 | Bitwise Ops | Popular in embedded/firmware roles |
| 7 | File Handling | Practical skill, tested in project-based rounds |
| 8 | Storage Classes | static and extern are frequent MCQ topics |
| 9 | Data Structures | Linked list, stack, BST from scratch |
| 10 | Preprocessor | Macros and include guards in MCQs |

---

## My 30-Day Preparation Plan

```
Week 1 (Days 1–7)
  Day 1–2:  Chapters 1–4  (Introduction, Variables, Operators, I/O)
  Day 3–4:  Chapters 5–6  (Conditionals, Loops) + Practice Problems
  Day 5–6:  Chapters 7–8  (Functions, Recursion) + Practice Programs
  Day 7:    Review + all Interview_Questions.md for chapters 1–8

Week 2 (Days 8–14)
  Day 8–9:  Chapters 9–10  (Arrays, Strings) + write programs from scratch
  Day 10–11: Chapters 11–12 (Pointers, Pointer Applications) — spend time here
  Day 12–13: Chapters 13–14 (Structures, Unions)
  Day 14:   Review + MCQ practice from this repository

Week 3 (Days 15–21)
  Day 15–16: Chapters 15–16 (Storage Classes, Dynamic Memory)
  Day 17–18: Chapters 17–18 (File Handling, Preprocessor)
  Day 19–20: Chapters 19–20 (Command Line, Bitwise)
  Day 21:   Review all Interview_Questions.md + 1 mini project

Week 4 (Days 22–28)
  Day 22–24: Chapter 21 — implement Linked List, Stack, BST from scratch
  Day 25–26: Sorting algorithms — implement and benchmark
  Day 27:   2 mini projects end-to-end
  Day 28:   Full mock interview — answer Top_100_Questions.md out loud

Days 29–30: Final revision
  Top_100_Questions.md full pass
  MCQ_Practice.md timed run
  Last-minute checklist review
```

---

## Last-Minute Checklist — Things That Always Trip People Up

- [ ] `malloc` returns `NULL` on failure — always check before using
- [ ] `free()` then set pointer to `NULL` — prevents use-after-free
- [ ] Integer division: `7/2` = `3`, not `3.5` — truncates toward zero
- [ ] `sizeof(array)` inside a function gives pointer size, not array size
- [ ] `strcmp` returns `0` for equal — not `1` or `true`
- [ ] String literals are read-only — use `char arr[]` to get a modifiable copy
- [ ] `static` local = persists across calls; `static` global = file scope only
- [ ] Pre-increment `++i` vs post-increment `i++` — know when it matters
- [ ] `&` for bitwise AND; `&&` for logical AND — never mix these in conditions
- [ ] `scanf` needs `&` for non-string types — `scanf("%d", &n)` not `scanf("%d", n)`
- [ ] Signed integer overflow is undefined behaviour — not guaranteed to wrap
- [ ] `fgets` includes the `\n` in the buffer — strip it with `strcspn`
- [ ] Array index starts at 0 — last valid index is `n-1`, not `n`
- [ ] Pointer arithmetic moves by `sizeof(type)` bytes, not 1 byte
- [ ] `realloc` — never assign result directly to original pointer (leaks on failure)

---

## Output Prediction Practice

These are the types of tricky questions that appear in MCQ rounds. Trace through by hand before running:

```c
/* Q1: What prints? */
int x = 5;
printf("%d %d\n", x++, ++x);
/* Answer: Undefined behaviour — don't write this. But interviewers ask it. */

/* Q2: What is sizeof? */
char *s = "Hello";
printf("%zu %zu\n", strlen(s), sizeof(s));
/* Answer: 5 and 8 (on 64-bit) — strlen gives string length, sizeof gives pointer size */

/* Q3: What prints? */
int arr[] = {1, 2, 3, 4, 5};
int *p = arr + 2;
printf("%d %d\n", *(p-1), *(p+2));
/* Answer: 2 and 5 */

/* Q4: What prints? */
static int x = 5;
if (x-- > 0) main();   /* ignore that calling main recursively is UB */
printf("%d ", x);
/* Answer: -1 -1 -1 -1 -1 -1 (printed 6 times, once per call on the way back) */

/* Q5: sizeof union */
union U { int i; double d; char c[3]; };
printf("%zu\n", sizeof(union U));
/* Answer: 8 (size of largest member, double) */
```

---

*— Pavan Shetty H S*
