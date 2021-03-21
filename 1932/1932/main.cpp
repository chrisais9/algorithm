#include <stdio.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
int tb[501][501];
int main()
{
    int i,j,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<=i;j++)scanf("%d",&tb[i][j]);
    }
    for(i=1;i<n;i++)
    {
        for(j=0;j<=i;j++)
        {
            if(j==0)tb[i][j]+=tb[i-1][j];
            else if(j==i)tb[i][j]+=tb[i-1][j-1];
            else tb[i][j]+=MAX(tb[i-1][j],tb[i-1][j-1]);
        }
    }
    int mx=0;
    for(i=0;i<n;i++)
    {
        if(mx<tb[n-1][i])mx=tb[n-1][i];
    }
    printf("%d",mx);
}
