#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> ci;
vector<ci> v;
int n,T;
int ck[50010];
int bfs()
{
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int now=q.front();
        q.pop();
        for(int i=now;i<v.size();i++)
        {
            if(v[i].first-v[now].first>2||v[i].second-v[now].second>2||ck[i])continue;
            ck[i]=ck[now]+1;
            if(v[i].second>=T)
            {
                return ck[i]-1;
            }
            q.push(i);
        }
    }
    return -1;
}
int main()
{
    cin>>n>>T;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }
    v.push_back(make_pair(0,0));
    sort(v.begin(),v.end());
    cout<<bfs();
}
