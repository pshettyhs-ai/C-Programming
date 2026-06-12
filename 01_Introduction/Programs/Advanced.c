/*
 * ===================================================================
 *  File    : Advanced.c
 *  Topic   : 01 Introduction
 *  Level   : Advanced
 *  Author  : PAVAN SHETTY H S
 *
 *  Notes   : Written as part of my personal C programming study.
 *            Comments explain the reasoning, not just the syntax.
 *            Run with: gcc Advanced.c -o out -lm && ./out
 * ===================================================================
 */

#include <stdio.h>
#include <stdarg.h>    /* for variadic functions: va_list, va_arg */
#include <string.h>
#include <time.h>

/* ─────────────────────────────────────────────────────────────────────────
   PROGRAM 1: Preprocessor and Conditional Compilation
   Demonstrates advanced preprocessor features.
───────────────────────────────────────────────────────────────────────── */

/* Stringify macro — converts token to string literal */
#define STRINGIFY(x)    #x
#define TOSTRING(x)     STRINGIFY(x)

/* Token pasting — joins two tokens */
#define MAKE_VAR(prefix, num)  prefix##num

/* Function-like macro with multiple statements (safe with do-while) */
#define SAFE_FREE(ptr) do { \
    if ((ptr) != NULL) {    \
        free(ptr);          \
        (ptr) = NULL;       \
    }                       \
} while (0)

/* Debug macro — prints file, line, function info */
#define DEBUG_PRINT(fmt, ...) \
    fprintf(stderr, "[DEBUG] %s:%d (%s): " fmt "\n", \
            __FILE__, __LINE__, __func__, ##__VA_ARGS__)

void program1_preprocessor(void) {
    printf("═══════════════════════════════════════════\n");
    printf("  PROGRAM 1: Preprocessor Features\n");
    printf("═══════════════════════════════════════════\n");

    /* Predefined macros */
    printf("File:        %s\n",     __FILE__);
    printf("Line:        %d\n",     __LINE__);
    printf("Function:    %s\n",     __func__);
    printf("Date:        %s\n",     __DATE__);
    printf("Time:        %s\n",     __TIME__);
    printf("C Standard:  %ld\n",    __STDC_VERSION__);  /* 201112L = C11 */

    /* Stringify macro */
    int MAKE_VAR(my, Var) = 42;    /* Creates variable: myVar */
    printf("\nStringified: %s\n",  TOSTRING(3.14));
    printf("myVar = %d\n",         myVar);

    /* Platform detection */
    printf("\nPlatform Detection:\n");
#if defined(_WIN32) || defined(_WIN64)
    printf("  Platform: Windows\n");
#elif defined(__linux__)
    printf("  Platform: Linux\n");
#elif defined(__APPLE__)
    printf("  Platform: macOS\n");
#else
    printf("  Platform: Unknown Unix-like\n");
#endif

#if __SIZEOF_POINTER__ == 8
    printf("  Architecture: 64-bit\n");
#else
    printf("  Architecture: 32-bit\n");
#endif

    DEBUG_PRINT("Preprocessor demo complete, value = %d", myVar);
}

/* ─────────────────────────────────────────────────────────────────────────
   PROGRAM 2: Variadic Functions
   Shows how to write functions that accept variable number of arguments.
   This is how printf itself works!
   Time Complexity: O(n) where n = number of arguments
───────────────────────────────────────────────────────────────────────── */

/* Custom variadic sum function */
int variadic_sum(int count, ...) {
    va_list args;           /* Declare argument list */
    va_start(args, count);  /* Initialize after last named param */

    int total = 0;
    for (int i = 0; i < count; i++) {
        total += va_arg(args, int);   /* Get next int argument */
    }

    va_end(args);           /* Clean up */
    return total;
}

/* Custom variadic logger */
void log_message(const char *level, const char *fmt, ...) {
    time_t now = time(NULL);
    char time_str[20];
    strftime(time_str, sizeof(time_str), "%H:%M:%S", localtime(&now));

    printf("[%s] [%s] ", time_str, level);

    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);     /* vprintf accepts va_list */
    va_end(args);
    printf("\n");
}

void program2_variadic(void) {
    printf("\n═══════════════════════════════════════════\n");
    printf("  PROGRAM 2: Variadic Functions\n");
    printf("═══════════════════════════════════════════\n");

    printf("Sum of 3 nums (1,2,3):     %d\n", variadic_sum(3, 1, 2, 3));
    printf("Sum of 5 nums (1..5):      %d\n", variadic_sum(5, 1, 2, 3, 4, 5));
    printf("Sum of 1 num  (99):        %d\n", variadic_sum(1, 99));

    printf("\nCustom Logger:\n");
    log_message("INFO",  "Server started on port %d", 8080);
    log_message("WARN",  "Memory usage at %.1f%%", 85.5);
    log_message("ERROR", "Failed to open file: %s", "data.txt");
}

/* ─────────────────────────────────────────────────────────────────────────
   PROGRAM 3: Function Pointer Dispatch Table
   Advanced use of function pointers for command dispatch.
   Time Complexity: O(1) for lookup
   Space Complexity: O(n) for n commands
───────────────────────────────────────────────────────────────────────── */

/* Operations — each has same signature */
void op_add(double a, double b)  { printf("%.4g + %.4g = %.4g\n", a,b,a+b); }
void op_sub(double a, double b)  { printf("%.4g - %.4g = %.4g\n", a,b,a-b); }
void op_mul(double a, double b)  { printf("%.4g × %.4g = %.4g\n", a,b,a*b); }
void op_div(double a, double b)  {
    if (b == 0) { printf("Error: Division by zero!\n"); return; }
    printf("%.4g ÷ %.4g = %.4g\n", a, b, a/b);
}

/* Dispatch table: map name → function pointer */
typedef struct {
    const char *name;
    void (*func)(double, double);
} Operation;

static Operation dispatch_table[] = {
    { "add",      op_add },
    { "subtract", op_sub },
    { "multiply", op_mul },
    { "divide",   op_div },
};
static int num_ops = sizeof(dispatch_table) / sizeof(dispatch_table[0]);

void execute_operation(const char *name, double a, double b) {
    for (int i = 0; i < num_ops; i++) {
        if (strcmp(dispatch_table[i].name, name) == 0) {
            dispatch_table[i].func(a, b);
            return;
        }
    }
    printf("Unknown operation: %s\n", name);
}

void program3_dispatch_table(void) {
    printf("\n═══════════════════════════════════════════\n");
    printf("  PROGRAM 3: Function Pointer Dispatch Table\n");
    printf("═══════════════════════════════════════════\n");

    execute_operation("add",      10.5, 4.5);
    execute_operation("subtract", 10.5, 4.5);
    execute_operation("multiply", 10.5, 4.5);
    execute_operation("divide",   10.5, 4.5);
    execute_operation("divide",   10.5, 0.0);
    execute_operation("modulo",   10.0, 3.0);   /* unknown */

    /* Available operations */
    printf("\nAvailable operations:\n");
    for (int i = 0; i < num_ops; i++) {
        printf("  [%d] %s → %p\n", i+1, dispatch_table[i].name,
               (void *)dispatch_table[i].func);
    }
}

/* ─────────────────────────────────────────────────────────────────────────
   MAIN
───────────────────────────────────────────────────────────────────────── */
int main(void) {
    program1_preprocessor();
    program2_variadic();
    program3_dispatch_table();

    printf("\n✓ Advanced Introduction programs completed.\n");
    return 0;
}
