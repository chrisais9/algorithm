#include <iostream>
#include<vector>
#include<queue>
using namespace std;
int n, m, k, dcnt[1001], dist[1001];
vector<pair<int, int> > V[1001];
priority_queue<pair<int, int> > pq;
int main()
{
    cin>>n>>m>>k;
    for (int i = 0; i < m; i++)
    {
        int x,y,c;
        cin>>x>>y>>c;
        V[x].push_back(make_pair(y, c));
    }
    pq.push(make_pair(0,1));
    
    while (!pq.empty())
    {
        int pos = pq.top().second, dis = -pq.top().first;
        pq.pop();
        if (dcnt[pos] == k) continue;
        if (dcnt[pos] == k - 1) dist[pos] = dis;
        for (auto it : V[pos]) pq.push({ -dis - it.second, it.first });
        dcnt[pos]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if(dcnt[i]==k)cout<<dist[i]<<endl;
        else cout<<-1<<endl;
    }
}
