//Program to print the array elements in forward and reverse order
//Author : Pavan Shetty H S

#include<stdio.h>
int main()
{
    int a[5],i;
    printf("\nEnter the array elements:");
    for(i=0;i<5;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<5;i++)
    {
        printf("Array element at index %d is:%d\n",i,a[i]);
    }
    for(i=4;i>=0;i--)
    {
        printf("Array element at index %d is:%d\n",i,a[i]);
    }
    return 0;
}