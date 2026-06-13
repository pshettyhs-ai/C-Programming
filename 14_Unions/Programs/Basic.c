/*
 * ===================================================================
 *  File    : Basic.c
 *  Topic   : 14 Unions
 *  Level   : Beginner
 *  Author  : PAVAN SHETTY H S
 *
 *  Notes   : Written as part of my personal C programming study.
 *            Comments explain the reasoning, not just the syntax.
 *            Run with: gcc Basic.c -o out -lm && ./out
 * ===================================================================
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>

union Data {
    int    i;
    float  f;
    char   str[20];
};

/* Tagged union — safe variant type */
typedef enum { T_INT, T_FLOAT, T_STRING } Tag;
typedef struct {
    Tag tag;
    union { int i; float f; char s[32]; } val;
} Variant;

void print_variant(const Variant *v) {
    switch(v->tag) {
        case T_INT:    printf("int:   %d\n",   v->val.i); break;
        case T_FLOAT:  printf("float: %.2f\n", v->val.f); break;
        case T_STRING: printf("str:   %s\n",   v->val.s); break;
    }
}

int main(void) {
    printf("=== Union Basics ===\n");
    union Data d;
    printf("sizeof(union Data) = %zu\n", sizeof(d));

    d.i = 100;   printf("d.i = %d\n", d.i);
    d.f = 99.9f; printf("d.f = %.1f (d.i is now garbage: %d)\n", d.f, d.i);
    strcpy(d.str, "Hello"); printf("d.str = %s\n", d.str);

    printf("\n=== Tagged Union (Variant Type) ===\n");
    Variant vars[3] = {
        {T_INT,    .val.i = 42},
        {T_FLOAT,  .val.f = 3.14f},
        {T_STRING, .val.s = "C Programming"},
    };
    for(int i=0;i<3;i++) print_variant(&vars[i]);

    printf("\n=== Type Punning (Float Bits) ===\n");
    union { float f; uint32_t u; } fb;
    fb.f = 1.0f;
    printf("1.0f in IEEE 754: 0x%08X\n", fb.u);
    fb.f = -0.0f;
    printf("-0.0f in IEEE 754: 0x%08X\n", fb.u);

    printf("\n=== Endianness Detection ===\n");
    union { uint32_t w; uint8_t b[4]; } e = { .w = 0x01020304 };
    printf("System is %s-endian\n", e.b[0]==0x04 ? "little" : "big");

    return 0;
}
