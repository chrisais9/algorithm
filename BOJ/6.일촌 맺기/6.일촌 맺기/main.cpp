#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector< vector<int> > v(101);
queue<int> q;
int n,ck[101];
int main()
{
    int i,j;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        int x,t;
        cin>>t;
        for(j=0;j<t;j++)
        {
            cin>>x;
            v[i].push_back(x);
        }
    }
    ck[1]=1;
    q.push(1);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(i=0;i<v[x].size();i++)
        {
            if(ck[v[x][i]])continue;
            ck[v[x][i]]=ck[x]+1;
            q.push(v[x][i]);
        }
    }
    int ans=0,ma=0;
    for(i=1;i<=n;i++)
    {
        if(ma<ck[i])ma=ck[i];
        if(ck[i])ans++;
    }
    cout<<ma-2<<endl<<ans-1<<endl;
}
