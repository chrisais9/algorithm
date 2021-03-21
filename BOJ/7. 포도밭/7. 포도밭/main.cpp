#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;
int n,m;
int tb[501][501],d[501][501];
int main()
{
    int i,j,tc,k,xr,yr,ans;
    cin>>tc;
    while(tc--)
    {
        cin>>n>>m;
        memset(tb,0,sizeof(tb));
        for(i=1;i<=n;i++)for(j=1;j<=m;j++)cin>>tb[i][j];
        cin>>k;
        while(k--)
        {
            memset(d,0,sizeof(d));
            ans=0;
            cin>>xr>>yr;
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=m;j++)
                {
                    if(xr<=tb[i][j]&&tb[i][j]<=yr)
                        d[i][j]=min(min(d[i-1][j-1],d[i-1][j]),d[i][j-1])+1;
                    ans=max(ans,d[i][j]);
                }
            }
            cout<<ans<<endl;
        }
        cout<<"-"<<endl;
    }
        
}
