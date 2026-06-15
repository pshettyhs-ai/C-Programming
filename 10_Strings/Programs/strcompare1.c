//Program to compare two strings using strcmp() function
//Author: Pavan Shetty H S

#include<stdio.h>
#include<string.h>
int main()
{
    int value;
    char s1[30],s2[30];
    printf("Enter first string:");
    gets(s1);
    printf("Enter second string:");
    gets(s2);
    value=strcmp(s1,s2);
    if(value==0)
    {
        printf("Both strings are same");
    }
    else
    {
        printf("Both strings are different");
    }   
    printf("value is:%d",value);
}