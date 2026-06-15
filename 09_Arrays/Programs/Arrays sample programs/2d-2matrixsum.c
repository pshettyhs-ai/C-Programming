//Addition of two 2D matrices
//Author : Pavan Shetty H S

#include<stdio.h>
int main()
{
    int a[2][3],b[2][3],c[2][3],i,j;
    printf("The first matrix elements are:\n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<3;j++)
        scanf("%d",&a[i][j]);
    }
    printf("The second matrix elements are:\n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<3;j++)
        scanf("%d",&b[i][j]);
    }

    printf("The first matrix is:\n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    printf("The second matrix is:\n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d\t",b[i][j]);
        }
        printf("\n");
    }
    printf("The sum matrix is:\n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<3;j++)
        {
            c[i][j]=a[i][j]+b[i][j];
            printf("%d\t",c[i][j]);
        }
        printf("\n");
    }
return 0;

}
