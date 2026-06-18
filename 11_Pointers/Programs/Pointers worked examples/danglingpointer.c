//Program to understand the concepts of dangling pointer
//Author: Pavan Shetty H S


#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *ptr=(int*)malloc(sizeof(int));
    *ptr=10;
    printf("%d\n",*ptr);
    free(ptr);
    printf("%d\n",*ptr);//dangling ppointer
}


/*
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *ptr=NULL;
    {
        int a=5;
        ptr=&a;
        printf("a=%d\n",*ptr);
    }
    printf("%d\n",*ptr);//dangling pointer
}
*/


/*
#include<stdio.h>
#include<stdlib.h>
int *f()
{
    int a=9;
    return &a;
}//a lost after returning local variable a address
int main()
{
    int *ptr=f();
    printf("%d\n",*ptr);//dangling pointer
}
*/

