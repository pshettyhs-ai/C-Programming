/*
 * ===================================================================
 *  File    : Basic.c
 *  Topic   : 19 Command Line Arguments
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

int main(int argc, char *argv[]) {
    printf("=== Command Line Arguments ===\n");
    printf("argc = %d\n", argc);
    for (int i = 0; i < argc; i++)
        printf("argv[%d] = \"%s\"\n", i, argv[i]);

    if (argc == 1) {
        printf("\nRun with arguments: ./Basic hello 42 3.14\n");
        return 0;
    }

    printf("\n=== Parsing Arguments ===\n");
    /* Parse flags and values */
    int verbose = 0;
    int number  = 0;
    char *mode  = "default";

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-v") == 0) {
            verbose = 1;
            printf("Verbose mode ON\n");
        } else if (strcmp(argv[i], "-n") == 0 && i+1 < argc) {
            number = atoi(argv[++i]);
            printf("Number set to: %d\n", number);
        } else {
            mode = argv[i];
            printf("Mode: %s\n", mode);
        }
    }

    printf("\n=== Type Conversions ===\n");
    if (argc > 1) {
        /* Convert to different types */
        char *endptr;
        long  l = strtol(argv[1], &endptr, 10);
        if (*endptr == '\0')
            printf("argv[1] as long:   %ld\n", l);
        else
            printf("argv[1] as string: %s\n", argv[1]);
    }
    if (argc > 2) {
        double d = strtod(argv[2], NULL);
        printf("argv[2] as double: %.4f\n", d);
    }

    if (verbose) {
        printf("\n[VERBOSE] Program: %s\n", argv[0]);
        printf("[VERBOSE] Total args: %d\n", argc - 1);
    }

    return 0;
}
/*
Run: ./Basic -v -n 5 compute
OUTPUT:
=== Command Line Arguments ===
argc = 5
argv[0] = "./Basic"
argv[1] = "-v"
argv[2] = "-n"
argv[3] = "5"
argv[4] = "compute"
Verbose mode ON
Number set to: 5
Mode: compute
*/
