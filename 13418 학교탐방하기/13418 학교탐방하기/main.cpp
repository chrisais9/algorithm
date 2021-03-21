#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

vector<vector<pair<int,int> > > v;
priority_queue<pair<int,int> > pq;
int ck[1010];
int n,m;
int main(){
    
    cin>>n>>m;
    v.resize(n+1);
    int a,b,c,start_c;
    for(int i=0;i<=m;i++)
    {
        cin>>a>>b>>c;
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
        if(a+b==1) start_c=c?0:1;
    }
    int W=0,B=0;
    pq.push(make_pair(-1,0));
    while(!pq.empty())
    {
        int here = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        
        if(ck[here]) continue;
        ck[here]=true;
        
        if(!cost) W++;
        
        for(int i=0;i<v[here].size();i++)
        {
            int next = v[here][i].first;
            int ccc = v[here][i].second;
            
            if(!ck[next]) pq.push(make_pair(-ccc,next));
        }
    }
    
    pq.push(make_pair(1,0));
    memset(ck,0,1010);
    while(!pq.empty()){
        int here = pq.top().second;
        int cost = pq.top().first; pq.pop();
        
        if(ck[here]) continue;
        ck[here]=true;
        
        if(!cost) B++;
        
        for(int i=0;i<v[here].size();i++){
            int next = v[here][i].first;
            int ccc = v[here][i].second;
            
            if(!ck[next]) pq.push(make_pair(ccc,next));
        }
    }
    cout<<W*W-B*B;
}
