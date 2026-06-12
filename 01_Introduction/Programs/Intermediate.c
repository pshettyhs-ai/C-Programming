/*
 * ===================================================================
 *  File    : Intermediate.c
 *  Topic   : 01 Introduction
 *  Level   : Intermediate
 *  Author  : PAVAN SHETTY H S
 *
 *  Notes   : Written as part of my personal C programming study.
 *            Comments explain the reasoning, not just the syntax.
 *            Run with: gcc Intermediate.c -o out -lm && ./out
 * ===================================================================
 */

#include <stdio.h>
#include <stdlib.h>   /* for EXIT_SUCCESS */

/* Macro constants — replaced by preprocessor, not stored in memory */
#define MAX_STUDENTS  50
#define PASS_MARK     40
#define GRADE_A       80
#define PI            3.14159265358979

/* ─────────────────────────────────────────────────────────────────────────
   PROGRAM 1: User Input with scanf
   Demonstrates reading different data types from stdin.
───────────────────────────────────────────────────────────────────────── */
void program1_user_input(void) {
    int    age;
    float  gpa;
    char   initial;
    char   name[50];

    printf("═══════════════════════════════════════\n");
    printf("  PROGRAM 1: User Input\n");
    printf("═══════════════════════════════════════\n");

    printf("Enter your name: ");
    scanf("%49s", name);          /* %49s prevents buffer overflow */

    printf("Enter your age: ");
    scanf("%d", &age);            /* & = address-of operator for scanf */

    printf("Enter your GPA (e.g. 8.5): ");
    scanf("%f", &gpa);            /* %f for float in scanf */

    printf("Enter your first initial: ");
    scanf(" %c", &initial);       /* space before %c skips whitespace */

    /* Print formatted summary */
    printf("\n┌───────────────────────────────┐\n");
    printf("│     Student Information        │\n");
    printf("├───────────────────────────────┤\n");
    printf("│ Name:    %-22s│\n", name);
    printf("│ Age:     %-22d│\n", age);
    printf("│ GPA:     %-22.2f│\n", gpa);
    printf("│ Initial: %-22c│\n", initial);
    printf("└───────────────────────────────┘\n");

    /* Grade determination */
    if (gpa >= 9.0)       printf("Grade: O (Outstanding)\n");
    else if (gpa >= 8.0)  printf("Grade: A+ (Excellent)\n");
    else if (gpa >= 7.0)  printf("Grade: A  (Very Good)\n");
    else if (gpa >= 6.0)  printf("Grade: B+ (Good)\n");
    else if (gpa >= 5.0)  printf("Grade: B  (Average)\n");
    else                  printf("Grade: F  (Fail)\n");
}

/* ─────────────────────────────────────────────────────────────────────────
   PROGRAM 2: Type Conversion
   Shows implicit (automatic) and explicit (cast) conversions.
───────────────────────────────────────────────────────────────────────── */
void program2_type_conversion(void) {
    printf("\n═══════════════════════════════════════\n");
    printf("  PROGRAM 2: Type Conversion\n");
    printf("═══════════════════════════════════════\n");

    /* IMPLICIT CONVERSION (widening — safe) */
    int    i = 65;
    float  f = i;      /* int → float: automatic, no data loss */
    double d = f;      /* float → double: automatic, no data loss */
    char   c = i;      /* int → char: automatic, value 65 = 'A' */

    printf("--- Implicit Conversion ---\n");
    printf("int i = %d\n", i);
    printf("float f = i → %.1f\n", f);
    printf("double d = f → %.1lf\n", d);
    printf("char c = i → '%c' (ASCII %d)\n", c, c);

    /* EXPLICIT CAST (narrowing — may lose data) */
    double pi = 3.99999;
    int    truncated = (int)pi;    /* Cast: double → int, fractional part lost */

    float  total  = 7.0f;
    int    count  = 2;
    float  avg1   = total / count;                 /* int/int = int then stored as float */
    float  avg2   = total / (float)count;          /* explicit cast for correct result */
    float  avg3   = (float)((int)total / count);   /* int division then cast */

    printf("\n--- Explicit (Cast) Conversion ---\n");
    printf("(int) 3.99999 = %d  ← truncated, NOT rounded!\n", truncated);
    printf("7.0f / 2     = %.2f  ← correct\n", avg1);
    printf("7.0f / (float)2 = %.2f\n", avg2);

    /* INTEGER OVERFLOW demonstration */
    unsigned char byte = 255;
    printf("\n--- Overflow Demo ---\n");
    printf("unsigned char = %u\n", byte);
    byte++;   /* 255 + 1 wraps around to 0 for unsigned! */
    printf("After ++:     %u  ← wrapped around!\n", byte);

    /* INTEGER PROMOTION */
    char a = 100, b = 200;
    int  result = a + b;   /* chars promoted to int before addition */
    printf("\n--- Integer Promotion ---\n");
    printf("char 100 + char 200 (as int) = %d\n", result);
}

