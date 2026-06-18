//Sample program to understand pointer increment and decrement operators in C
//Author: Pavan Shetty H S  

#include<stdio.h>
int main()
{
    int a[]={10,11,-1,56,67,5,4,};
    int *p=a;//or &a[0]
    int *q=&a[0]+3;
    printf("%d %d %d\n",(*p)++,(*p)++,*(++p));
    printf("%d\n",*p);
    printf("%d\n",(*p)++);
    printf("%d\n",(*p)++);
    q--;
    printf("%d\n",(*(q+2))--);
    printf("%d\n",*(p+2)-2);
    printf("%d\n",*(p++ -2)-1);
    
}

/*
output:
12 11 11
13
13
14
67
54
208
*/