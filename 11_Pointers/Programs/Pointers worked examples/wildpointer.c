//program to understand the concepts of wild pointer
//Author: pavan Shetty H S

#include<stdio.h>
#include<stdlib.h>
int main()

{
    int *ptr;//uninitialized pointer or wild pointer
    printf("%d",*ptr);
}

/*
to overcome it
{
    int a=9;
    int *ptr=&a;
    printf("%d",*ptr);

}
*/

/*
{
    int *ptr=(int*)malloc(sizeof(int));
    *ptr=67;
    printf("%d",*ptr);

}
*/
