/*
 * ===================================================================
 *  File    : Basic.c
 *  Topic   : 22 Advanced C
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
#include <string.h>
#include <setjmp.h>
#include <math.h>

/* ── Flexible Array Member ────────────────────────────────────────────── */
typedef struct {
    int    count;
    char   name[20];
    int    scores[];
} Student;

Student *create_student(const char *name, int n, int vals[]) {
    Student *s = malloc(sizeof(Student) + n * sizeof(int));
    s->count = n;
    strncpy(s->name, name, 19);
    for(int i=0;i<n;i++) s->scores[i]=vals[i];
    return s;
}

/* ── setjmp/longjmp — simple error recovery ───────────────────────────── */
jmp_buf error_env;

void parse_number(const char *s) {
    char *end;
    long val = strtol(s, &end, 10);
    if (*end != '\0') {
        printf("  parse_number: invalid input '%s' — jumping back!\n", s);
        longjmp(error_env, 1);
    }
    printf("  Parsed: %ld\n", val);
}

/* ── _Generic selection ────────────────────────────────────────────────── */
#define type_name(x) _Generic((x),  \
    int:          "int",            \
    long:         "long",           \
    float:        "float",          \
    double:       "double",         \
    char*:        "char*",          \
    default:      "other")

#define my_sqrt(x) _Generic((x),    \
    float:  sqrtf,                  \
    double: sqrt                    \
)(x)

int main(void) {
    /* ── Flexible array ───────────────────────────────────────────────── */
    printf("=== Flexible Array Member ===\n");
    int vals[] = {85,90,78,92,88};
    Student *s = create_student("Alice", 5, vals);
    printf("Student: %s (%d scores)\n", s->name, s->count);
    int total=0;
    for(int i=0;i<s->count;i++) { printf("  %d",s->scores[i]); total+=s->scores[i]; }
    printf("\nAverage: %.1f\n", (float)total/s->count);
    free(s);

    /* ── setjmp/longjmp ───────────────────────────────────────────────── */
    printf("\n=== setjmp / longjmp ===\n");
    if (setjmp(error_env) == 0) {
        printf("Parsing '42':\n");    parse_number("42");
        printf("Parsing '3.14':\n");  parse_number("3.14");  /* triggers longjmp */
        printf("This line never executes\n");
    } else {
        printf("  Recovered from parse error!\n");
    }

    /* ── _Generic ─────────────────────────────────────────────────────── */
    printf("\n=== _Generic (C11) ===\n");
    int    i = 42;
    double d = 3.14;
    float  f = 2.71f;
    char  *c = "hello";
    printf("type of i: %s\n", type_name(i));
    printf("type of d: %s\n", type_name(d));
    printf("type of f: %s\n", type_name(f));
    printf("type of c: %s\n", type_name(c));
    printf("sqrt(2.0f) = %.6f\n", my_sqrt(2.0f));
    printf("sqrt(2.0)  = %.10f\n", my_sqrt(2.0));

    /* ── Compound literals ────────────────────────────────────────────── */
    printf("\n=== Compound Literals ===\n");
    int *arr = (int[]){10,20,30,40,50};
    printf("Compound literal array: ");
    for(int j=0;j<5;j++) printf("%d ",arr[j]);
    printf("\n");

    /* ── Designated initializers ──────────────────────────────────────── */
    struct { int x,y,z; } point = { .x=10, .z=30 };  /* .y defaults to 0 */
    printf("\n=== Designated Initializers ===\n");
    printf("point = {x=%d, y=%d, z=%d}\n", point.x, point.y, point.z);

    return 0;
}
