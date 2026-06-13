# Theory — Strings in C

> **Author: Pavan Shetty H S**

---

## 1. What is a String in C?

In C, there is no dedicated string type. A string is just a `char` array where the last element is the **null character** `'\0'` (ASCII value 0). This null terminator tells string functions where the string ends.

```c
char name[] = "Pavan";

/* What is actually stored in memory: */
/*  P    a    v    a    n   \0          */
/* [0]  [1]  [2]  [3]  [4]  [5]        */

printf("Length: %zu\n",  strlen(name));   /* 5 — does NOT count \0 */
printf("Size:   %zu\n",  sizeof(name));   /* 6 — DOES count \0 */
```

The null character is invisible and automatic — when you write `"Pavan"`, the compiler adds `'\0'` for you. But you must always make sure your char arrays are large enough to hold both the characters AND the terminator.

---

## 2. Two Ways to Declare Strings — Very Different Behaviour

```c
/* Option 1: Character array — stored on stack, MODIFIABLE */
char name1[] = "Pavan";
name1[0] = 'p';    /* OK — this is a local array you can change */

/* Option 2: Pointer to string literal — stored in read-only segment */
char *name2 = "Pavan";
name2[0] = 'p';    /* UNDEFINED BEHAVIOUR — likely a crash */
                   /* String literals are read-only */

/* The safe habit: use const for pointer-to-literal */
const char *name3 = "Pavan";   /* compiler will catch accidental modification */
```

---

## 3. Reading Strings Safely

```c
char buf[100];

/* NEVER use gets() — removed in C11, causes buffer overflow */

/* scanf("%s") — stops at whitespace, no length limit — risky */
scanf("%s", buf);          /* dangerous for user input */

/* fgets — always use this for reading strings from users */
fgets(buf, sizeof(buf), stdin);    /* reads at most 99 chars + '\0' */

/* fgets includes the \n — strip it like this */
buf[strcspn(buf, "\n")] = '\0';

/* scanf with width limit — acceptable */
scanf("%99s", buf);    /* reads at most 99 characters */
```

---

## 4. The Standard String Library (string.h)

I use these all the time. Know them well:

```c
#include <string.h>

/* Length */
strlen(s)                  /* number of characters, NOT counting \0 */

/* Copy */
strcpy(dst, src)           /* copies src into dst — UNSAFE if dst too small */
strncpy(dst, src, n)       /* copies at most n chars — always add \0 yourself */
snprintf(dst, n, "%s", src) /* safest option for copying strings */

/* Concatenate */
strcat(dst, src)           /* appends src to dst — UNSAFE */
strncat(dst, src, n)       /* appends at most n chars — safer */

/* Compare */
strcmp(s1, s2)             /* 0 if equal, <0 if s1<s2, >0 if s1>s2 */
strncmp(s1, s2, n)         /* compare first n chars */
strcasecmp(s1, s2)         /* case-insensitive (POSIX) */

/* Search */
strchr(s, c)               /* pointer to first occurrence of char c, or NULL */
strrchr(s, c)              /* pointer to last occurrence */
strstr(s, sub)             /* pointer to first occurrence of substring */

/* Tokenize */
strtok(s, delim)           /* splits string by delimiter — modifies the string! */
```

**The most important rule:** always check that `strcmp` returns `0` to test equality:
```c
/* WRONG — compares pointer addresses, not string contents */
if (name == "Pavan") { ... }

/* CORRECT */
if (strcmp(name, "Pavan") == 0) { ... }
```

---

## 5. Common String Algorithms

```c
/* Reverse a string in place */
void reverse_string(char *s) {
    int lo = 0, hi = strlen(s) - 1;
    while (lo < hi) {
        char temp = s[lo];
        s[lo] = s[hi];
        s[hi] = temp;
        lo++;
        hi--;
    }
}

/* Check if palindrome */
int is_palindrome(const char *s) {
    int lo = 0, hi = strlen(s) - 1;
    while (lo < hi) {
        if (s[lo] != s[hi]) return 0;
        lo++;
        hi--;
    }
    return 1;
}

/* Count vowels */
int count_vowels(const char *s) {
    int count = 0;
    for (int i = 0; s[i]; i++) {
        char c = tolower(s[i]);
        if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
            count++;
    }
    return count;
}
```

---

## 6. Common Mistakes

```c
/* Mistake 1: Comparing strings with == */
if (s1 == s2)               /* compares addresses, not content */
if (strcmp(s1, s2) == 0)    /* correct */

/* Mistake 2: Modifying a string literal */
char *s = "hello";
s[0] = 'H';    /* crash — string literals are read-only */
/* Fix: char s[] = "hello"; */

/* Mistake 3: Forgetting null terminator space */
char name[5] = "Pavan";    /* no room for '\0' — writes 6 bytes into 5 */
char name[6] = "Pavan";    /* correct */

/* Mistake 4: strncpy does not guarantee null termination */
char dst[5];
strncpy(dst, "Hello World", 5);   /* copies "Hello", no '\0' added */
dst[4] = '\0';                    /* must add it yourself */

/* Mistake 5: strtok modifies the original string */
char sentence[] = "one two three";
strtok(sentence, " ");     /* sentence is now "one\0two three" */
/* Never call strtok on a string literal or const string */
```
