//program to convert a string to lowercase
//Author: Pavan Shetty H S

#include<stdio.h>
#include<string.h>
int main()
{   
    int i;
    char s[30];
    printf("Enter a string: ");
    gets(s);
    //strlwr(s);
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]>='A' && s[i]<='Z')
        s[i]=s[i]+32;
    }
    printf("%s",s);
}

/*
output:
Enter a string: PavAn
pavan
*/