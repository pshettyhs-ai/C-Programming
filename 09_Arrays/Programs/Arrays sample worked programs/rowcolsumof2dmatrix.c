//program to print the sum of rows and columns of a 2D matrix
//Author: Pavan Shetty H S

#include<stdio.h>
int main()
{
    int a[3][3],i,j,SR,SC;
    printf("Enter the elements of the matrix:\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        scanf("%d",&a[i][j]);
    }

    printf("Matrix is:\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }

    
    for(i=0;i<3;i++)
    {
        SR=SC=0;
        for(j=0;j<3;j++)
        {
            SR=SR+a[i][j];
            SC=SC+a[j][i];
          
        }
    printf("\n SumRow=%d , SumCol=%d",SR,SC);
    
    }

return 0;
}


/*
output:
Enter the elements of the matrix:
1 2 3 4 5 6 7 8 9
Matrix is:
1       2       3
4       5       6
7       8       9

 SumRow=6 , SumCol=12
 SumRow=15 , SumCol=15
 SumRow=24 , SumCol=18
*/