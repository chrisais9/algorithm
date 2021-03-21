#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector< vector<int> > v;
vector<bool> ck;
int n,m;
void bfs(int x)
{
    queue<int> q;
    q.push(x);
    ck[x]=1;
    while(!q.empty())
    {
        int now=q.front();
        q.pop();
        for(int i=0;i<v[now].size();i++)
        {
            if(!ck[v[now][i]])
            {
                ck[v[now][i]]=true;
                q.push(v[now][i]);
            }
        }
    }
}
int main()
{
    int i;
    cin>>n>>m;
    v.resize(n+1);
    ck.resize(n+1);
    for(i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int ans=0;
    for(i=1;i<=n;i++)
    {
        if(!ck[i])
        {
            ans++;
            bfs(i);
        }
    }
    cout<<ans<<endl;
}
