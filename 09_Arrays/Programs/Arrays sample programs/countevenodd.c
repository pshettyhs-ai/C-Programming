//Program to count even and odd numbers in an array
//Author : Pavan Shetty H S

#include<stdio.h>
int main()
{
    int i,a[10];
    int even=0,odd=0;
    printf("\n Enter the array elements:");
    for(i=0;i<5;i++)//no need but for easy execution
    {
        scanf("%d",&a[i]);
        if(a[i]%2==0)
            even++;
        else
            odd++;
    }
    printf("Total even numbers are:%d",even);
    printf("\nTotal odd numbers are:%d",odd);
return 0;
    
}