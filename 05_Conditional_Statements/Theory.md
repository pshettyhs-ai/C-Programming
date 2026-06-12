# Theory — Conditional Statements

> **Author: Pavan Shetty H S**

---

## 1. Why We Need Conditionals

A program that runs the same steps every time is not very useful. Conditionals let your code make decisions. They are the foundation of any logic in programming.

C gives you three tools for this: `if-else`, `switch-case`, and the ternary operator `? :`.

---

## 2. The if-else Chain

```c
if (condition1) {
    /* runs when condition1 is true (non-zero) */
} else if (condition2) {
    /* runs when condition1 is false but condition2 is true */
} else {
    /* runs when ALL conditions above are false */
}
```

**Real example — grading system:**
```c
int marks = 78;

if (marks >= 90) {
    printf("Grade: O (Outstanding)\n");
} else if (marks >= 75) {
    printf("Grade: A\n");
} else if (marks >= 60) {
    printf("Grade: B\n");
} else if (marks >= 50) {
    printf("Grade: C\n");
} else {
    printf("Grade: F (Fail)\n");
}
/* Output: Grade: A */
```

**The dangling else problem — one of the most common beginner bugs:**
```c
/* What does this actually do? */
if (x > 0)
    if (x > 100)
        printf("big positive\n");
else
    printf("where does this else belong?\n");

/*
 * The else belongs to the INNER if (x > 100), not the outer one.
 * C always pairs else with the nearest preceding unmatched if.
 * This is called the "dangling else" problem.
 *
 * Fix: always use curly braces, even for single-line blocks.
 */
if (x > 0) {
    if (x > 100) {
        printf("big positive\n");
    }
} else {
    printf("non-positive\n");   /* now clearly belongs to outer if */
}
```

---

## 3. switch-case

switch is best when you are comparing one variable against many constant values:

```c
switch (expression) {      /* expression must evaluate to an integer type */
    case CONSTANT_1:
        /* code */
        break;             /* without break, execution falls into the next case */
    case CONSTANT_2:
        /* code */
        break;
    default:               /* optional — runs if no case matches */
        /* code */
        break;
}
```

**Day-of-week example:**
```c
int day = 3;

switch (day) {
    case 1:  printf("Monday\n");    break;
    case 2:  printf("Tuesday\n");   break;
    case 3:  printf("Wednesday\n"); break;
    case 4:  printf("Thursday\n");  break;
    case 5:  printf("Friday\n");    break;
    case 6:  printf("Saturday\n");  break;
    case 7:  printf("Sunday\n");    break;
    default: printf("Invalid day\n");
}
```

**Intentional fall-through — grouping cases:**
```c
switch (day) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        printf("Weekday\n");    /* all 5 cases share this code */
        break;
    case 6:
    case 7:
        printf("Weekend\n");
        break;
}
```

**What switch cannot do:**
- Cannot use float or double as the expression
- Cannot use strings (use `strcmp` with if-else for string matching)
- Case values must be integer constants, not variables

---

## 4. switch vs if-else — When to Use Which

| Use switch | Use if-else |
|------------|-------------|
| Comparing one variable to several integer constants | Range checks like `score >= 90` |
| Menu systems with numbered options | Comparing floats |
| Character dispatch (vowel check, menu choices) | Complex boolean conditions |
| When you want intentional fall-through | Mixed condition types |
| 4+ discrete cases | 1–3 conditions |

---

## 5. The Ternary Operator

A shorthand for simple if-else assignments. I use it when the logic fits in one line cleanly:

```c
/* condition ? value_if_true : value_if_false */

int n = -7;
int abs_n = (n < 0) ? -n : n;          /* absolute value */

int age = 20;
char *status = (age >= 18) ? "Adult" : "Minor";

int a = 10, b = 20;
int bigger = (a > b) ? a : b;          /* maximum of two values */
```

I avoid nesting ternary operators more than once — it gets unreadable fast. If the logic is complex, a regular if-else is clearer.

---

## 6. Nested if Statements

```c
int age = 20;
int hasID = 1;

if (age >= 18) {
    if (hasID) {
        printf("Entry allowed.\n");
    } else {
        printf("No ID — cannot enter.\n");
    }
} else {
    printf("Too young to enter.\n");
}
```

The key thing I learned: always add braces `{}` even when a block has only one statement. It prevents bugs when you add a second statement later and forget to add the braces.

---

## 7. Common Mistakes

```c
/* Mistake 1: = instead of == */
if (x = 5)     /* assigns 5 to x, condition is always true — BUG */
if (x == 5)    /* correct comparison */

/* Mistake 2: Missing break in switch */
switch (x) {
    case 1: printf("one\n");     /* falls through to case 2! */
    case 2: printf("two\n"); break;
}
/* if x is 1, prints "one" AND "two" */

/* Mistake 3: switch on float */
float temp = 36.6f;
switch (temp) { ... }    /* compile error — only integers allowed */

/* Mistake 4: No default in switch */
/* If none of the cases match, nothing runs — no error, no warning */
/* Always add a default case, even if it just says "should not happen" */
```