/* ─────────────────────────────────────────────────────────────────────────
   PROGRAM 3: Constants — const vs #define
───────────────────────────────────────────────────────────────────────── */
void program3_constants(void) {
    printf("\n═══════════════════════════════════════\n");
    printf("  PROGRAM 3: Constants\n");
    printf("═══════════════════════════════════════\n");

    /* const variables — type-safe, have memory address, debuggable */
    const float TAX_RATE       = 0.18f;  /* 18% GST */
    const int   DAYS_IN_WEEK   = 7;

    /* #define macros — no memory, simple text replacement */
    /* PI and MAX_STUDENTS defined at top of file */

    float product_cost = 1500.0f;
    float tax_amount   = product_cost * TAX_RATE;
    float total_cost   = product_cost + tax_amount;

    printf("Product Cost:  ₹%.2f\n", product_cost);
    printf("Tax Rate:       %.0f%%\n", TAX_RATE * 100);
    printf("Tax Amount:    ₹%.2f\n", tax_amount);
    printf("Total Cost:    ₹%.2f\n", total_cost);
    printf("\nPI = %.10f\n", PI);
    printf("Max Students = %d\n", MAX_STUDENTS);
    printf("Days in Week = %d\n", DAYS_IN_WEEK);

    /* const vs #define:
       - const: has type, stored in memory, can be debugged
       - #define: no type, replaced before compilation, no memory
       - Prefer const for values, #define for compile flags */
}

/* ─────────────────────────────────────────────────────────────────────────
   PROGRAM 4: Simple Function Demonstration
───────────────────────────────────────────────────────────────────────── */

/* Function prototypes */
float celsius_to_fahrenheit(float c);
float fahrenheit_to_celsius(float f);
int   is_leap_year(int year);

void program4_functions(void) {
    printf("\n═══════════════════════════════════════\n");
    printf("  PROGRAM 4: Functions Demo\n");
    printf("═══════════════════════════════════════\n");

    /* Temperature conversions */
    float temps[] = { 0.0f, 25.0f, 37.0f, 100.0f };
    int n = sizeof(temps) / sizeof(temps[0]);

    printf("%-12s %-15s\n", "Celsius", "Fahrenheit");
    printf("%-12s %-15s\n", "───────", "──────────");
    for (int i = 0; i < n; i++) {
        printf("%-12.1f %-15.1f\n",
               temps[i],
               celsius_to_fahrenheit(temps[i]));
    }

    /* Leap year checker */
    printf("\nLeap Year Check:\n");
    int years[] = { 2000, 1900, 2024, 2023 };
    for (int i = 0; i < 4; i++) {
        printf("%d → %s\n", years[i],
               is_leap_year(years[i]) ? "LEAP YEAR" : "Not a leap year");
    }
}

float celsius_to_fahrenheit(float c) {
    return (c * 9.0f / 5.0f) + 32.0f;
}

float fahrenheit_to_celsius(float f) {
    return (f - 32.0f) * 5.0f / 9.0f;
}

int is_leap_year(int year) {
    /* A year is leap if:
       divisible by 4, EXCEPT century years must be divisible by 400 */
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

/* ─────────────────────────────────────────────────────────────────────────
   MAIN
───────────────────────────────────────────────────────────────────────── */
int main(void) {
    /* Comment out input-based programs if running non-interactively */
    /* program1_user_input(); */
    program2_type_conversion();
    program3_constants();
    program4_functions();

    return EXIT_SUCCESS;
}
