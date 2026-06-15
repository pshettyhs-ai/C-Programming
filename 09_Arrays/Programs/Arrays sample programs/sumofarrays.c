//Program to print the sum of two arrays and store it in a third array.
//Author: Pavan Shetty H S

#include<stdio.h>
int main()
{
    int i,a[5],b[5],c[5];
    printf("Enter the first array elements:");  
    for(i=0;i<5;i++)
        scanf("%d",&a[i]);

    printf("Enter the second array elements:");
    for(i=0;i<5;i++)
        scanf("%d",&b[i]);

    for(i=0;i<5;i++)
    {
        c[i]=a[i]+b[i];
         printf("\nThe third array elements with index %d are:%d",i,c[i]);

    }
        
}