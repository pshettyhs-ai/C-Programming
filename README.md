<div align="center">

# 📘 C Programming — Complete Guide from Basics to Advanced

[![Language](https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c)](https://en.wikipedia.org/wiki/C_(programming_language))
[![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)](LICENSE)
[![GitHub Stars](https://img.shields.io/github/stars/pshettyhs-ai/C-Programming?style=for-the-badge&logo=github)]
[![Author](https://img.shields.io/badge/Author-Pavan%20Shetty%20H%20S-blueviolet?style=for-the-badge)]
[![Contributions Welcome](https://img.shields.io/badge/Contributions-Welcome-orange?style=for-the-badge)](CONTRIBUTING.md)
[![GitHub Forks](https://img.shields.io/github/forks/pshettyhs-ai/C-Programming?style=for-the-badge&logo=github)]

**Created and maintained by [Pavan Shetty H S](https://github.com/pshettyhs-ai)**

*A hands-on, beginner-friendly, placement-ready C programming resource — built the way I wished someone had explained it to me.*

[📚 Roadmap](#-learning-roadmap) &nbsp;·&nbsp; [📁 Structure](#-repository-structure) &nbsp;·&nbsp; [💡 Interview Prep](#-interview-preparation) &nbsp;·&nbsp; [🔨 Projects](#-mini-projects) &nbsp;·&nbsp; [⚙️ Setup](#-getting-started)

</div>

---

## 🙋 Why I Built This

Hello! I'm **Pavan Shetty H S**, a ECE student who spent months learning C for academics and placement preparation. The biggest problem I faced was that most resources either moved too fast, skipped memory concepts entirely, or gave textbook answers that didn't actually help in interviews.

So I decided to document everything I learned — in my own words, with my own examples, with the mistakes I personally made highlighted so you can avoid them. This repository is the resource I wish existed when I started.

Whether you are picking up C for the first time, preparing for a university exam, or getting ready for a placement interview — this is built for you.

---

## ✨ What This Repository Offers

| What you get | Details |
|---|---|
| 📖 Theory in plain language | I explain every concept simply, without unnecessary jargon |
| 💻 Programs at 3 levels | Basic → Intermediate → Advanced for every single topic |
| 🧠 Memory layout diagrams | I show where each variable sits in RAM (stack, heap, BSS) |
| ❓ Interview Q&A | 100+ questions with answers written the way I'd say them |
| 🧩 Graded practice problems | Easy, Medium, and Hard problems with hints |
| 🔨 10 complete mini projects | Real programs — not toy examples |
| ⚠️ Common mistakes section | Bugs I actually made, so you don't repeat them |
| 📊 Complexity analysis | Time and space complexity for every significant program |

---

## 🗺️ Learning Roadmap

I recommend following the chapters in order. Each one builds on the previous.

```
╔════════════════════════════════════════════════════════════════════╗
║              PAVAN'S C PROGRAMMING LEARNING PATH                  ║
╚════════════════════════════════════════════════════════════════════╝

PHASE 1 — FOUNDATIONS                                    Weeks 1–3
────────────────────────────────────────────────────────────────────
  01  Introduction to C       History, compilers, your first program
  02  Variables & Data Types  Storing numbers, characters, decimals
  03  Operators               Math, logic, comparisons, bit tricks
  04  Input and Output        printf, scanf, format specifiers

PHASE 2 — CONTROL FLOW                                   Weeks 4–5
────────────────────────────────────────────────────────────────────
  05  Conditional Statements  if, else, switch — making decisions
  06  Loops                   for, while, do-while — repeating tasks

PHASE 3 — FUNCTIONS AND MODULARITY                       Week 6
────────────────────────────────────────────────────────────────────
  07  Functions               Write once, use many times
  08  Recursion               Functions that call themselves

PHASE 4 — DATA AND MEMORY                                Weeks 7–9
────────────────────────────────────────────────────────────────────
  09  Arrays                  Store many values in a row
  10  Strings                 Text is just a char array in C
  11  Pointers                The most important concept in C
  12  Pointer Applications    Function pointers, void *, double **

PHASE 5 — USER-DEFINED TYPES                             Week 10
────────────────────────────────────────────────────────────────────
  13  Structures              Group related data under one name
  14  Unions                  Share memory between multiple types

PHASE 6 — ADVANCED FEATURES                              Weeks 11–14
────────────────────────────────────────────────────────────────────
  15  Storage Classes         auto, static, extern, register
  16  Dynamic Memory          malloc, calloc, realloc, free
  17  File Handling           Read and write files
  18  Preprocessor Directives #define, #include, macros
  19  Command Line Arguments  argc and argv
  20  Bitwise Programming     Bit-level manipulation tricks

PHASE 7 — DATA STRUCTURES IN C                           Weeks 15–18
────────────────────────────────────────────────────────────────────
  21  Linked List · Stack · Queue · Tree · Hash Table
      Sorting: Bubble · Selection · Insertion · Merge · Quick
      Searching: Linear · Binary · Jump · Interpolation

PHASE 8 — PROJECTS AND PLACEMENT                         Weeks 19–22
────────────────────────────────────────────────────────────────────
  22  Advanced C Topics       volatile, restrict, atomics, _Generic
  23  Mini Projects           10 real programs I built
  24  Interview Preparation   500+ Q&A, MCQs, placement guide
```

---

## 📁 Repository Structure

```
C-Programming/
│
├── README.md                         ← You are reading this
├── LICENSE
├── .gitignore
│
├── 01_Introduction/
│   ├── README.md                     ← Chapter overview
│   ├── Theory.md                     ← Concept explained in my words
│   ├── Syntax.md                     ← Syntax rules with examples
│   ├── Memory_Concepts.md            ← How it works in RAM
│   ├── Programs/
│   │   ├── Basic.c                   ← Beginner-level programs
│   │   ├── Intermediate.c            ← Moderate programs
│   │   └── Advanced.c                ← Complex, real-world usage
│   ├── Practice_Problems.md          ← Graded exercises
│   └── Interview_Questions.md        ← Q&A from real interviews
│
├── 02_Variables_DataTypes/ ────────── same structure for all topics
├── 03_Operators/
├── ...
├── 20_Bitwise_Programming/
│
├── 21_Data_Structures_in_C/
│   ├── Linked_List/
│   ├── Stack/
│   ├── Queue/
│   ├── Tree/
│   ├── Hash_Table/
│   ├── Sorting/
│   └── Searching/
│
├── 22_Advanced_C/
│
├── 23_Mini_Projects/
│   ├── Student_Management/
│   │   ├── README.md
│   │   ├── Source_Code/main.c
│   │   ├── Sample_Output/output.txt
│   │   └── Project_Report.md
│   ├── Banking_System/
│   ├── Tic_Tac_Toe/
│   └── ... (10 projects total)
│
├── 24_Interview_Preparation/
│   ├── README.md
│   ├── Top_100_Questions.md
│   ├── MCQ_Practice.md
│   └── Placement_Guide.md
│
└── Resources/
    ├── Cheatsheet.md
    ├── Reference_Card.md
    └── Recommended_Books.md
```

---

## 📚 Topics Covered

<details>
<summary><b>Phase 1 — Foundations (Chapters 1–4)</b></summary>

- The story behind C — Dennis Ritchie, Bell Labs, and why it still matters
- All 4 compilation stages: preprocessing → compilation → assembling → linking
- Every data type with exact byte sizes and value ranges
- Implicit and explicit type conversion — and where it silently goes wrong
- All operators with precedence table and real examples
- printf and scanf — every format specifier explained clearly

</details>

<details>
<summary><b>Phase 2 — Control Flow (Chapters 5–6)</b></summary>

- if, else if, else — including the classic "dangling else" trap
- switch with fall-through — when it helps and when it hurts
- All three loop types — and my rule for choosing which to use
- break, continue explained with flow diagrams
- Common loop patterns: digit sum, reverse number, prime check

</details>

<details>
<summary><b>Phase 3 — Functions and Recursion (Chapters 7–8)</b></summary>

- Function declaration vs definition — why both matter
- Call by value vs call by reference (with pointer diagrams)
- Why you must never return the address of a local variable
- Recursion call stack visualisation — I draw this out step by step
- Classic problems: factorial, Fibonacci, GCD, Tower of Hanoi

</details>

<details>
<summary><b>Phase 4 — Pointers — The Heart of C (Chapters 9–12)</b></summary>

- Pointer declaration, initialization, and dereferencing
- Pointer arithmetic — why p++ moves by 4 bytes not 1
- const int *p vs int * const p — clearly explained at last
- Double pointers — what they look like in memory
- void * and function pointers with real dispatch table examples

</details>

<details>
<summary><b>Phases 5–8 — Advanced Topics (Chapters 13–24)</b></summary>

- Struct padding and alignment — why sizeof surprises you
- Tagged unions as a safe variant type
- Dynamic memory — malloc patterns and how leaks happen
- File I/O: text mode vs binary mode, fseek for random access
- Bitwise tricks: set, clear, toggle, check bits, popcount
- All major data structures built from scratch in C

</details>

---

## ⚙️ Getting Started

### Requirements

| Tool | Purpose | Link |
|------|---------|------|
| GCC 9+ | Compile C programs | [gcc.gnu.org](https://gcc.gnu.org/) |
| VS Code | Code editor (my choice) | [code.visualstudio.com](https://code.visualstudio.com/) |
| Git | Clone this repo | [git-scm.com](https://git-scm.com/) |

### Clone and run

```bash
# Clone the repository
git clone https://github.com/pshettyhs-ai /C-Programming.git
cd C-Programming

# Compile and run any program
gcc program.c -o program
./program

# My recommended flags — catches most beginner bugs
gcc -Wall -Wextra -std=c11 program.c -o program
./program

# If the program uses math functions like sqrt or pow
gcc program.c -o program -lm
./program

# With debugging symbols (for use with gdb)
gcc -g program.c -o program
```

### Platform setup

**Ubuntu / Debian Linux:**
```bash
sudo apt update && sudo apt install gcc gdb valgrind build-essential
```

**macOS:**
```bash
xcode-select --install    # installs clang (works the same as gcc)
```

**Windows:**
Download and install MinGW-w64 from [mingw-w64.org](https://mingw-w64.org), then use `gcc` in the terminal.

**No installation? Try these online compilers:**
- [onlinegdb.com](https://onlinegdb.com) — includes a debugger
- [replit.com](https://replit.com) — browser-based IDE
- [godbolt.org](https://godbolt.org) — shows the assembly your code produces

---

## 🔨 Mini Projects

These are programs I actually built, tested, and documented. Each one uses multiple concepts together.

| # | Project | Main Concepts Used | Difficulty |
|---|---------|-------------------|------------|
| 01 | Student Management System | Structs, file I/O, arrays, sorting | ⭐⭐ Medium |
| 02 | Library Management System | Linked lists, file persistence | ⭐⭐⭐ Medium+ |
| 03 | Banking System | Structs, transactions, binary files | ⭐⭐⭐ Medium+ |
| 04 | Employee Record System | Dynamic memory, structs | ⭐⭐⭐ Medium+ |
| 05 | Inventory Management | Sorting, searching, file I/O | ⭐⭐⭐ Medium+ |
| 06 | Contact Book | Linked list, string search | ⭐⭐ Medium |
| 07 | File Compressor (RLE) | Bitwise operations, file I/O | ⭐⭐⭐⭐ Hard |
| 08 | Scientific Calculator | Functions, math.h, history buffer | ⭐ Easy |
| 09 | Snake Game | Arrays, terminal I/O, game loop | ⭐⭐⭐⭐ Hard |
| 10 | Tic Tac Toe with AI | Minimax algorithm, 2D arrays | ⭐⭐ Medium |

---

## 💡 Interview Preparation

The `24_Interview_Preparation/` folder has everything I used during placement prep:

- ✅ Top 100 C Interview Questions — with fully explained answers in my words
- ✅ 75+ MCQs — output prediction and concept-based questions with answer key
- ✅ Placement Guide — company-wise question patterns for TCS, Infosys, Samsung, Qualcomm, and more
- ✅ 30-day revision plan — how I structured my last month before placements
- ✅ Last-minute checklist — the 15 things that trip up most candidates

---

## 🤝 Contributing

If you spot an error, have a cleaner explanation, or want to add a program — contributions are very welcome.

```bash
# 1. Fork this repo on GitHub
# 2. Clone your fork
git clone https://github.com/YOUR_USERNAME/C-Programming.git

# 3. Create a new branch
git checkout -b feature/your-improvement

# 4. Make your changes, commit clearly
git add .
git commit -m "Add: binary search tree deletion explained"

# 5. Push and open a Pull Request
git push origin feature/your-improvement
```

**Please keep contributions:**
- Simple and beginner-friendly in language
- Technically correct and tested
- Well-commented with educational notes
- Consistent with the style of the rest of the repo

---

## 📖 Resources and Books

| Resource | My recommendation |
|---------|-------------------|
| Let Us C — Yashavant Kanetkar | Start here if you are brand new to C |
| The C Programming Language — K&R | Read this after you know the basics. A classic. |
| Pointers in C — Yashavant Kanetkar | The best book specifically on pointers |
| Expert C Programming — Peter van der Linden | Funny, deep, and genuinely useful |
| C Traps and Pitfalls — Andrew Koenig | Every sneaky bug in C, explained |
| GeeksForGeeks (online) | Good for quick topic references |
| cppreference.com (online) | The most accurate C standard reference |

---

## 📜 License

This repository is licensed under the **MIT License**.
You are free to use, copy, and share it for personal learning or education. See [LICENSE](LICENSE) for details.

---

<div align="center">

## 👤 Author — Pavan Shetty H S

*ECE Student | C Enthusiast | Placement Aspirant*

I built this repository as part of my own learning journey. Everything here is written in my own words, tested by me, and shared freely for any student who finds it useful.

([https://github.com/pshettyhs-ai](https://github.com/pshettyhs-ai))

---

*If this repository helped you — a ⭐ on GitHub would genuinely mean a lot to me.*

*Good luck with your learning and your placements. You've got this. 💪*

</div>

