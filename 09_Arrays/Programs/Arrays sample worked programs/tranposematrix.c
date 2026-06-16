//Program to print tranpose of a matrix
//Author: Pavan Shetty H S

#include<stdio.h>
int main()
{
    int a[2][3],i,j;
    printf("Enter the matrix elements:\n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<3;j++)
        scanf("%d",&a[i][j]);
    }

    printf("Matrix is:\n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<3;j++)
        {
        printf("%d ",a[i][j]);
        }
    printf("\n");
    }

    printf("Tranpose Matrix is:\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<2;j++)
        {
        printf("%d ",a[j][i]);
        }
    printf("\n");
    }

}


/*
output:
Enter the matrix elements:
1 2 3 4 5 6
Matrix is:
1 2 3 
4 5 6 
Tranpose Matrix is:
1 4 
2 5 
3 6 
*/