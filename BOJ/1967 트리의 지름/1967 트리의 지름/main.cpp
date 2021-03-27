#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
typedef pair<int, int> p;
vector<vector<p> > v(10001);
int ck[10001];
int far,mxCost;
void dfs(int x,int sum) {
    if (ck[x]) return;
    if (mxCost < sum) {
        mxCost = sum;
        far = x;
    }
    ck[x] = 1;
    for (int i=0; i<(int)v[x].size(); i++) {
        dfs(v[x][i].first, sum + v[x][i].second);
    }
}
int main() {
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++) {
        int from,x,c;
        cin>>from>>x>>c;
        v[from].push_back(make_pair(x, c));
        v[x].push_back(make_pair(from, c));
    }
    dfs(1, 0);
    memset(ck, 0, sizeof(ck));
    mxCost = 0;
    dfs(far, 0);
    cout<<mxCost;
}
