//Program to compare two strings using strcmp() function
//Author: Pavan Shetty H S

#include<stdio.h>
#include<string.h>
int main()
{
    char s1[30],s2[30];
    printf("Enter first string:");
    gets(s1);
    printf("Enter second string:");
    gets(s2);
    if(strcmp(s1,s2)==0)
    {
        printf("Both strings are same");
    }
    else
    {
        printf("Both strings are different");
    }
}


/*
output:
Enter first string:Pavan
Enter second string:Shetty
Both strings are different
*/