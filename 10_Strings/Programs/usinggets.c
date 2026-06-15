//C program to demonstrate string operations(gets) in C
//Author: Pavan Shetty H S

#include<stdio.h>
#include<string.h>
int main()
{
    char name[30];
    printf("Enter name:");
    gets(name);//unsafe to use because it over writes beyond the memory location leads loosing of other data
    printf("%s",name);
}