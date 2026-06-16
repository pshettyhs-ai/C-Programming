//Program to print 2d array and find sum of all elements in the array
//Author: Pavan Shetty H S

#include<stdio.h>
int main()
{
    int a[2][3],i,j,sum=0;
    printf("Enter the 2d array elements:\n");
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
            printf("%d\t",a[i][j]);
            sum=sum+a[i][j];
        }
        printf("\n");
    }
    
    printf("Sum:%d",sum);
return 0;  
}

/*
output:
Enter the 2d array elements:
1 2 3 4 5 6
Matrix is:
1       2       3
4       5       6
Sum:21
*/