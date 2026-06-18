//Program to introduce pointer operations
//Author: Pavan Shetty H S

#include<stdio.h>
int main()
{
    int a = 10,b=9,c;
    int *p,*q;
    p = &a;
    q = &b;
    c=*p;
    *p=20;
    printf("Value of a is %d\n",a);
    printf("Value of a is %d\n",p);
    printf("Value of a is %d\n",*p);
    printf("Address of a=%x\n",&a);
    printf("Address of p=%x",&p);
    printf("Address of a=%x\n",p);
    printf("Address of c=%d\n",c);
    printf("Value of a is %d\n",a);
    printf("%x\n",p);
}


/*
output :
Value of a is 20
Value of a is 639630624
Value of a is 20
Address of a=261ffd20
Address of p=261ffd10Address of a=261ffd20
Address of c=10
Value of a is 20
261ffd20
*/
