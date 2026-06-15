//Program to compare two strings without using strcmp() function
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
    for(int i=0;s1[i]!='\0' || s2[i]!='\0';i++)
    {
        if(s1[i]!=s2[i])
        {
            printf("Both strings are different");
            return 0;
        }
    }
    printf("Both strings are same");
}