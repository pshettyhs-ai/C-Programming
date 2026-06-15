//Program to find the length of the string without using strlen() function
//Author: Pavan Shetty H S

#include<stdio.h>
#include<string.h>
int main()
{
   int count=0,i=0;  
   char name[30];
   printf("Enter name:");
   gets(name);
   //count=strlen(name);
   while(name[i]!='\0')
   {
    count ++;
    i++;
   }
   puts(name);
   printf("length of the string is:%d",count);
}