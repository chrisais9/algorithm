#include <iostream>
#include <memory.h>
using namespace std;
int res, tb[1010][1010], n, m, ck[1010][1010];
int main()
{
    int i,j,k,num1,num2,ans=0;
    int x,y,l,f;
    cin>>n>>m;
    n++;
    for(k=0;k<m;k++)
    {
        cin>>x>>y>>l>>f;
        for(i=x;i<x+l;i++)for(j=y;j<y+l;j++)tb[i][j]=f;
    }
    
    for (num1=1;num1<=7;num1++)
    {
        for (num2=num1;num2<=7;num2++)
        {
            memset(ck,0,sizeof(ck));
            for(i=0;i<n;i++)for(j=0;j<n;j++)if(num1==tb[i][j]||num2==tb[i][j])ck[i][j]=1;
            for(i=1;i<n;i++)
            {
                for(j=1;j<n;j++)
                {
                    if (!ck[i][j])continue;
                    ck[i][j]=min(ck[i - 1][j],min(ck[i - 1][j - 1],ck[i][j - 1]))+1;
                    if(ans<ck[i][j])ans=ck[i][j];
                }
            }
        }
    }
    cout<<ans*ans;
}
