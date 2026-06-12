/*
 * ===================================================================
 *  File    : Basic.c
 *  Topic   : 05 Conditional Statements
 *  Level   : Beginner
 *  Author  : PAVAN SHETTY H S
 *
 *  Notes   : Written as part of my personal C programming study.
 *            Comments explain the reasoning, not just the syntax.
 *            Run with: gcc Basic.c -o out -lm && ./out
 * ===================================================================
 */

#include <stdio.h>

int main(void) {
    /* ── if / else if / else ─────────────────────────────────────────── */
    printf("=== if/else if/else ===\n");
    int score = 78;
    printf("Score: %d\n", score);
    if (score >= 90)      printf("Grade: O (Outstanding)\n");
    else if (score >= 75) printf("Grade: A (Excellent)\n");
    else if (score >= 60) printf("Grade: B (Good)\n");
    else if (score >= 50) printf("Grade: C (Average)\n");
    else                  printf("Grade: F (Fail)\n");

    /* ── switch-case: Day of Week ────────────────────────────────────── */
    printf("\n=== switch-case ===\n");
    int day = 3;
    switch (day) {
        case 1: printf("Monday\n");    break;
        case 2: printf("Tuesday\n");   break;
        case 3: printf("Wednesday\n"); break;
        case 4: printf("Thursday\n");  break;
        case 5: printf("Friday\n");    break;
        case 6: printf("Saturday\n");  break;
        case 7: printf("Sunday\n");    break;
        default: printf("Invalid day\n");
    }

    /* ── switch fall-through ─────────────────────────────────────────── */
    printf("\n=== switch fall-through (weekday check) ===\n");
    switch (day) {
        case 1: case 2: case 3: case 4: case 5:
            printf("Day %d is a Weekday\n", day); break;
        case 6: case 7:
            printf("Day %d is Weekend\n", day);   break;
        default:
            printf("Invalid\n");
    }

    /* ── Nested if ───────────────────────────────────────────────────── */
    printf("\n=== Nested if ===\n");
    int age = 20;
    int hasID = 1;
    if (age >= 18) {
        if (hasID) printf("Entry allowed (adult with ID)\n");
        else       printf("No ID — cannot enter\n");
    } else {
        printf("Too young to enter\n");
    }

    /* ── Ternary ─────────────────────────────────────────────────────── */
    printf("\n=== Ternary Operator ===\n");
    int n = -42;
    printf("Absolute value of %d = %d\n", n, (n < 0) ? -n : n);
    printf("Is %d even or odd? %s\n", score, (score % 2 == 0) ? "Even" : "Odd");

    return 0;
}
/*
OUTPUT:
=== if/else if/else ===
Score: 78
Grade: A (Excellent)
=== switch-case ===
Wednesday
...
*/
