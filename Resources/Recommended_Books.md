# Books and Resources I Recommend

> **Author: Pavan Shetty H S**
>
> These are resources I actually used or wish I had found earlier.

---

## Books — In the Order I Recommend Reading Them

### If you are brand new to C

**Let Us C** — Yashavant Kanetkar
The book most Indian CS students start with. Straightforward, exam-oriented, and covers the basics well. A good first book.

**C Programming: A Modern Approach** — K.N. King
More thorough than Let Us C. Better explanations, good exercises. I wish I had read this one first.

**Head First C** — David and Dawn Griffiths
Visual and engaging. If you learn better with diagrams than walls of text, this is for you.

---

### After you know the basics

**The C Programming Language** — Kernighan and Ritchie (K&R)
The original C book, written by the people who created the language. Not a beginner book — read it after you are comfortable with the basics. Every serious C programmer should read this at least once.

**Pointers in C** — Yashavant Kanetkar
The best dedicated book on pointers. If pointers still confuse you after reading this one, read it again.

**Data Structures Using C** — Reema Thareja
Covers all major data structures with C implementations. Good for university exams and placements.

---

### Advanced reading

**Expert C Programming: Deep C Secrets** — Peter van der Linden
Witty, detailed, and genuinely eye-opening. Covers things most C textbooks never touch — linkers, memory models, compiler internals. Read this when you feel confident.

**C Traps and Pitfalls** — Andrew Koenig
Every subtle bug in C, catalogued and explained. Short but dense. Read it slowly.

**Modern C** — Jens Gustedt
Up-to-date coverage of C11 and C17. Good if you want to write idiomatic modern C.

---

## Online Resources

| Resource | What it is good for |
|---------|-------------------|
| [cppreference.com/w/c](https://en.cppreference.com/w/c) | Most accurate C standard reference. I use this daily. |
| [GeeksForGeeks — C](https://www.geeksforgeeks.org/c-programming-language/) | Quick topic summaries and practice problems |
| [HackerRank — C](https://www.hackerrank.com/domains/c) | Practice problems with automated grading |
| [Godbolt Compiler Explorer](https://godbolt.org) | See exactly what assembly your C code produces |
| [OnlineGDB](https://www.onlinegdb.com) | Browser-based C compiler with debugger |
| [Valgrind](https://valgrind.org) | Memory error detection tool — indispensable |

---

## Tools I Use

**GCC with sanitisers:**
```bash
gcc -Wall -Wextra -std=c11 -g -fsanitize=address,undefined program.c -o program
./program
```
This catches memory errors, undefined behaviour, and out-of-bounds accesses at runtime. I run every program with these flags while learning.

**Valgrind for memory leak detection:**
```bash
valgrind --leak-check=full --show-leak-kinds=all ./program
```

**GDB for debugging:**
```bash
gcc -g program.c -o program    # compile with debug symbols
gdb ./program                  # start debugger
(gdb) break main               # set breakpoint at main
(gdb) run                      # start the program
(gdb) next                     # step one line
(gdb) print x                  # print value of x
(gdb) bt                       # show call stack
```

---

## Setting Up VS Code for C

1. Install VS Code
2. Install the **C/C++** extension by Microsoft
3. Install the **Code Runner** extension (optional but convenient)
4. Create `.vscode/tasks.json`:

```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "Build C with sanitizers",
            "type": "shell",
            "command": "gcc",
            "args": [
                "-Wall", "-Wextra", "-std=c11", "-g",
                "-fsanitize=address,undefined",
                "${file}", "-o", "${fileBasenameNoExtension}", "-lm"
            ],
            "group": { "kind": "build", "isDefault": true }
        }
    ]
}
```

Press `Ctrl+Shift+B` to build and `F5` to debug.

---

*— Pavan Shetty H S*
