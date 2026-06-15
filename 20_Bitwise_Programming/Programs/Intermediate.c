/*
 * ===================================================================
 *  File    : Intermediate.c
 *  Topic   : 20 Bitwise Programming
 *  Level   : Intermediate
 *  Author  : PAVAN SHETTY H S
 *
 *  Notes   : Written as part of my personal C programming study.
 *            Comments explain the reasoning, not just the syntax.
 *            Run with: gcc Intermediate.c -o out -lm && ./out
 * ===================================================================
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>

/* Gray code conversion */
uint32_t to_gray(uint32_t n)   { return n ^ (n >> 1); }
uint32_t from_gray(uint32_t g) {
    uint32_t n = g;
    while (g >>= 1) n ^= g;
    return n;
}

/* Bit count (popcount) — multiple methods */
int popcount_naive(uint32_t n){ int c=0; while(n){c+=n&1;n>>=1;} return c; }
int popcount_fast(uint32_t n) { int c=0; while(n){n&=(n-1);c++;} return c; }
int popcount_builtin(uint32_t n){ return __builtin_popcount(n); }

/* Parity (odd/even number of set bits) */
int parity(uint32_t n) {
    n ^= n >> 16; n ^= n >> 8; n ^= n >> 4;
    n ^= n >> 2;  n ^= n >> 1;
    return n & 1;
}

/* Rotate bits */
uint32_t rotate_left(uint32_t n, int k)  { return (n<<k)|(n>>(32-k)); }
uint32_t rotate_right(uint32_t n, int k) { return (n>>k)|(n<<(32-k)); }

/* Bit manipulation: extract bit range [hi:lo] */
uint32_t extract_bits(uint32_t n, int lo, int hi) {
    uint32_t mask = ((1u << (hi-lo+1)) - 1) << lo;
    return (n & mask) >> lo;
}

/* Simple bitmap (set of integers) */
#define BITMAP_SIZE 256
uint8_t bitmap[BITMAP_SIZE/8];
void bm_set(int n)  { bitmap[n/8] |=  (1<<(n%8)); }
void bm_clr(int n)  { bitmap[n/8] &= ~(1<<(n%8)); }
int  bm_get(int n)  { return (bitmap[n/8]>>(n%8))&1; }

void print_bin32(uint32_t n){for(int i=31;i>=0;i++){printf("%d",((n>>i)&1));if(i%4==0)printf(" ");}printf("\n");}

int main(void) {
    printf("=== Gray Code ===\n");
    printf("%-8s %-10s %-10s %-8s\n","Decimal","Binary","Gray","Decoded");
    for(int i=0;i<16;i++){
        uint32_t g=to_gray(i);
        printf("%-8d %-10u %-10u %-8u\n",i,i,g,from_gray(g));
    }

    printf("\n=== Popcount (count set bits) ===\n");
    uint32_t nums[]={0,1,0xFF,0xFFFFFFFF,0b10110101};
    for(int i=0;i<5;i++){
        printf("%10u: naive=%d fast=%d builtin=%d parity=%d\n",
               nums[i],popcount_naive(nums[i]),popcount_fast(nums[i]),
               popcount_builtin(nums[i]),parity(nums[i]));
    }

    printf("\n=== Bit Rotation ===\n");
    uint32_t x=0x12345678;
    printf("Original: "); print_bin32(x);
    printf("RotL 4:   "); print_bin32(rotate_left(x,4));
    printf("RotR 4:   "); print_bin32(rotate_right(x,4));

    printf("\n=== Extract Bit Range ===\n");
    uint32_t val=0b11010110;
    printf("Value: %d (0b11010110)\n",val);
    printf("Bits [2:0] = %u\n", extract_bits(val,0,2));
    printf("Bits [5:3] = %u\n", extract_bits(val,3,5));
    printf("Bits [7:6] = %u\n", extract_bits(val,6,7));

    printf("\n=== Bitmap (sparse set) ===\n");
    memset(bitmap,0,sizeof(bitmap));
    int primes[]={2,3,5,7,11,13,17,19,23,29};
    for(int i=0;i<10;i++) bm_set(primes[i]);
    printf("Prime bits set. Checking 1-30:\n");
    for(int i=1;i<=30;i++) if(bm_get(i)) printf("%d ",i);
    printf("\n");

    return 0;
}
