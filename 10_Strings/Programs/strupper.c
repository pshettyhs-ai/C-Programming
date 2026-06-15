//program to convert a string to uppercase
//Author: Pavan Shetty H S

#include<stdio.h>
#include<string.h>
int main()
{   
    int i;
    char s[30];
    printf("Enter a string: ");
    gets(s);
    //strupr(s);
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]>='a' && s[i]<='z')
        s[i]=s[i]-32;
    }
    printf("%s",s);
}