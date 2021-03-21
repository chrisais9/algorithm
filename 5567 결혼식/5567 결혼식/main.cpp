#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector< vector<int> > v(501);
queue<int> q;
int n,m;
int ck[501];
int main()
{
    int i;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(i=0;i<v[1].size();i++)
    {
        if(!ck[v[1][i]])
        {
            ck[v[1][i]]=1;
            q.push(v[1][i]);
        }
    }
    while (!q.empty())
    {
        int x=q.front();
        q.pop();
        for(i=0;i<v[x].size();i++)
        {
            if(!ck[v[x][i]])
            {
                ck[v[x][i]]=1;
            }
            
        }
    }
    int ans=0;
    for(i=2;i<=n;i++)if(ck[i])ans++;
    cout<<ans;
}
