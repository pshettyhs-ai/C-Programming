//Program to demonstrate the use of pointer to string in C
//Author: Pavan Shetty H S

#include<stdio.h>
int main()
{
    char str[]="welcome to jenny's lectures";
    char *p=str;//or &str[0]
    printf("%s\n",p);
    printf("%c\n",*p);
    printf("%c\n",*(p+++1));
    printf("%c\n",*((p-- +5)-1)+3);
    printf("%c\n",*(++p+10)-32);
    printf("%c %c %c\n",*p,*++p,*--p);
}


/*output:
welcome to jenny's lectures
w
e
p
J
e e w*/