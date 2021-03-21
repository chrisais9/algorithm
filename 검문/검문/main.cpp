#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 987654321
using namespace std;
typedef pair<int,int> ci;
vector< vector<ci> > v(1001);
int ck[1001][1001];
vector<int> dist;
int n,m;
struct cmp {
    bool operator()(ci a,ci b)
    {
        return a.second>b.second;
    }
};
void dji(int s,int e)
{
    priority_queue<ci,vector<ci>,cmp> pq;
    pq.push(make_pair(s,0));
    while(!pq.empty())
    {
        int now=pq.top().first;
        pq.pop();
        for(int i=0;i<v[now].size();i++)
        {
            int next=v[now][i].first;
            int cost=v[now][i].second;
            if(!ck[now][next]&&dist[next]>dist[now]+cost)
            {
                dist[next]=dist[now]+cost;
                pq.push(make_pair(next,dist[next]));
            }
        }
        
    }
}
int main()
{
    int ans=0;
    vector<ci> temp;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y,c;
        cin>>x>>y>>c;
        temp.push_back(make_pair(x,y));
        v[x].push_back(make_pair(y,c));
        v[y].push_back(make_pair(x,c));
    }
    dist.resize(n+1,MAX);
    dist[1]=0;
    dji(1,n);
    int mc=dist[n];
    for(int i=0;i<m;i++)
    {
        dist.clear();
        dist.resize(n+1,MAX);
        dist[1]=0;
        ck[temp[i].first][temp[i].second]=1;
        dji(1,n);
        ans=max(ans,dist[n]);
        if(dist[n]==MAX)break;
        ck[temp[i].first][temp[i].second]=0;
    }
    if(ans==MAX)cout<<-1;
    else cout<<ans-mc;
}
