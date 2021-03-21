#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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
vector< vector<ci> > v;
int n,m;
int djikstra(int s,int e)
{
    int dis[801];
    for(int i=0;i<=n;i++)dis[i]=INF;
    priority_queue< ci,vector<ci>,cmp> q;
    q.push(make_pair(s,0));
    dis[s]=0;
    while (!q.empty())
    {
        int now=q.top().first;
        q.pop();
        for(int i=0;i<v[now].size();i++)
        {
            int next=v[now][i].first;
            int cost=v[now][i].second;
            if(dis[next]>dis[now]+cost)
            {
                dis[next]=dis[now]+cost;
                q.push(make_pair(next,dis[next]));
            }
        }
    }
    return dis[e];
}
int main()
{
    int i,t1,t2;
    cin>>n>>m;
    v.resize(n+1);
    for(i=0;i<m;i++)
    {
        int x,y,c;
        cin>>x>>y>>c;
        v[x].push_back(make_pair(y,c));
        v[y].push_back(make_pair(x,c));
    }
    cin>>t1>>t2;
    int onetot1=djikstra(1,t1),t1tot2=djikstra(t1,t2),t2ton=djikstra(t2,n),
    onetot2=djikstra(1,t2),t1ton=djikstra(t1,n);
    if((onetot1>=INF&&onetot2>=INF)||(t1ton>=INF&&t2ton>=INF)||t1tot2>=INF)
    {
        cout<<-1<<endl;
        return 0;
    }
    int a_way=-1,b_way=-1;
    if(!(onetot1>=INF||t1tot2>=INF||t2ton>=INF))a_way=onetot1+t1tot2+t2ton;
    if(!(onetot2>=INF||t1tot2>=INF||t1ton>=INF))b_way=onetot2+t1tot2+t1ton;
    if(a_way==-1&&b_way==-1)
    {
        cout<<-1<<endl;
        return 0;
    }
    cout<<min(a_way,b_way)<<endl;
}
