#include <iostream>
#include <vector>
#include <queue>
#define INF 9999999
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
vector< vector<ci> > v;
int n,m,s;
int dist[20001];
int main()
{
    int i;
    cin>>n>>m>>s;
    v.resize(n+1);
    for(i=1;i<=n;i++)dist[i]=INF;
    for(i=0;i<m;i++)
    {
        int x,y,c;
        cin>>x>>y>>c;
        v[x].push_back(make_pair(y,c));
    }
    pq.push(make_pair(s,0));
    dist[s]=0;
    while(!pq.empty())
    {
        int now=pq.top().first;
        pq.pop();
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
    for(i=1;i<=n;i++)
    {
        if(dist[i]==INF)cout<<"INF";
        else cout<<dist[i];
        cout<<endl;
    }
}
