#include <iostream>
#include <queue>
using namespace std;
struct in
{
    int tb[100][100],cnt;
}te;
queue<in> q;
int data[100][100],n,m,smp[100][100];
void inv(int x,int y)
{
    int i,j;
    for(i=0;i<n;i++)for(j=0;j<m;j++)te.tb[i][j]=smp[i][j];
    for(i=0;i<=x;i++)for(j=0;j<=y;j++)
    {
        te.tb[i][j]=!smp[i][j];
    }
}
bool ok()
{
    int i,j;
    for(i=0;i<n;i++)for(j=0;j<m;j++)if(te.tb[i][j]==1)return false;
    return true;
}
int f()
{
    int i,j,tc;
    while(!q.empty())
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                smp[i][j]=q.front().tb[i][j];
            }
        }
        tc=q.front().cnt;
        q.pop();
        for(i=n-1;i>=0;i--)
        {
            for(j=m-1;j>=0;j--)
            {
                if(smp[i][j])
                {
                    inv(i,j);
                    te.cnt=tc+1;
                    if(ok())return te.cnt;
                    q.push(te);
                }
            }
        }
    }
    return -1;
}
int main()
{
    int i,j;
    char tt;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>tt;
            te.tb[i][j]=tt-'0';
        }
    }
    if(ok())cout<<0<<endl;
    else
    {
        te.cnt=0;
        q.push(te);
        cout<<f();
    }
}
