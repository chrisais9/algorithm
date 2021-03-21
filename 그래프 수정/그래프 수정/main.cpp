#include <iostream>
#include <stdio.h>
#include <fstream>
#include <queue>
using namespace std;
int n;
vector<int> adj[305];
int ans[305];
int ind[305];
int main()
{
    int i,j;
    ifstream in("input.txt");
    ofstream out("output.txt");
    freopen("input.txt", "r", stdin);
    cin>>n;
    for(i=0;i<n;++i)for(j=0;j<n;++j)
    {
        int x;
        scanf("%1d",&x);
        if(x)
        {
            adj[j].push_back(i);
            ind[i]++;
        }
    }
    priority_queue<int> pq;
    for(i=0;i<n;++i) if(!ind[i])pq.push(i);
    int cnt = n;
    while(!pq.empty())
    {
        int cur = pq.top();
        ans[cur]=cnt--;
        pq.pop();
        for(int nxt:adj[cur])
        {
            ind[nxt]--;
            if(!ind[nxt])pq.push(nxt);
        }
    }
    for(i=0;i<n;++i)
    {
        if(ind[i])
        {
            out<<-1;
            return 0;
        }
    }
    for(i=0;i<n;++i)out<<ans[i]<<endl;
}

