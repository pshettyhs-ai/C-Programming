/*
 * ===================================================================
 *  File    : Advanced.c
 *  Topic   : 10 Strings
 *  Level   : Advanced
 *  Author  : PAVAN SHETTY H S
 *
 *  Notes   : Written as part of my personal C programming study.
 *            Comments explain the reasoning, not just the syntax.
 *            Run with: gcc Advanced.c -o out -lm && ./out
 * ===================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* ── 1. KMP string search — O(n+m) ───────────────────────────────────── */
void build_lps(const char *pat, int m, int *lps) {
    lps[0] = 0; int len = 0, i = 1;
    while (i < m) {
        if (pat[i] == pat[len]) { lps[i++] = ++len; }
        else if (len) len = lps[len-1];
        else lps[i++] = 0;
    }
}

void kmp_search(const char *text, const char *pat) {
    int n=strlen(text), m=strlen(pat);
    int *lps = malloc(m*sizeof(int));
    build_lps(pat, m, lps);
    int i=0,j=0,found=0;
    while (i < n) {
        if (text[i]==pat[j]) { i++; j++; }
        if (j==m) { printf("  Found at index %d\n",i-j); j=lps[j-1]; found++; }
        else if (i<n && text[i]!=pat[j]) {
            if (j) j=lps[j-1]; else i++;
        }
    }
    if (!found) printf("  Pattern not found\n");
    free(lps);
}

/* ── 2. Longest palindromic substring — O(n²) ────────────────────────── */
void longest_palindrome(const char *s, int *start, int *maxlen) {
    int n = strlen(s);
    *start = 0; *maxlen = 1;
    for (int i=0;i<n;i++) {
        /* Odd length */
        int l=i,r=i;
        while(l>=0&&r<n&&s[l]==s[r]){l--;r++;}
        if(r-l-1>*maxlen){*maxlen=r-l-1;*start=l+1;}
        /* Even length */
        l=i;r=i+1;
        while(l>=0&&r<n&&s[l]==s[r]){l--;r++;}
        if(r-l-1>*maxlen){*maxlen=r-l-1;*start=l+1;}
    }
}

/* ── 3. Simple tokenizer / CSV parser ────────────────────────────────── */
typedef struct { char **fields; int count; } Row;

Row parse_csv_line(const char *line) {
    Row row = { malloc(50 * sizeof(char*)), 0 };
    char *copy = strdup(line);
    char *tok = strtok(copy, ",");
    while (tok && row.count < 50) {
        /* trim leading whitespace */
        while (*tok == ' ') tok++;
        row.fields[row.count++] = strdup(tok);
        tok = strtok(NULL, ",");
    }
    free(copy);
    return row;
}
void free_row(Row *r){for(int i=0;i<r->count;i++)free(r->fields[i]);free(r->fields);}

/* ── 4. String compression ────────────────────────────────────────────── */
int compress(const char *s, char *out, int max_out) {
    int i=0, n=strlen(s);
    char *p=out;
    while(i<n&&(p-out)<max_out-3){
        char c=s[i]; int cnt=0;
        while(i<n&&s[i]==c){i++;cnt++;}
        if(cnt>1) p+=sprintf(p,"%c%d",c,cnt);
        else *p++=c;
    }
    *p='\0';
    return strlen(out) < strlen(s);  /* return 1 if compression helped */
}

int main(void) {
    printf("=== KMP String Search ===\n");
    const char *text="AABAACAADAABAABA";
    const char *patterns[]={"AABA","AAA","BAAC"};
    for(int i=0;i<3;i++){
        printf("Search '%s' in '%s':\n",patterns[i],text);
        kmp_search(text,patterns[i]);
    }

    printf("\n=== Longest Palindromic Substring ===\n");
    const char *tests[]={"babad","cbbd","racecar","abacaba","noon"};
    for(int i=0;i<5;i++){
        int start,maxlen;
        longest_palindrome(tests[i],&start,&maxlen);
        printf("'%s' → '%.*s' (len=%d)\n",tests[i],maxlen,tests[i]+start,maxlen);
    }

    printf("\n=== CSV Parser ===\n");
    const char *csv_lines[]={
        "Alice Johnson, 101, CSE, 9.2",
        "Bob Kumar, 102, ECE, 8.5",
        "Carol Singh, 103, ME, 7.9",
    };
    for(int i=0;i<3;i++){
        Row r=parse_csv_line(csv_lines[i]);
        printf("Row %d: ",i+1);
        for(int j=0;j<r.count;j++) printf("[%s]",r.fields[j]);
        printf("\n");
        free_row(&r);
    }

    printf("\n=== String Compression ===\n");
    const char *inputs[]={"aaabbbccc","abcdef","aaaaaaaa","aabbccdd"};
    for(int i=0;i<4;i++){
        char out[100];
        int compressed=compress(inputs[i],out,100);
        printf("'%s' → '%s' (%s)\n",inputs[i],out,compressed?"compressed":"no gain");
    }

    return 0;
}
