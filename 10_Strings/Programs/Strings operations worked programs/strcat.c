//program to concatenate two strings using strcat() function
//Author: Pavan Shetty H S

#include<stdio.h>
#include<string.h>
int main()
{
    char str1[30],str2[30];
    printf("Enter first string:");
    gets(str1);
    printf("Enter second string:");
    gets(str2);
    strcat(str1,str2);
    puts(str1);
}



/*
output:
Enter first string:Pavan
Enter second string:Shetty
PavanShetty
*/