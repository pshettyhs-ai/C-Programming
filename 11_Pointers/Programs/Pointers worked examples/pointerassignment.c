//program to assign value of one pointer to another pointer(pointer assignment)
//Author: Pavan Shetty H S

#include<stdio.h>
int main()
{
    int a = 10,b=9,c;
    int *p,*q;
    p = &a,q=&b,*q =*p;
    
    printf("a=%d %d %d",a,*p,*q);
}


//output:a=10 10 10

