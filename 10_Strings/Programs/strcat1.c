//program to find the length of the string and concatenate two strings
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
    if(l1+l2<N)
    {
        strcat(s1,s2);
        puts(s1);
    }
    else
    {
        printf("String length exceeds the limit");
    }
}