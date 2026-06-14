/*
 * ===================================================================
 *  File    : Basic.c
 *  Topic   : 18 Preprocessor Directives
 *  Level   : Beginner
 *  Author  : PAVAN SHETTY H S
 *
 *  Notes   : Written as part of my personal C programming study.
 *            Comments explain the reasoning, not just the syntax.
 *            Run with: gcc Basic.c -o out -lm && ./out
 * ===================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/* Constants */
#define PI          3.14159265358979
#define MAX_ITEMS   10
#define APP_VERSION "2.4.1"

/* Safe macros with full parenthesization */
#define SQUARE(x)   ((x)*(x))
#define CUBE(x)     ((x)*(x)*(x))
#define MAX(a,b)    ((a)>(b)?(a):(b))
#define MIN(a,b)    ((a)<(b)?(a):(b))
#define ABS(x)      ((x)<0?-(x):(x))
#define CLAMP(v,lo,hi) MAX((lo),MIN((hi),(v)))

/* Safe multi-statement macro using do-while trick */
#define SWAP(T,a,b) do { T _tmp=(a); (a)=(b); (b)=_tmp; } while(0)

/* Debug macro — active only when compiled with -DDEBUG */
#ifdef DEBUG
#define DBG(fmt,...) fprintf(stderr,"[DBG] %s:%d: " fmt "\n",__FILE__,__LINE__,##__VA_ARGS__)
#else
#define DBG(fmt,...)
#endif

/* Stringify */
#define STR(x)  #x
#define XSTR(x) STR(x)

int main(void) {
    printf("=== Constants and Macros ===\n");
    printf("App Version: %s\n", APP_VERSION);
    printf("PI = %.10f\n", PI);
    printf("MAX_ITEMS = %d\n", MAX_ITEMS);

    printf("\n=== Function-like Macros ===\n");
    int x = 5;
    printf("SQUARE(%d)  = %d\n", x, SQUARE(x));
    printf("CUBE(%d)    = %d\n", x, CUBE(x));
    printf("MAX(3,7)   = %d\n", MAX(3,7));
    printf("ABS(-42)   = %d\n", ABS(-42));
    printf("CLAMP(150,0,100) = %d\n", CLAMP(150,0,100));

    printf("\n=== SWAP Macro ===\n");
    int a=10,b=20;
    printf("Before: a=%d b=%d\n",a,b);
    SWAP(int,a,b);
    printf("After:  a=%d b=%d\n",a,b);

    double p=1.5,q=9.9;
    SWAP(double,p,q);
    printf("Doubles swapped: p=%.1f q=%.1f\n",p,q);

    printf("\n=== Predefined Macros ===\n");
    printf("File:    %s\n", __FILE__);
    printf("Line:    %d\n", __LINE__);
    printf("Func:    %s\n", __func__);
    printf("Date:    %s\n", __DATE__);
    printf("Time:    %s\n", __TIME__);

    printf("\n=== Conditional Compilation ===\n");
#ifdef DEBUG
    printf("DEBUG mode: extra logging enabled\n");
    DBG("x=%d, a=%d, b=%d", x, a, b);
#else
    printf("RELEASE mode: no debug output\n");
#endif

    printf("\n=== Stringify ===\n");
    printf("STR(PI)  = %s\n",  STR(PI));
    printf("XSTR(PI) = %s\n", XSTR(PI));   /* expands PI first */
    printf("STR(MAX_ITEMS) = %s\n", STR(MAX_ITEMS));

    return 0;
}
