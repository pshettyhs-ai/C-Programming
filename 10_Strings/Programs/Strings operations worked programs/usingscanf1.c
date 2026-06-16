//C program to demonstrate string operations using scanf() function
//Author: Pavan Shetty H S

#include<stdio.h>
#include<string.h>
int main()
{
    char fname[30],lname[30];
    printf("Enter name:");
    scanf("%s%s",fname,lname);
    printf("%s %s",fname,lname);
}

/*
Output :
Enter name:Pavan Shetty
Pavan Shetty
*/