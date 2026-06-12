/*
 * ===================================================================
 *  File    : Basic.c
 *  Topic   : 04 Input Output
 *  Level   : Beginner
 *  Author  : PAVAN SHETTY H S
 *
 *  Notes   : Written as part of my personal C programming study.
 *            Comments explain the reasoning, not just the syntax.
 *            Run with: gcc Basic.c -o out -lm && ./out
 * ===================================================================
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    /* ── printf format specifiers ──────────────────────────────────── */
    printf("=== printf Format Specifiers ===\n");
    printf("Integer:     %d\n",  42);
    printf("Float:       %.2f\n", 3.14159);
    printf("Char:        %c\n",  'A');
    printf("String:      %s\n",  "Hello, C!");
    printf("Hex:         %x  (0x%X)\n", 255, 255);
    printf("Octal:       %o\n",  8);
    printf("Sci:         %e\n",  12345.6789);
    printf("Pointer:     %p\n",  (void*)&main);

    /* ── Width and alignment ────────────────────────────────────────── */
    printf("\n=== Width and Precision ===\n");
    printf("[%10d]\n",   42);    /* right-aligned, width 10 */
    printf("[%-10d]\n",  42);    /* left-aligned */
    printf("[%010d]\n",  42);    /* zero-padded */
    printf("[%+d]\n",    42);    /* always show sign */
    printf("[%.5f]\n",   3.14);  /* 5 decimal places */
    printf("[%10.3f]\n", 3.14);  /* width 10, 3 decimals */

    /* ── User input (interactive) ───────────────────────────────────── */
    printf("\n=== User Input Demo ===\n");
    int age;
    float gpa;
    char name[50];

    printf("Enter name: ");
    scanf("%49s", name);

    printf("Enter age: ");
    scanf("%d", &age);

    printf("Enter GPA: ");
    scanf("%f", &gpa);

    printf("\nHello, %s! Age: %d, GPA: %.2f\n", name, age, gpa);

    /* ── scanf return value check ───────────────────────────────────── */
    int a, b;
    printf("\nEnter two integers: ");
    int ret = scanf("%d %d", &a, &b);
    if (ret == 2)
        printf("Sum = %d\n", a + b);
    else
        printf("Invalid input (got %d items)\n", ret);

    return 0;
}
