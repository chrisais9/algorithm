#include <iostream>
#include <vector>
#include <queue>
#include <ctype.h>
#include <memory.h>
#define N 52
#define INF 987654321
using namespace std;
vector< vector<int> > v;
int n;
int cap[N][N],flow[N][N];
int ctoi(char x)
{
    if(isupper(x))return x-'A';
    else return x-'a'+26;
}
int f(int so,int si)
{
    int ans=0;
    while(1)
    {
        int way[N];
        memset(way,-1,sizeof(way));
        queue<int> q;
        q.push(so);
        while(!q.empty())
        {
            int now=q.front();
            q.pop();
            for(int i=0;i<v[now].size();i++)
            {
                int next=v[now][i];
                if(way[next]!=-1)continue;
                if(cap[now][next]-flow[now][next]>0)
                {
                    q.push(next);
                    way[next]=now;
                    if(next==si)break;
                }
            }
        }
        if(way[si]==-1)break;
        int mi=INF;
        for(int i=si;i!=so;i=way[i])mi=min(mi,cap[way[i]][i]-flow[way[i]][i]);
        for(int i=si;i!=so;i=way[i])
        {
            flow[way[i]][i]+=mi;
            flow[i][way[i]]-=mi;
        }
        ans+=mi;
    }
    return ans;
}
int main()
{
    v.resize(N+1);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        char x,y;
        int c;
        cin>>x>>y>>c;
        cap[ctoi(x)][ctoi(y)]+=c;
        v[ctoi(x)].push_back(ctoi(y));
        v[ctoi(y)].push_back(ctoi(x));
    }
    cout<<f(0,'Z'-'A');
}
