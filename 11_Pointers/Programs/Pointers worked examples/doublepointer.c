//Program to demonstrate the use of double pointers in C
//Author: Pavan Shetty H S

#include<stdio.h>
int main()
{
    int a=10;
    int *p=&a;
    //int **q=&a;//the n level pointer should store the (n-1)level pointer address
    int **q=&p;
    int ***r=&q;
    //*p=12;
    //*q=25;
    //*r=78;
    printf("the value of a=%d\n %d\n %d\n %d\n",a,*p,*(*q),*(*(*r)));
    printf("the address of a=%x %x\n",&a,p);
    printf("the address of p=%x %x\n",&p,q);
    printf("the address of q=%x %x",&q,r);
    return 0;

}

/*
output:
the value of a=10
 10
 10
 10
the address of a=100 100
the address of p=200 200
the address of q=300 300
*/     
