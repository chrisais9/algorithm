#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;
#define INF 999999999
int n,m,s,e,flag;
typedef pair<int,int> ci;
vector<vector<pair<int, int>>> v;
bool ck[501][501];
int dis[501],way[501];
void di_1(int st, int en)
{
    priority_queue< ci,vector<ci>,greater<ci> > pq;
    memset(dis,INF,sizeof(dis));
    dis[st] = 0;
    pq.push(make_pair(st,0));
    while (!pq.empty())
    {
        int now = pq.top().first;
        pq.pop();
        for(int i=0;i<v[now].size();i++)
        {
            int next=v[now][i].first;
            int cost=v[now][i].second+dis[now];
            if(dis[next]>cost)
            {
                way[next]=now;
                dis[next]=cost;
                pq.push(make_pair(next,cost));
            }
        }
    }
    
}
void di_2(int st,int en)
{
    priority_queue< ci,vector<ci>,greater<ci> > pq;
    memset(dis,INF,sizeof(dis));
    dis[st]=0;
    pq.push(make_pair(st,0));
    while(!pq.empty())
    {
        int now=pq.top().first;
        pq.pop();
        for(int i=0;i<v[now].size();i++)
        {
            int next=v[now][i].first;
            int cost=v[now][i].second+dis[now];
            if(dis[next]>cost&&!ck[now][next])
            {
                dis[next]=cost;
                pq.push(make_pair(next,cost));
            }
        }
    }
}
void back_way(int x)
{
    if(flag)return;
    if(x==s)
    {
        flag=1;
        return;
    }
    ck[way[x]][x]=1;
    back_way(way[x]);
}
int main()
{
    while(1)
    {
        cin>>n>>m;
        if(n==0&&m==0)break;
        cin>>s>>e;
        v.clear();
        v.resize(n+1);
        memset(ck,false,sizeof(ck));
        memset(way,-1,sizeof(way));
        for(int i=0;i<m;i++)
        {
            int x,y,c;
            cin>>x>>y>>c;
            v[x].push_back(make_pair(y,c));
        }
        di_1(s,e);
        back_way(e);
        di_2(s,e);
        if(dis[e]==INF)cout<<-1<<endl;
        else cout<<dis[e];
    }
}
