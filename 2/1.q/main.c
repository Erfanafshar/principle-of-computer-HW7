#include <stdio.h>
#include <stdlib.h>
int main (void)
{
    int i , m , j , k , d=1 , jam=0 , row=0;
    int xa,ya,xb,yb,xc,yc,xd,yd;
    int B[100][100];
    int C[100][100];
    int D[100][100];
    int** A;
    //printf("enter your matrix column : ");
    scanf("%d",&m);
    int check_finish[m];
    //printf("enter the first row numbers : ");
    A=(int **)malloc(sizeof(int *));
    if (A==NULL)
    {
        //printf("can not allocate memory .");
        return -1 ;
    }
    else ;
    A[0]=(int *)malloc(m*sizeof(int));
    if (A[0]==NULL)
    {
        //printf("can not allocate memory .");
        return -1 ;
    }
    else ;
    for(i=0;i<m;i++)
    {
        scanf("%d",&A[0][i]);
    }
    while(1)
    {
        //printf("enter the %d th row numbers : ",d+1);
        //check finish
        for(i=0;i<m;i++)
        {
            scanf("%d",&check_finish[i]);
        }
        for(i=0;i<m;i++)
        {
            if (check_finish[i]!=0)
            {
                row++;
                break ;
            }
            else ;
        }
        if (i==m)
        {
            row++;
            break ;
        }
        else ;
        // new memory
        A=(int **)realloc(A,sizeof(int));
        if(A==NULL)
        {
            printf("can not allocate memory .");
            return -1 ;
        }
        else ;
        A[d]=(int *)malloc(m*sizeof(int));
        if (A[d]==NULL)
        {
            printf("can not allocate memory .");
            return -1 ;
        }
        else ;
        for(i=0;i<m;i++)
        {
            A[d][i]=check_finish[i];
        }
        d++;
    }
    //A
    xa=m;
    ya=d;
    // B
    for(i=0;i<d;i++)
    {
        for(j=0;j<m;j++)
        {
            B[j][i]=A[i][j];
        }
    }
    xb=d;
    yb=m;
    //C
    for (i = 0; i <d ; i++)
    {
        for (j = 0; j <d ; j++)
        {
            for (k = 0; k <m ; k++)
            {
              jam = jam + A[i][k]*B[k][j];
            }
            C[i][j] = jam;
            jam = 0;
        }
    }
    xc=d;
    yc=d;
    //D
    for (i = 0; i <m ; i++)
    {
        for (j = 0; j <m ; j++)
        {
            for (k = 0; k <d ; k++)
            {
                jam = jam + B[i][k]*A[k][j];
            }
            D[i][j] = jam;
            jam = 0;
        }
    }
    xd=m;
    yd=m;
    // print
    //A
    printf("A: \n");
    for (i=0;i<ya;i++)
    {
        for(j=0;j<xa;j++)
        {
            printf(" %d ",A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    //B
    printf("B: \n");
    for(j=0;j<yb;j++)
    {
        for (i=0;i<xb;i++)
        {
            printf(" %d ",B[j][i]);
        }
        printf("\n");
    }
    printf("\n");
    //C
    printf("C: \n");
    for(j=0;j<xc;j++)
    {
        for (i=0;i<xc;i++)
        {
            printf(" %d ",C[j][i]);
        }
        printf("\n");
    }
    printf("\n");
    //D
     printf("D: \n");
    for(j=0;j<xd;j++)
    {
        for (i=0;i<xd;i++)
        {
            printf(" %d ",D[j][i]);
        }
        printf("\n");
    }
    printf("\n");
    for (j = 0; j < row; j++)
    {
        free(A[j]);
    }
    free(A);
    return 0 ;
}
