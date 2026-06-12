# Theory — Loops in C

> **Author: Pavan Shetty H S**

---

## 1. Why Loops Exist

Imagine writing `printf` 1000 times. Loops let you repeat a block of code without copying it. They are one of the most fundamental ideas in programming.

C has three loop constructs. Each one is best for a specific situation.

---

## 2. The for Loop

Use this when you know how many times you want to repeat:

```c
for (initialization; condition; update) {
    /* body executes while condition is true */
}
```

```c
/* Count from 1 to 5 */
for (int i = 1; i <= 5; i++) {
    printf("%d ", i);
}
/* Output: 1 2 3 4 5 */
```

**All three parts of the for loop are optional:**
```c
for (;;) {
    /* infinite loop — runs forever until a break */
}

int i = 0;
for (; i < 5; ) {
    printf("%d ", i);
    i++;    /* update moved inside the body */
}
```

**Multiple variables:**
```c
for (int i = 0, j = 10; i < j; i++, j--) {
    printf("i=%d j=%d\n", i, j);
}
```

---

## 3. The while Loop

Use this when the number of iterations is not known upfront — you loop as long as a condition holds:

```c
while (condition) {
    /* body */
}
```

```c
/* Sum of digits of a number */
int n = 12345, sum = 0;
while (n > 0) {
    sum += n % 10;   /* extract last digit */
    n   /= 10;       /* remove last digit */
}
printf("Sum = %d\n", sum);   /* 15 */
```

```c
/* Read numbers until the user enters -1 */
int num;
printf("Enter numbers (-1 to stop):\n");
while (scanf("%d", &num) == 1 && num != -1) {
    printf("Got: %d\n", num);
}
```

---

## 4. The do-while Loop

The body runs **at least once**, then the condition is checked:

```c
do {
    /* body */
} while (condition);    /* note: semicolon is required here */
```

**Perfect for input validation — you always want to ask at least once:**
```c
int choice;
do {
    printf("Enter a number between 1 and 5: ");
    scanf("%d", &choice);
    if (choice < 1 || choice > 5) {
        printf("That is not valid. Try again.\n");
    }
} while (choice < 1 || choice > 5);

printf("You entered: %d\n", choice);
```

**Menu-driven programs are the most common use case:**
```c
int option;
do {
    printf("\n1. View\n2. Add\n3. Delete\n0. Exit\nChoice: ");
    scanf("%d", &option);
    /* handle option */
} while (option != 0);
```

---

## 5. break and continue

**`break`** — immediately exits the innermost loop or switch:
```c
for (int i = 0; i < 100; i++) {
    if (i == 5) break;          /* stops at 5 */
    printf("%d ", i);
}
/* Output: 0 1 2 3 4 */
```

**`continue`** — skips the rest of the current iteration and moves to the next:
```c
for (int i = 0; i < 10; i++) {
    if (i % 2 == 0) continue;  /* skip even numbers */
    printf("%d ", i);
}
/* Output: 1 3 5 7 9 */
```

**Important:** `break` only exits the **innermost** loop. To exit nested loops, use a flag variable or restructure the code into a function and use `return`.

---

## 6. Common Loop Patterns I Use Constantly

```c
/* Sum of first n natural numbers */
int sum = 0;
for (int i = 1; i <= n; i++) sum += i;

/* Find maximum in an array */
int max = arr[0];
for (int i = 1; i < n; i++)
    if (arr[i] > max) max = arr[i];

/* Reverse a number */
int rev = 0;
while (n != 0) {
    rev = rev * 10 + n % 10;
    n /= 10;
}

/* Count digits in a number */
int digits = 0;
do {
    digits++;
    n /= 10;
} while (n != 0);   /* do-while handles n=0 correctly */

/* Print multiplication table */
for (int i = 1; i <= 10; i++) {
    for (int j = 1; j <= 10; j++) {
        printf("%4d", i * j);
    }
    printf("\n");
}
```

---

## 7. When to Use Which Loop

| Situation | Best loop |
|-----------|-----------|
| Iterate exactly n times | `for` |
| Iterate over an array | `for` |
| Read until end-of-file | `while` |
| Loop until a condition changes | `while` |
| Input validation | `do-while` |
| Menu-driven program | `do-while` |
| Number must execute at least once | `do-while` |

---

## 8. Common Mistakes

```c
/* Mistake 1: Off-by-one — this prints 0 to 9, not 1 to 10 */
for (int i = 0; i < 10; i++) printf("%d\n", i);

/* Mistake 2: Infinite loop by accident */
for (int i = 0; i != 10; i += 3) { }   /* i goes 0,3,6,9,12... never equals 10 */
/* Fix: use i < 10 or i <= 9, not i != 10 */

/* Mistake 3: Modifying loop variable inside loop */
for (int i = 0; i < 5; i++) {
    printf("%d\n", i);
    i++;    /* now i jumps 2 at a time — likely a bug */
}

/* Mistake 4: Semicolon after for — empty loop body */
for (int i = 0; i < 5; i++);    /* the ; is the body — loop does nothing */
{
    printf("This runs once, not 5 times\n");
}
```
