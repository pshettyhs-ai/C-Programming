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


/*
output:
Enter the array elements:1 2 3 4 5
Array element at index 0 is:1
Array element at index 1 is:2
Array element at index 2 is:3
Array element at index 3 is:4
Array element at index 4 is:5
Array element at index 4 is:5
Array element at index 3 is:4
Array element at index 2 is:3
Array element at index 1 is:2
Array element at index 0 is:1
*/