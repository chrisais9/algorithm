#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define V 2500
#define INF 0x7ffffffffffffff
using namespace std;
int min2(int x,int y)
{
    return (x<y?x:y);
}
int n,m,oil_v[V+1];
vector<int> go[V+1],d[V+1];
long long shortest_d[V+1][V+1];
priority_queue<pair<int,long long>,vector<pair<int,long long> >,greater<pair<int,long long> > > q;
void input(void)
{
    int i,v1,v2,weight;
    cin>>n>>m;
    for(i=1;i<=n;i++)cin>>oil_v[i];
    for(i=1;i<=n;i++)
    {
        cin>>v1>>v2>>weight;
        go[v1].push_back(v2);
        d[v1].push_back(weight);
        go[v2].push_back(v1);
        d[v2].push_back(weight);
    }
}
void djikstra(int start)
{
    int i,j,size_p;
    bool check[V+1];
    pair<int,long long> t,tt;
    for(i=1;i<=n;i++)check[i]=false;
    tt.first=0;
    tt.second=start;
    q.push(tt);
    for(i=1;i<=n;i++)
    {
        while(!q.empty())
        {
            t=q.top();
            q.pop();
            if(!check[t.second])break;
        }
        check[t.second]=true;
        size_p=go[t.second].size();
        for(j=0;j<size_p;j++)
        {
            if(shortest_d[start][go[t.second][j]]>shortest_d[start][go[t.second][j]]+oil_v[start]*d[t.second][j])
            {
                
                
                shortest_d[start][go[t.second][j]]=shortest_d[start][go[t.second][j]]+oil_v[start]*d[t.second][j];
                tt.first=shortest_d[start][go[t.second][j]];
                tt.second=go[t.second][j];
                q.push(tt);
            }
        }
    }
    while(!q.empty())q.pop();
}
long long get_answer(void)
{
    int i,j,ii,jj;
    pair<int,int> sorted_oil_v[V+1];
    long long min_cost[V+1];
    for(i=1;i<=n;i++)
    {
        sorted_oil_v[i].first=-oil_v[i];
        sorted_oil_v[i].second=i;
    }
    sort(sorted_oil_v+2,sorted_oil_v+n);
    min_cost[1]=0;
    for(i=2;i<=n;i++)
    {
        ii=sorted_oil_v[i].second;
        min_cost[ii]=INF;
        for(j=1;j<i;j++)
        {
            jj=sorted_oil_v[j].second;
            min_cost[ii]=min2(min_cost[ii],min_cost[jj])+shortest_d[jj][ii];
        }
    }
    return min_cost[n];
}
int main()
{
    int i,j;
    input();
    for(i=1;i<n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            shortest_d[i][j]=shortest_d[j][i]=INF;
        }
        djikstra(i);
    }
    cout<<get_answer();
}
