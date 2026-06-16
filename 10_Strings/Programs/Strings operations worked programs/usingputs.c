//C program to demonstrate string operations using gets() and puts() functions
//Author: Pavan Shetty H S

#include<stdio.h>
#include<string.h>
int main()
{
    char name[30];
    printf("Enter name:");
    gets(name);//unsafe to use because it over writes beyond the memory location leads loosing of other data
    printf("%s ",name);
    //printf("%10.5s",name);//prints 5 characters with 10 field spacing
    puts(name);//automatically adds new line character at the end of the string and prints the string   
    puts(name);
}


/*
output :
Enter name:Pavan Shetty H S
Pavan Shetty H S Pavan Shetty H S
Pavan Shetty H S
*/