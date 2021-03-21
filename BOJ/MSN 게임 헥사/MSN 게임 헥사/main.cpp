#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
struct edge{int to,cap,cost,rev;};
int INF=1e9;
int n;
const int MAX_V=3002;
vector<edge> G[MAX_V];
int dist[MAX_V];
int prevv[MAX_V],preve[MAX_V];
int inq[MAX_V]={0,};
void addEdge(int from,int to,int cap,int cost){
    G[from].push_back({to,cap,cost,(int)G[to].size()});
    G[to].push_back({from,0,-cost,(int)G[from].size()-1});
}
pair<int,int> min_cost_flow(int s,int t){
    int res=0;
    int total=0;
    queue<int> q;
    while(true){
        for(int i=0;i<MAX_V;i++)dist[i]=INF;
        dist[s]=0;
        q.push(s);
        inq[s]=1;
        while(!q.empty()){
            int here=q.front();
            q.pop();
            inq[here]=0;
            for(int i=0;i<G[here].size();i++){
                edge &e=G[here][i];
                if(e.cap>0 && dist[e.to]>dist[here]+e.cost){
                    dist[e.to]=dist[here]+e.cost;
                    prevv[e.to]=here;
                    preve[e.to]=i;
                    if(!inq[e.to]){
                        q.push(e.to);
                        inq[e.to]=1;
                    }
                }
            }
        }
        if(dist[t]>=1e9){
            return {total,res};
        }
        int d=1e9;
        for(int v=t;v!=s;v=prevv[v]){
            d=min(d,G[prevv[v]][preve[v]].cap);
        }
        res+=d*dist[t];
        total+=d;
        for(int v=t;v!=s;v=prevv[v]){
            edge&e=G[prevv[v]][preve[v]];
            e.cap-=d;
            G[v][e.rev].cap+=d;
        }
    }
    return {total,res};
}

int main()
{
    ios::sync_with_stdio(false);
    int source=0;
    int sink=2005;
    int a[1001],b[1001];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    for(int i=1;i<=n;i++){
        addEdge(source,i,1,0);
        addEdge(i+n,sink,1,0);
        for(int j=1;j<=n;j++){
            if(a[i]>b[j]){addEdge(i,j+n,1,-2); }
            else if(a[i]==b[j]){addEdge(i,j+n,1,-1);}
            else addEdge(i,j+n,1,0);
        }
    }
    auto node=min_cost_flow(source,sink);
    cout<<-node.second;
}
