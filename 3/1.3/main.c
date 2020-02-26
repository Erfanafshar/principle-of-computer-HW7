#include <stdio.h>
#include <stdlib.h>
typedef struct
    {
        float sorat ;
        float makhraj;
    }
    goia ;
int help_soeodi (void *a,void *b)
{
    float e , f ;
    goia c , d ;
    c =*((goia *)a);
    d =*((goia *)b);
    e=(c.sorat)/(c.makhraj) ;
    f=(d.sorat) / (d.makhraj) ;
    if (e>f)
    {
        return 1 ;
    }
    else ;
    if (e==f)
    {
        return 0 ;
    }
    else ;
    if (e<f)
    {
        return -1 ;
    }
    else ;
}
int help_nozoli (void *a,void *b)
{
    float e , f ;
    goia c , d ;
    c =*((goia *)a);
    d =*((goia *)b);
    e=(c.sorat)/(c.makhraj) ;
    f=(d.sorat) / (d.makhraj) ;
    if (e>f)
    {
        return -1 ;
    }
    else ;
    if (e==f)
    {
        return 0 ;
    }
    else ;
    if (e<f)
    {
        return 1 ;
    }
    else ;
}
int main (void)
{
    int n , i , j=1 , a;
    printf("enter n : \n");
    scanf("%d",&n);
    goia A[n];
    for(i=0;i<n;i++)
    {
        printf("enter the Facial and denominator of %d th  rational number : \n",j);
        j++;
        scanf("%f%f",&A[i].sorat,&A[i].makhraj);
    }
    printf("enter the number 1 for Ascending sort or -1 for Descending sort : \n");
    scanf("%d",&a);
    if (a==1)
    {
        qsort(A,n,sizeof(goia),help_soeodi);
    }
    else ;
    if (a==-1)
    {
        qsort(A,n,sizeof(goia),help_nozoli);
    }
    else ;
    for(i=0;i<n;i++)
    {
        printf("%.0f/%.0f\n",A[i].sorat,A[i].makhraj);
    }
    return 0 ;
}
