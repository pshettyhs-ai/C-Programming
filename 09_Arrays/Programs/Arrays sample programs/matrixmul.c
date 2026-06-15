//Program to multiply two matrices
//Author : Pavan Shetty H S
#include<stdio.h>
#define N 50
int main()
{
    int a[N][N],b[N][N],c[N][N],i,j,k,m,n,p,q,sum;
    printf("Enter the number of rows and columns of first matrix:\n");
    scanf("%d %d",&m,&n);
    printf("Enter the elements of first matrix:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        scanf("%d",&a[i][j]);
    }
    printf("Enter the number of rows and columns of second matrix:\n");
    scanf("%d %d",&p,&q);
    printf("Enter the elements of second matrix:\n");
    for(i=0;i<p;i++)
    {
        for(j=0;j<q;j++)
        scanf("%d",&b[i][j]);
    }

    printf("The first matrix is:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d",a[i][j]);
        }
        printf("\n");
    }

    printf("The second matrix is:\n");
    for(i=0;i<p;i++)
    {
        for(j=0;j<q;j++)
        {
            printf("%d",b[i][j]);
        }
        printf("\n");
    }

    printf("The first matrix is:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }

    printf("The second matrix is:\n");
    for(i=0;i<p;i++)
    {
        for(j=0;j<q;j++)
        {
            printf("%d\t",b[i][j]);
        }
        printf("\n");
    }

    if(n!=p)
    {
        printf("Multiplication is not possible");
    }
    else
    {
        for(i=0;i<m;i++)
        {
            for(j=0;j<q;j++)
            {
                sum=0;
                for(k=0;k<n;k++)
                {
                    sum=sum+a[i][k]*b[k][j];

                }
                c[i][j]=sum;
               
            }

        }
    
        printf("Multiplication matrix is:\n");
        for(i=0;i<m;i++)
            {
                for(j=0;j<q;j++)
                {
                    printf("%d\t",c[i][j]);
                }
                printf("\n");
            }
    }        

return 0;

}