#include <iostream>
using namespace std;
int tb[2000][2000],v[2000],n,m,ans[2000],an;
void f(int x)
{
    int i;
    for(i=1; i<=n; i++)if(tb[x][i]==1)v[i]--;
}
int ini()
{
    int i;
    for(i=1; i<=n; i++)
    {
        if(v[i]==0)
        {
            f(i);
            ans[an++]=i;
            v[i]=-1;
            return 0;
        }
    }
    return 1;
}
int main()
{
    int a,b,k;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        cin>>k>>a;
        for(int j=1; j<k; j++)
        {
            cin>>b;
            tb[a][b]=1;
            a=b;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)if(tb[j][i]==1)v[i]++;
    }
    for(int i=0;i<n;i++)
    {
        if(ini()&&i!=n-1)
        {
            cout<<0;
            return 0;
        }
    }
    for(int i=0;i<an;i++)cout<<ans[i]<<endl;
}
