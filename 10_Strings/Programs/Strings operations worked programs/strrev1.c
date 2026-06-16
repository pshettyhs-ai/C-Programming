//Program to reverse a string using strrev() function
//Author: Pavan Shetty H S

#include<stdio.h>
#include<string.h>
int main()
{
    char s[30];
    printf("Enter the string:");
    gets(s);
    strrev(s);
    printf("%s",s);
}


/*
output:
Enter the string:Pavan Shetty H S
S H yttehS navaP
*/