/*
 * ===================================================================
 *  File    : Basic.c
 *  Topic   : 20 Bitwise Programming
 *  Level   : Beginner
 *  Author  : PAVAN SHETTY H S
 *
 *  Notes   : Written as part of my personal C programming study.
 *            Comments explain the reasoning, not just the syntax.
 *            Run with: gcc Basic.c -o out -lm && ./out
 * ===================================================================
 */

#include <stdio.h>

/* Print binary representation of unsigned int */
void print_binary(unsigned int n, int bits) {
    for(int i=bits-1;i>=0;i--)
        printf("%d",  (n>>i)&1);
}

/* Count set bits (Kernighan's method) */
int count_bits(unsigned int n) {
    int c=0;
    while(n){n&=(n-1);c++;}
    return c;
}

/* Check if power of 2 */
int is_pow2(unsigned int n) { return n>0 && (n&(n-1))==0; }

/* Find single unique element (all others appear twice) */
int find_unique(int arr[], int n) {
    int r=0;
    for(int i=0;i<n;i++) r^=arr[i];
    return r;
}

/* Permission system demo */
#define PERM_READ  (1u<<0)
#define PERM_WRITE (1u<<1)
#define PERM_EXEC  (1u<<2)

void show_perms(unsigned int p){
    printf("Permissions: %c%c%c\n",
           (p&PERM_READ)?'r':'-',
           (p&PERM_WRITE)?'w':'-',
           (p&PERM_EXEC)?'x':'-');
}

int main(void) {
    printf("=== Bitwise Operations ===\n");
    unsigned char a=0b10110101, b=0b11001100;
    printf("a = "); print_binary(a,8); printf(" (%u)\n",a);
    printf("b = "); print_binary(b,8); printf(" (%u)\n",b);
    printf("a&b= "); print_binary(a&b,8); printf(" (%u)  AND\n",a&b);
    printf("a|b= "); print_binary(a|b,8); printf(" (%u)  OR\n", a|b);
    printf("a^b= "); print_binary(a^b,8); printf(" (%u)  XOR\n",a^b);
    printf("~a = "); print_binary((unsigned char)~a,8); printf(" (%u)  NOT\n",(unsigned char)~a);

    printf("\n=== Bit Manipulation ===\n");
    unsigned int x=0b10110101; int n=2;
    printf("x       = "); print_binary(x,8); printf("\n");
    printf("Set  b%d: ", n); print_binary(x|(1u<<n),8); printf("\n");
    printf("Clr  b%d: ", n); print_binary(x&~(1u<<n),8); printf("\n");
    printf("Tgl  b%d: ", n); print_binary(x^(1u<<n),8); printf("\n");
    printf("Chk  b%d: %d\n", n, (x>>n)&1);

    printf("\n=== Useful Tricks ===\n");
    for(int i=1;i<=16;i++)
        if(is_pow2(i)) printf("%d is a power of 2\n",i);

    printf("\nSet bit counts:\n");
    unsigned int nums[]={0,1,3,7,255,0b10110101};
    for(int i=0;i<6;i++)
        printf("  count_bits(%3u) = %d\n",nums[i],count_bits(nums[i]));

    printf("\n=== XOR: Find Unique ===\n");
    int arr[]={4,3,5,3,4,7,5};
    printf("Array has one unique element: %d\n", find_unique(arr,7));

    printf("\n=== Permission Flags ===\n");
    unsigned int perms=0;
    show_perms(perms);
    perms|=PERM_READ|PERM_WRITE; show_perms(perms);
    perms|=PERM_EXEC;            show_perms(perms);
    perms&=~PERM_WRITE;          show_perms(perms);

    printf("\n=== Shift Arithmetic ===\n");
    for(int i=0;i<=5;i++)
        printf("1 << %d = %3d  |  256 >> %d = %3d\n",i,1<<i,i,256>>i);

    return 0;
}
