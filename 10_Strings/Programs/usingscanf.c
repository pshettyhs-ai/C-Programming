//C program to demonstrate string operations using scanf() function
//Author: Pavan Shetty H S

#include<stdio.h>
#include<string.h>
int main()
{
    char name[30];
    printf("Enter name:");
    scanf("%s",name);//scanf() won't consider space as string
    printf("%s",name);
}