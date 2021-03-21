#include <iostream>
#include <vector>
#include <queue>
#define INT_MAX 2147483647
using namespace std;
typedef pair<int,int> ci;
struct cmp
{
    bool operator ()(ci a,ci b)
    {
        return a.second<b.second;
    }
};
priority_queue< ci,vector<ci>,cmp> pq;
vector< vector<ci> > v;
vector<int> dist(20010,INT_MAX);
int n,m,s;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int i;
    cin>>n>>m>>s;
    v.resize(n+1);
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
        int tcost=pq.top().second;
        pq.pop();
        if(dist[now]<tcost)continue;
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
        if(dist[i]==INT_MAX)cout<<"INF";
        else cout<<dist[i];
        cout<<"\n";
    }
}
