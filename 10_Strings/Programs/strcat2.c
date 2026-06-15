//Program to concatenate two strings without using strcat() function
//Author: Pavan Shetty H S

#include<stdio.h>
#define N 50
#include<string.h>
int main()
{
    int l1,l2;
    char s1[N],s2[N];
    printf("Enter first string:");
    gets(s1);
    printf("Enter second string:");
    gets(s2);
    l1=strlen(s1);
    l2=strlen(s2);
    for(int i=0;i<l2;i++)
    {
        s1[l1+i]=s2[i];
    }
    printf("%s\n",s1);
    puts(s2);
}