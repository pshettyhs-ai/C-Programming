//Program to demonstrate the increment and decrement of pointers in C
//Author: Pavan Shetty H S

#include<stdio.h>
int main()
{
    int a[]={10,20,30,40,50,70,80,90,89};
    int *p=a;//or &a[0]
    //p=&a[3];
    //printf("%d %d\n",*(p++),*(++p));
    printf("%d %d\n",*p++,*++p);
    printf("%d %d\n",*(p++),*(++p));
    printf("%d %d\n",*p++,(*p)++);
    printf("%d\n",*p);
    printf("%d %d\n",*p--,*--p);
}






/*output:
20 20
40 40
51 50
70
51 51
*/