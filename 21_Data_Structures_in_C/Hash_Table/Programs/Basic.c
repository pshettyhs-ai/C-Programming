/*
 * ===================================================================
 *  File    : Basic.c
 *  Topic   : 21 Data Structures in C
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

#define BUCKET_COUNT 17  /* prime for better distribution */

typedef struct Entry { char key[50]; int value; struct Entry *next; } Entry;
typedef struct { Entry *buckets[BUCKET_COUNT]; int size; } HashTable;

unsigned int hash(const char *key){
    unsigned int h=5381;
    while(*key) h=((h<<5)+h)+(*key++);
    return h % BUCKET_COUNT;
}

HashTable *ht_create(void){
    HashTable *ht=calloc(1,sizeof(HashTable));
    return ht;
}
void ht_set(HashTable *ht, const char *key, int val){
    unsigned int idx=hash(key);
    for(Entry *e=ht->buckets[idx];e;e=e->next)
        if(strcmp(e->key,key)==0){e->value=val;return;}
    Entry *e=malloc(sizeof(Entry));
    strncpy(e->key,key,49); e->value=val;
    e->next=ht->buckets[idx]; ht->buckets[idx]=e; ht->size++;
}
int  ht_get(HashTable *ht, const char *key, int *out){
    unsigned int idx=hash(key);
    for(Entry *e=ht->buckets[idx];e;e=e->next)
        if(strcmp(e->key,key)==0){*out=e->value;return 1;}
    return 0;
}
void ht_delete(HashTable *ht, const char *key){
    unsigned int idx=hash(key);
    Entry *cur=ht->buckets[idx],*prev=NULL;
    while(cur){
        if(strcmp(cur->key,key)==0){
            if(prev) prev->next=cur->next; else ht->buckets[idx]=cur->next;
            free(cur); ht->size--; return;
        }
        prev=cur; cur=cur->next;
    }
}
void ht_print(HashTable *ht){
    printf("HashTable [%d entries]:\n",ht->size);
    for(int i=0;i<BUCKET_COUNT;i++){
        if(ht->buckets[i]){
            printf("  [%2d] ",i);
            for(Entry *e=ht->buckets[i];e;e=e->next)
                printf("(%s:%d) ",e->key,e->value);
            printf("\n");
        }
    }
}
void ht_free(HashTable *ht){
    for(int i=0;i<BUCKET_COUNT;i++){
        Entry *cur=ht->buckets[i],*nxt;
        while(cur){nxt=cur->next;free(cur);cur=nxt;}
    }
    free(ht);
}

int main(void){
    HashTable *ht=ht_create();
    printf("=== Hash Table (Separate Chaining) ===\n");

    /* Insert word frequencies */
    const char *words[]={"apple","banana","cherry","apple","date","banana","apple","elderberry"};
    int wc=sizeof(words)/sizeof(words[0]);
    for(int i=0;i<wc;i++){
        int cnt=0;
        ht_get(ht,words[i],&cnt);
        ht_set(ht,words[i],cnt+1);
    }
    ht_print(ht);

    printf("\nLookups:\n");
    int val;
    const char *keys[]={"apple","banana","grape"};
    for(int i=0;i<3;i++){
        if(ht_get(ht,keys[i],&val)) printf("  %s → %d\n",keys[i],val);
        else printf("  %s → not found\n",keys[i]);
    }

    ht_delete(ht,"banana");
    printf("\nAfter deleting 'banana':\n");
    if(!ht_get(ht,"banana",&val)) printf("  banana → not found\n");

    ht_free(ht);
    return 0;
}
