#include <iostream>
#include <vector>
#include <queue>
#define INF 0x7fffffff
using namespace std;
typedef pair<int,int> ci;
struct cmp
{
    bool operator ()(ci a,ci b)
    {
        return a.second>b.second;
    }
};
priority_queue< ci,vector<ci>,cmp> pq;
vector<ci> v[100001];
int n,m,s,e;
int dist[20001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int i;
    cin>>n>>m;
    for(i=1;i<=n;i++)dist[i]=INF;
    for(i=0;i<m;i++)
    {
        int x,y,c;
        cin>>x>>y>>c;
        v[x].push_back(make_pair(y,c));
    }
    cin>>s>>e;
    pq.push(make_pair(s,0));
    dist[s]=0;
    while(!pq.empty())
    {
        int now=pq.top().first;
        int dis=pq.top().second;
        pq.pop();
        if(dist[now] < dis) continue;
        for(i=0;i<v[now].size();i++)
        {
            int next=v[now][i].first;
            int cost=v[now][i].second;
            if(dist[next]>cost+dist[now])
            {
                dist[next]=cost+dist[now];
                pq.push(make_pair(next,dist[next]));
            }
        }
    }
    cout<<dist[e];
}
