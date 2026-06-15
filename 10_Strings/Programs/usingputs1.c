//C program to demonstrate string operations using gets() and puts() functions
//Author: Pavan Shetty H S

#include<stdio.h>
#include<string.h>
int main()
{
    char name[30];
    printf("Enter name:");
    scanf("%5s",name);//scanf() won't consider space as string
    printf("%.5s ",name);
    printf("%10.5s",name);//prints 5 characters with 10 field spacing
    puts(name);//automatically adds new line character at the end of the string and prints the string   
    puts(name);//prints 5 characters because as i already stored 5 characters in name variable using scanf() function
}
