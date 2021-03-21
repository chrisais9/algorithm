#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;
typedef pair<int,int> ci;
struct cmp
{
    bool operator ()(ci a,ci b)
    {
        return a.second>b.second;
    }
};
int n,m,des;
vector<int> dist,prev_dist;
vector< vector<ci> > v,mp,rev_mp;
void djikstra(int st)
{
    dist.clear();
    dist.resize(n+1,INF);
    dist[st]=0;
    priority_queue<ci,vector<ci>,cmp> pq;
    pq.push(make_pair(st,0));
    while(!pq.empty())
    {
        int now=pq.top().first;
        pq.pop();
        for(int i=0;i<v[now].size();i++)
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
}
int main()
{
    cin>>n>>m>>des;
    mp.resize(n+1);
    rev_mp.resize(n+1);
    for(int i=0;i<m;i++)
    {
        int x,y,c;
        cin>>x>>y>>c;
        mp[x].push_back(make_pair(y,c));
        rev_mp[y].push_back(make_pair(x,c));
    }
    v=mp;
    djikstra(des);
    prev_dist=dist;
    v=rev_mp;
    djikstra(des);
    int ans=0;
    for(int i=1;i<=dist.size();i++)if(ans<prev_dist[i]+dist[i])ans=prev_dist[i]+dist[i];
    cout<<ans;
}
