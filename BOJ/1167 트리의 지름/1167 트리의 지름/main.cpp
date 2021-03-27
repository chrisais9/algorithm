#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
typedef pair<int, int> p;
vector<vector<p> > v(100001);
int ck[100001];
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
    for(int i=0;i<n;i++) {
        int from;
        cin>>from;
        for(int j=0;;j++) {
            int x,c;
            cin>>x;
            if (x==-1) break;
            cin>>c;
            v[from].push_back(make_pair(x, c));
            v[x].push_back(make_pair(from, c));
        }
    }
    dfs(1, 0);
    memset(ck, 0, sizeof(ck));
    mxCost = 0;
    dfs(far, 0);
    cout<<mxCost;
}
