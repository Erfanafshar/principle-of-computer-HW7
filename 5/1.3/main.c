#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main (void)
{
    int i=0 , b , e , s;
    char d ;
    FILE *vorodi , *khoroji ;
    char a[20]={0} , c[20]={0};
    printf("enter the input file name : ");
    scanf("%s",a);
    printf("enter the output file name : ");
    scanf("%s",c);
    while(a[i]!=0)
    {
        i++;
    }
    a[i]='.';
    a[i+1]='t';
    a[i+2]='x';
    a[i+3]='t';
    i=0;
    while(c[i]!=0)
    {
        i++;
    }
    c[i]='.';
    c[i+1]='t';
    c[i+2]='x';
    c[i+3]='t';
    vorodi=fopen(a,"r");
    if (vorodi==NULL)
    {
        printf("can not open the file \n");
        exit(-1);
    }
    else ;
    khoroji=fopen(c,"w");
    if (khoroji==NULL)
    {
        printf("can not open the file \n");
        exit(-1);
    }
    else ;
    while(1)
    {
        d=fgetc(vorodi);
        if (feof(vorodi))
        {
            break ;
        }
        else ;
        b=islower(d);
        if (b==2)
        {
            d=toupper(d);
        }
        else ;
        e=isdigit(d);
        if (e==1)
        {
            s=(int)d;
            s=s-48;
            while(s-i!=0)
            {
                i++;
            }
            if(i==0)
            {
                fputs("zero",khoroji);
            }
            else ;
            if(i==1)
            {
                fputs("one",khoroji);
            }
            else ;
            if(i==2)
            {
                fputs("two",khoroji);
            }
            else ;
            if(i==3)
            {
                fputs("three",khoroji);
            }
            else ;
            if(i==4)
            {
                fputs("four",khoroji);
            }
            else ;
            if(i==5)
            {
                fputs("five",khoroji);
            }
            else ;
            if(i==6)
            {
                fputs("six",khoroji);
            }
            else ;
            if(i==7)
            {
                fputs("seven",khoroji);
            }
            else ;
            if(i==8)
            {
                fputs("eight",khoroji);
            }
            else ;
            if(i==9)
            {
                fputs("nine",khoroji);
            }
            else ;
        }
        else
        {
            fputc(d, khoroji);
        }
    }


    fclose(vorodi);
    fclose(khoroji);

    return 0 ;
}
