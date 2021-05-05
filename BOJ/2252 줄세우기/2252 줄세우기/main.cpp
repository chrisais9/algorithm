#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector <vector<int> > v(32001);
queue<int> q;
int vet[32001],n,m;
int main() {
    cin>>n>>m;
    for(int i=0;i<m;i++) {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        vet[y]++;
    }
    for(int i=1;i<=n;i++) {
        if (!vet[i]) {
            q.push(i);
        }
    }
    for(int i=0;i<n;i++) {
        int p = q.front();
        cout<<p<<" ";
        q.pop();
        
        for(int j=0;j<v[p].size();j++) {
            vet[v[p][j]]--;
            if (!vet[v[p][j]]) {
                q.push(v[p][j]);
            }
        }
    }
}
