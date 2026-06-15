//Program to print the sum and average of marks of 5 students
//Author: Pavan Shetty H S

#include<stdio.h>
int main()
{
    int i;
    float marks[5],sum=0,avg;
    printf("Enter the marks:");
    for(i=0;i<5;i++)
    scanf("%f",&marks[i]);
    for(i=0;i<5;i++)
    {
        sum=sum+marks[i];
    }
    avg=sum/5;
    printf("Sum=%f",sum);
    printf("Average=%f",avg);
    
}