/*
 * ===================================================================
 *  File    : Intermediate.c
 *  Topic   : 10 Strings
 *  Level   : Intermediate
 *  Author  : PAVAN SHETTY H S
 *
 *  Notes   : Written as part of my personal C programming study.
 *            Comments explain the reasoning, not just the syntax.
 *            Run with: gcc Intermediate.c -o out -lm && ./out
 * ===================================================================
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/* Anagram check */
int are_anagrams(const char *s1, const char *s2) {
    if (strlen(s1) != strlen(s2)) return 0;
    int freq[256] = {0};
    for (; *s1; s1++) freq[(unsigned char)*s1]++;
    for (; *s2; s2++) freq[(unsigned char)*s2]--;
    for (int i=0;i<256;i++) if(freq[i]) return 0;
    return 1;
}

/* Count words */
int word_count(const char *s) {
    int count = 0, in_word = 0;
    for (; *s; s++) {
        if (isspace(*s)) in_word = 0;
        else if (!in_word) { in_word = 1; count++; }
    }
    return count;
}

/* Title case */
void to_title_case(char *s) {
    int new_word = 1;
    for (; *s; s++) {
        if (isspace(*s)) new_word = 1;
        else if (new_word) { *s = toupper(*s); new_word = 0; }
        else *s = tolower(*s);
    }
}

/* Run-Length Encoding */
void rle_encode(const char *in, char *out) {
    int i = 0;
    while (*in) {
        char c = *in; int count = 0;
        while (*in == c) { in++; count++; }
        if (count > 1) i += sprintf(out+i, "%d%c", count, c);
        else out[i++] = c;
    }
    out[i] = '\0';
}

/* Caesar cipher */
void caesar(char *s, int shift) {
    shift = ((shift % 26) + 26) % 26;
    for (; *s; s++) {
        if (isupper(*s)) *s = 'A' + (*s - 'A' + shift) % 26;
        else if (islower(*s)) *s = 'a' + (*s - 'a' + shift) % 26;
    }
}

/* Longest common prefix */
void longest_common_prefix(const char *words[], int n, char *out) {
    strcpy(out, words[0]);
    for (int i = 1; i < n; i++) {
        int j = 0;
        while (out[j] && words[i][j] && out[j] == words[i][j]) j++;
        out[j] = '\0';
    }
}

int main(void) {
    printf("=== Anagram Check ===\n");
    printf("'listen','silent' : %s\n", are_anagrams("listen","silent")?"YES":"NO");
    printf("'hello','world'   : %s\n", are_anagrams("hello","world")?"YES":"NO");
    printf("'triangle','integral': %s\n",are_anagrams("triangle","integral")?"YES":"NO");

    printf("\n=== Word Count ===\n");
    const char *texts[]={"Hello World","  spaces   everywhere  ","one","a b c d e f"};
    for(int i=0;i<4;i++)
        printf("\"%s\" → %d words\n",texts[i],word_count(texts[i]));

    printf("\n=== Title Case ===\n");
    char title[]="the quick brown fox jumps over the lazy dog";
    printf("Before: %s\n",title);
    to_title_case(title);
    printf("After:  %s\n",title);

    printf("\n=== Run-Length Encoding ===\n");
    const char *inputs[]={"aaabbbcc","aabcdddd","abcdef","AAAAABBBB"};
    for(int i=0;i<4;i++){
        char out[100];
        rle_encode(inputs[i],out);
        printf("'%s' → '%s'\n",inputs[i],out);
    }

    printf("\n=== Caesar Cipher ===\n");
    char msg[]="Hello, World!";
    printf("Original:  %s\n",msg);
    caesar(msg,13);
    printf("ROT13:     %s\n",msg);
    caesar(msg,13);
    printf("Decoded:   %s\n",msg);

    printf("\n=== Longest Common Prefix ===\n");
    const char *words[]={"flower","flow","flight"};
    char prefix[50];
    longest_common_prefix(words,3,prefix);
    printf("Words: flower, flow, flight\nLCP: '%s'\n",prefix);

    return 0;
}
