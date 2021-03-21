#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e15
using namespace std;
typedef pair<int,int> ci;
typedef long long int lld;
struct node
{
    int x;
    lld cost;
    int road;
    bool operator ()(node a,node b)
    {
        return a.cost>b.cost;
    }
};
vector< vector<ci> > v;
lld dist[10010][21];
int n,m,k;
void dijkstra(int s,int e)
{
    for(int i=0;i<=n;i++)for(int j=0;j<=k;j++)dist[i][j]=INF;
    dist[1][k]=0;
    priority_queue<node,vector<node>,node> pq;
    pq.push({1,0,k});
    while(!pq.empty())
    {
        
        node now=pq.top();
        pq.pop();
        if(now.cost!=dist[now.x][now.road])continue;
        for(int i=0;i<v[now.x].size();i++)
        {
            int next=v[now.x][i].first;
            lld ncost=v[now.x][i].second;
            if(dist[next][now.road]>now.cost+ncost)
            {
                dist[next][now.road]=now.cost+ncost;
                pq.push({next,dist[next][now.road],now.road});
            }
            if(now.road>0)
            {
                if(dist[next][now.road-1]>now.cost)
                {
                    dist[next][now.road-1]=now.cost;
                    pq.push({next,dist[next][now.road-1],now.road-1});
                }
            }
        }
    }
}
int main()
{
    int i;
    cin>>n>>m>>k;
    v.resize(n+1);
    for(i=0;i<m;i++)
    {
        int x,y,c;
        cin>>x>>y>>c;
        v[x].push_back(make_pair(y,c));
        v[y].push_back(make_pair(x,c));
    }
    
    dijkstra(1,n);
    
    lld ans=INF;
    for(i=0;i<=k;i++)ans=min(ans,dist[n][i]);
    cout<<ans;
}

