#include <iostream>
#define INF 99999999
using namespace std;
int tb[200][200];
int main()
{
    int i,j,k,n,m,a,b,cnt;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i==j)continue;
            tb[i][j]=INF;
        }
    }

    for(i=0;i<m;i++)
    {
        cin>>a>>b;
        tb[a][b]=1;
    }
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(tb[i][j]>tb[i][k]+tb[k][j])tb[i][j]=tb[i][k]+tb[k][j];
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        cnt=0;
        for(j=1;j<=n;j++)
        {
            if(i==j)continue;
            if(tb[i][j]==INF&&tb[j][i]==INF)cnt++;
        }
        cout<<cnt<<endl;
    }
}
