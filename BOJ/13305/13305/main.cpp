#include <stdio.h>
long long int cost[100001],dis[100001],mincost,ans=0;

int main()
{
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n-1;i++)scanf("%lld",&dis[i]);
    for(i=0;i<n;i++)scanf("%lld",&cost[i]);
    mincost=0x7fffffff;
    for(i=0;i<n;i++)
    {
        if(mincost>cost[i])mincost=cost[i];
        ans+=dis[i]*mincost;
    }
    printf("%lld",ans);
}
