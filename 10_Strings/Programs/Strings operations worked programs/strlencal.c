//Program to find the length of the string using strlen() function
//Author: Pavan Shetty H S

#include<stdio.h>
#include<string.h>
int main()
{
   int count=0,i=0;  
   char name[30];
   printf("Enter name:");
   gets(name);
   count=strlen(name);
   puts(name);
   printf("length of the string is:%d",count);
}


/*
output:
Enter name:Pavan Shetty H S
Pavan Shetty H S
length of the string is:16
*/