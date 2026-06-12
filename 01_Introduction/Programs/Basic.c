/*
 * ===================================================================
 *  File    : Basic.c
 *  Topic   : 01 Introduction
 *  Level   : Beginner
 *  Author  : PAVAN SHETTY H S
 *
 *  Notes   : Written as part of my personal C programming study.
 *            Comments explain the reasoning, not just the syntax.
 *            Run with: gcc Basic.c -o out -lm && ./out
 * ===================================================================
 */

#include <stdio.h>    /* we need this for printf() */



void program1_hello_world(void)
{
    printf("--- Program 1: Hello, World! ---\n");

    printf("Hello, World!\n");
    printf("My name is Pavan Shetty H S\n");
    printf("I am learning C programming.\n");

    /*
     * Expected output:
     *   Hello, World!
     *   My name is Pavan Shetty H S
     *   I am learning C programming.
     */
}


void program2_printing(void)
{
    printf("\n--- Program 2: Printing Text ---\n");

    /* Three separate printf calls */
    printf("Line 1\n");
    printf("Line 2\n");
    printf("Line 3\n");

    /* One printf can print many lines using \n */
    printf("\nAll in one printf:\nApple\nBanana\nCherry\n");

    /* Tab character \t helps align output nicely */
    printf("\nName\t\tAge\tCity\n");
    printf("Pavan\t\t21\tMangalore\n");
    printf("Ravi\t\t22\tBangalore\n");
    printf("Priya\t\t20\tHubli\n");
}



void program3_arithmetic(void)
{
    printf("\n--- Program 3: Arithmetic ---\n");

    int a = 7, b = 2;

    printf("a = %d, b = %d\n\n", a, b);
    printf("a + b = %d\n", a + b);    /* addition */
    printf("a - b = %d\n", a - b);    /* subtraction */
    printf("a * b = %d\n", a * b);    /* multiplication */
    printf("a / b = %d\n", a / b);    /* integer division — drops remainder */
    printf("a %% b = %d\n", a % b);   /* modulo — gives the remainder only */

    /*
     * %% prints a literal % sign.
     * Without it, printf would think it is a format specifier.
     *
     * 7 / 2 = 3 (NOT 3.5) because both values are integers.
     * 7 % 2 = 1 because 7 = 2*3 + 1, so the remainder is 1.
     */

    printf("\nWith floats:\n");
    printf("7.0 / 2.0 = %.2f\n", 7.0 / 2.0);   /* now we get 3.50 */
}



void program4_sizeof(void)
{
    printf("\n--- Program 4: sizeof Operator ---\n");

    printf("%-20s %s\n", "Type", "Size (bytes)");
    printf("%-20s %s\n", "----", "------------");

    printf("%-20s %zu\n", "char",        sizeof(char));
    printf("%-20s %zu\n", "short",       sizeof(short));
    printf("%-20s %zu\n", "int",         sizeof(int));
    printf("%-20s %zu\n", "long",        sizeof(long));
    printf("%-20s %zu\n", "long long",   sizeof(long long));
    printf("%-20s %zu\n", "float",       sizeof(float));
    printf("%-20s %zu\n", "double",      sizeof(double));
    printf("%-20s %zu\n", "pointer",     sizeof(void *));

    /*
     * Typical output on a 64-bit Linux system:
     *   char                 1
     *   short                2
     *   int                  4
     *   long                 8
     *   long long            8
     *   float                4
     *   double               8
     *   pointer              8
     */
}



void program5_escape_sequences(void)
{
    printf("\n--- Program 5: Escape Sequences ---\n");

    printf("Newline demo:\nThis is the second line.\n");
    printf("Tab demo:\tColumn1\tColumn2\tColumn3\n");
    printf("Backslash: C:\\Users\\Pavan\\Documents\\\n");
    printf("Double quote: He said, \"Hello!\"\n");
    printf("Percent sign: Scored 95%%\n");

    /* \0 is the null character — it terminates strings */
    /* printf stops printing when it hits \0 in a string */
    printf("String stops at null: ABC\0XYZ\n");   /* prints: ABC */
}



int main(void)
{
    program1_hello_world();
    program2_printing();
    program3_arithmetic();
    program4_sizeof();
    program5_escape_sequences();

    printf("\n--- All basic programs finished ---\n");
    return 0;
}
