//C program to demonstrate string operations using gets() function
//Author: Pavan Shetty H S

#include<stdio.h>
#include<string.h>
int main()
{
    char name[30];
    printf("Enter name:");
    gets(name);//unsafe to use because it over writes beyond the memory location leads loosing of other data
    //printf("%.5s",name);//prints 5 characters
    printf("%10.5s",name);//prints 5 characters with 10 field spacing
}