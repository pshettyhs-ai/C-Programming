//Program to reverse a string
//Author: Pavan Shetty H S

#include<stdio.h>
#include<string.h>
int main()
{
    int l,i,j;
    char s1[30],ch;
    printf("Enter the string:");
    gets(s1);
    l=strlen(s1);
   /* for(i=0;i<l/2;i++)
    {
        ch=s1[i];
        s1[i]=s1[l-1-i];
        s1[l-1-i]=ch;
    }*/
   for(i=0,j=l-1;i<j;i++,j--)
   {
        ch=s1[i];
        s1[i]=s1[l-1-i];
        s1[l-1-i]=ch; 
   }
    printf("%s",s1);
}