//Program to demonstrate the use of pointer addition in C
//Author: Pavan Shetty H S

#include<stdio.h>
int main()
{
    int a[5]={10,20,30,40,50};
    int *p=a;//or &a[0]
    int *q=a;//or &a[0]
    printf("the value is : %d\n",*p);
    printf("the value is : %d\n",*q);
    printf("The address of element is : %u\n",&a[0]);
    printf("The address of element is : %u\n",p);
    printf("The address of element is : %u\n",q);
    p=p+2;//or p+=2
    //*p=34;
    printf("the value is : %d\n",*p);
    printf("The address of element is : %u\n",p);

}


/*output:
the value is : 10
the value is : 10
The address of element is : 100
The address of element is : 100
The address of element is : 100
the value is : 30
The address of element is : 108
*/

