//Program to understand the concepts of NULL pointer
//Author : Pavan Shetty H S

#include<stdio.h>
int main()
{
    int *ptr1=NULL;
    int *ptr2=NULL;
    //int *ptr1;
    //int *ptr2;
    //int *ptr2=0;//this is also a NULL pointer
    printf("%d\n",*ptr1);
    if (ptr1==ptr2)
    {
        printf("Both are NULL pointers");
    }
    else
    {
        printf("%d\n",*ptr1);
        printf("%d",*ptr2);
    }
}

/*
output:
Both are NULL pointers
*/