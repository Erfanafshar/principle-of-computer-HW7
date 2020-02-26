#include <stdio.h>
#include <stdlib.h>
struct time
{
    int hour;
    int min;
    int sec;
};
//time compering
int time_cmp(struct time t1, struct time t2)
{
    if(t1.hour > t2.hour)
    return 1;
    else if(t2.hour > t1.hour)
    return -1;
    else if(t1.min > t2.min)
    return 1;
    else if(t2.min > t1.min)
    return -1;
    else if(t1.sec > t2.sec)
    return 1;
    else if(t2.sec > t1.sec)
    return -1;
    else
    return 0;
}
int main(void){
    FILE *fp;
    struct time p , minim , maxim ,tmp , tms;
    int a=0 , h, m ,s , hh ,mm ,ss;
    fp= fopen("asd", "rb+");
    if(fp==NULL)
    {
        printf("Cannot read from file\n");
        return -1;
    }
    //find the minimum time
    while(1)
    {
        if(fread(&p, sizeof(p), 1, fp) < 1)
        {
            break;
        }
        minim.hour=p.hour ;
        minim.min=p.min ;
        minim.sec=p.sec ;
        break ;
    }
    while(1)
    {
        if(fread(&p, sizeof(p), 1, fp) < 1)
        {
            break;
        }
        a=time_cmp( p ,  minim);
        if (a==-1)
        {
            minim.hour=p.hour ;
            minim.min=p.min ;
            minim.sec=p.sec ;
        }
        else ;
    }
    fseek(fp,0*sizeof(p),SEEK_SET);
    // find the maximum time
    while(1)
    {
        if(fread(&p, sizeof(p), 1, fp) < 1)
        {
            break;
        }
        maxim.hour=p.hour ;
        maxim.min=p.min ;
        maxim.sec=p.sec ;
        break ;
    }
    while(1)
    {
        if(fread(&p, sizeof(p), 1, fp) < 1)
        {
            break;
        }
        a=time_cmp(p , maxim);
        if (a==1)
        {
            maxim.hour=p.hour ;
            maxim.min=p.min ;
            maxim.sec=p.sec ;
        }
        else ;
    }
    //save the last element of time in tms
    fseek(fp,0*sizeof(p),SEEK_SET);
    fseek(fp,0*sizeof(p),SEEK_END);
    fread(&p, sizeof(p), 1, fp);
    hh=p.hour;
    mm=p.min;
    ss=p.sec;

    tms.hour=hh;
    tms.min=mm;
    tms.sec=ss;
    fseek(fp,0*sizeof(p),SEEK_SET);
    //save the first element of time in tmp
    while(1)
    {
        if(fread(&p, sizeof(p), 1, fp) < 1)
        {
            break ;
        }
        h=p.hour ;
        m=p.min ;
        s=p.sec ;
        break ;
    }
    tmp.hour=h;
    tmp.min=m;
    tmp.sec=s;
    //swap the minimum time with the first element
    while(1)
    {
        if(fread(&p, sizeof(p), 1, fp) < 1)
        {
            break;
        }
        a=time_cmp(p,minim);
        if (a==0)
        {
            fseek(fp,-1*sizeof(p),SEEK_CUR);
            fwrite(&tmp,sizeof(p),1,fp);
            fseek(fp,0*sizeof(p),SEEK_SET);
            fwrite(&minim,sizeof(p),1,fp);
            break ;
        }
        else ;
    }
    fseek(fp,1*sizeof(p),SEEK_SET);
    //swap the maximum time with the last element
    while(1)
    {
        if(fread(&p, sizeof(p), 1, fp) < 1)
        {
            break;
        }
        a=time_cmp(p,maxim);
        if (a==0)
        {
            fseek(fp,-1*sizeof(p),SEEK_CUR);
            fwrite(&tms,sizeof(p),1,fp);
            fseek(fp,-1*sizeof(p),SEEK_END);
            fwrite(&maxim,sizeof(p),1,fp);
            break ;
        }
        else ;
    }
    fclose(fp);
    return 0;
}
