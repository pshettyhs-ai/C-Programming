//Program to demonstrate substraction of pointers in C
//Author: Pavan Shetty H S

#include<stdio.h>
int main()
{
    int a[5]={10,20,30,40,50};
    int *p=a;//or &a[0]
    int *q=&a[3];
    printf("the q-p = %d\n",q-p);
    printf("the p-q = %d\n",p-q);
    printf("the value is : %d\n",*p);
    printf("the value is : %d\n",*q);
    q=q-2;//or q-=2
    printf("the value is : %d\n",*q);
    p=p+2;//or p+=2
    printf("q-p = %d\n",q-p);
    q=q-2;//or q-=2
    printf("the value is : %d\n",*q);
    
}

/*
output :
the q-p = 3
the p-q = -3
the value is : 10
the value is : 40
the value is : 20
q-p = -1
the value is : 250
*/