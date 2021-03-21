#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321
using namespace std;
vector< vector<int> > v;
int tb[101][101],way[101][101];
int n,m;
void print_path(int q, int r)
{
    if(way[q][r] != 0)
    {
        print_path(q,way[q][r]);
        cout<<way[q][r]<<" ";
        print_path(way[q][r],r);
    }
}
int main()
{
    int i,j,k;
    cin>>n>>m;
    v.resize(n+1);
    for(i=0;i<=n;i++)for(j=0;j<=n;j++)if(i!=j)tb[i][j]=INF;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            int x;
            cin>>x;
            if(x)
            {
                v[i].push_back(j);
                tb[i][j]=1;
            }
        }
    }
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(tb[i][j]>tb[i][k]+tb[k][j])
                {
                    tb[i][j]=tb[i][k]+tb[k][j];
                    way[i][j]=k;
                }
                
            }
        }
    }
    int flag=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(tb[i][j]==n-1)
            {
                cout<<i<<" ";
                print_path(i,j);
                cout<<j<<" "<<endl;
                return 0;
            }
        }
    }
}
