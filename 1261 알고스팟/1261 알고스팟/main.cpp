#include <iostream>
#include <queue>
using namespace std;
int tb[101][101],ck[101][101];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int n,m;
struct node
{
    int x,y,wall;
    bool operator ()(node a,node b)
    {
        return a.wall>b.wall;
    }
};
int main()
{
    cin>>n>>m;
    swap(n,m);
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%1d",&tb[i][j]);
    
    priority_queue<node,vector<node>,node> pq;
    pq.push({1,1,0});
    ck[1][1]=1;
    while(!pq.empty())
    {
        node now=pq.top();
        pq.pop();
        for(int i=0;i<4;i++)
        {
            int mx=now.x+dx[i];
            int my=now.y+dy[i];
            if(mx<=0||mx>n||my<=0||my>m)continue;
            if(mx==n&&my==m)
            {
                cout<<now.wall+tb[n][m];
                return 0;
            }
            if(!ck[mx][my])
            {
                ck[mx][my]=1;
                pq.push({mx,my,now.wall+tb[mx][my]});
            }
        }
    }
    cout<<0<<endl;
}
