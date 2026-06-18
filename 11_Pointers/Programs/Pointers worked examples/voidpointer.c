//Program to demonstrate the use of void pointers
//Author: Pavan Shetty H S

#include<stdio.h>
int main()
{
    void *vp;
    int a=10;
    float b=1.56;
    char ch='c';

    vp=&a;
    printf("a=%d\n",*(int*)vp);

    vp=&b;
    printf("b=%f\n",*(float*)vp);

    vp=&ch;
    printf("ch=%c\n",*(char*)vp);
}


/*
output:
a=10
b=1.560000
ch=c
*/