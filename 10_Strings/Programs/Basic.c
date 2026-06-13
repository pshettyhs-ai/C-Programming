/*
 * ===================================================================
 *  File    : Basic.c
 *  Topic   : 10 Strings
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
#include <ctype.h>

void reverse_str(char *s) {
    int lo=0, hi=strlen(s)-1;
    while(lo<hi){char t=s[lo];s[lo]=s[hi];s[hi]=t;lo++;hi--;}
}
int is_palindrome(const char *s) {
    int lo=0,hi=strlen(s)-1;
    while(lo<hi) if(s[lo++]!=s[hi--]) return 0;
    return 1;
}

int main(void) {
    char s1[] = "Hello, World!";
    printf("=== Basic String Operations ===\n");
    printf("String: \"%s\"\n", s1);
    printf("Length: %zu\n",  strlen(s1));
    printf("sizeof: %zu\n",  sizeof(s1));

    /* Copy and concatenation */
    char dest[50];
    strcpy(dest, "Hello");
    strcat(dest, ", C!");
    printf("After strcat: \"%s\"\n", dest);

    /* Comparison */
    printf("\n=== Comparison ===\n");
    printf("strcmp(\"abc\",\"abc\") = %d\n", strcmp("abc","abc"));
    printf("strcmp(\"abc\",\"abd\") = %d\n", strcmp("abc","abd"));
    printf("strcmp(\"abd\",\"abc\") = %d\n", strcmp("abd","abc"));

    /* Search */
    printf("\n=== Search ===\n");
    char text[] = "C programming is fun";
    char *found = strstr(text, "gram");
    printf("strstr for 'gram': %s\n", found ? found : "Not found");
    printf("strchr for 'p': %c\n", *strchr(text,'p'));

    /* Reverse */
    char word[] = "abcde";
    printf("\n=== Reverse ===\n");
    printf("Before: %s\n", word);
    reverse_str(word);
    printf("After:  %s\n", word);

    /* Palindrome check */
    printf("\n=== Palindrome ===\n");
    const char *tests[] = {"racecar","hello","madam","world","level"};
    for(int i=0;i<5;i++)
        printf("%-10s → %s\n", tests[i], is_palindrome(tests[i])?"Yes":"No");

    /* Case conversion */
    printf("\n=== Case Conversion ===\n");
    char mix[] = "Hello World";
    for(int i=0;mix[i];i++) mix[i]=toupper(mix[i]);
    printf("Uppercase: %s\n", mix);
    for(int i=0;mix[i];i++) mix[i]=tolower(mix[i]);
    printf("Lowercase: %s\n", mix);

    /* strtok */
    printf("\n=== Tokenize (CSV) ===\n");
    char csv[] = "Alice,25,Engineering,Mumbai";
    char *tok = strtok(csv, ",");
    int col=1;
    while(tok){printf("Field %d: %s\n",col++,tok);tok=strtok(NULL,",");}

    return 0;
}
