#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n,m;
struct fq {
    int num,mi,mx;
};
typedef pair<int,int> ci;
vector< vector<ci> > v;
void bfs(int s,int e)
{
    bool ck[100010]={0,};
    fq temp;
    temp.num=s;
    temp.mi=99999999;
    temp.mx=0;
    queue<fq> q;
    q.push(temp);
    ck[s]=1;
    while(!q.empty())
    {
        temp=q.front();
        int x=temp.num;
        q.pop();
        for(int i=0;i<v[x].size();i++)
        {
            if(!ck[v[x][i].first])
            {
                fq nxt;
                ck[v[x][i].first]=1;
                nxt.num=v[x][i].first;
                nxt.mi=min(temp.mi,v[x][i].second);
                nxt.mx=max(temp.mx,v[x][i].second);
                if(v[x][i].first==e)
                {
                    cout<<nxt.mi<<" "<<nxt.mx<<endl;
                    return;
                }
                q.push(nxt);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    v.resize(n+1);
    for(int i=0;i<n-1;i++)
    {
        int x,y,c;
        cin>>x>>y>>c;
        v[x].push_back(make_pair(y,c));
        v[y].push_back(make_pair(x,c));
    }
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int s,e;
        cin>>s>>e;
        bfs(s,e);
    }
}
