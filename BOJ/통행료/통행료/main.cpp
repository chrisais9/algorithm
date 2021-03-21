#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;
typedef pair<int,int> ci;
vector< vector<ci> > v;
int fee[300];
int n,m,k;
struct node
{
    int x,cost,m_fee;
    bool operator()(node a,node b)
    {
        return a.cost>b.cost;
    }
};
int dijkstra(int s,int e)
{
    vector<int> dist(300,INF);
    priority_queue<node,vector<node>,node> q;
    q.push({s,fee[s],fee[s]});
    dist[s]=0;
    while(!q.empty())
    {
        node now=q.top();
        q.pop();
        for(int i=0;i<v[now.x].size();i++)
        {
            int next=v[now.x][i].first;
            int cost=v[now.x][i].second;
            int flag=0;
            if(now.m_fee<fee[next])
            {
                flag=1;
                cost+=(cost-now.m_fee)+fee[next];
            }
            if(dist[next]>dist[now.x]+cost)
            {
                dist[next]=dist[now.x]+cost;
                if(flag)q.push({next,dist[next],fee[next]});
                else q.push({next,dist[next],now.m_fee});
            }
        }
    }
    return dist[e];
}
int main()
{
    int i;
    cin>>n>>m>>k;
    v.resize(m+1);
    for(i=1;i<=n;i++)cin>>fee[i];
    for(i=0;i<m;i++)
    {
        int x,y,c;
        cin>>x>>y>>c;
        v[x].push_back(make_pair(y,c));
        v[y].push_back(make_pair(x,c));
    }
    for(i=0;i<k;i++)
    {
        int s,e;
        cin>>s>>e;
        cout<<dijkstra(s,e)<<endl;
    }
}
