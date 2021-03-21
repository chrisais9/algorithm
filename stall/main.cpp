#include <stdio.h>
int n,m,tb[1000][1000]={0,};
int main()
{
    FILE *fp;
    fp=fopen("/Users/Christopher/Desktop/input.txt","w");


    int i,j,t,c;
    fscanf(fp,"%d %d",&n,&m);
    printf("%d ",n);
    for(i=1;i<=m;i++)
    {
        fscanf(fp,"%d",&t);
        for(j=0;j<t;j++)
        {
            fscanf(fp,"%d",&c);
            tb[i][c]=1;
        }
    }
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=m;j++)printf("%d ",tb[i][j]);
        printf("\n");
    }
}
