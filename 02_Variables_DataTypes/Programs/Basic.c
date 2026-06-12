/*
 * ===================================================================
 *  File    : Basic.c
 *  Topic   : 02 Variables DataTypes
 *  Level   : Beginner
 *  Author  : PAVAN SHETTY H S
 *
 *  Notes   : Written as part of my personal C programming study.
 *            Comments explain the reasoning, not just the syntax.
 *            Run with: gcc Basic.c -o out -lm && ./out
 * ===================================================================
 */

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void) {
    /* ── Integer Types ─────────────────────────────────────────────── */
    char           c  = 'Z';
    short          s  = -1000;
    int            i  = 2147483647;
    long           l  = 1234567890L;
    long long      ll = 9876543210LL;
    unsigned int   ui = 4294967295U;

    printf("=== Integer Types ===\n");
    printf("char:       %c  (ASCII %d)\n", c, c);
    printf("short:      %d\n",  s);
    printf("int:        %d\n",  i);
    printf("long:       %ld\n", l);
    printf("long long:  %lld\n",ll);
    printf("uint:       %u\n",  ui);

    /* ── Floating-Point Types ──────────────────────────────────────── */
    float       f  = 3.14f;
    double      d  = 3.141592653589793;
    long double ld = 3.14159265358979323846L;

    printf("\n=== Floating-Point Types ===\n");
    printf("float:       %.7f\n",   f);
    printf("double:      %.15lf\n", d);
    printf("long double: %.19Lf\n", ld);

    /* ── Type Ranges ───────────────────────────────────────────────── */
    printf("\n=== Type Ranges ===\n");
    printf("INT_MAX  = %d\n",  INT_MAX);
    printf("INT_MIN  = %d\n",  INT_MIN);
    printf("UINT_MAX = %u\n",  UINT_MAX);
    printf("CHAR_MAX = %d\n",  CHAR_MAX);
    printf("DBL_DIG  = %d decimal digits of precision\n", DBL_DIG);

    /* ── Multiple Assignments ──────────────────────────────────────── */
    int a, b, x;
    a = b = x = 10;   /* chained assignment — right to left */
    printf("\na = b = x = %d (each)\n", a);

    return 0;
}
/*
OUTPUT (64-bit Linux):
=== Integer Types ===
char:       Z  (ASCII 90)
short:      -1000
int:        2147483647
long:       1234567890
long long:  9876543210
uint:       4294967295

=== Floating-Point Types ===
float:       3.1400001
double:      3.141592653589793
long double: 3.14159265358979323851
...
*/
