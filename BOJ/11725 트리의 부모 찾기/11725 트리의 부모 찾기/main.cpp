#include <iostream>
#include <vector>
using namespace std;

int n,ans[100010],ck[100010];
vector<int> tb[100010];
void f(int x) {
    ck[x]=1;
    for(int i=0;i<tb[x].size();i++) {
        int to = tb[x][i];
        if(!ck[to]) {
            ans[to]=x;
            f(to);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(int i=0;i<n-1;i++) {
        int x,y;
        cin>>x>>y;
        tb[x].push_back(y);
        tb[y].push_back(x);
    }
    f(1);
    for(int i=2;i<=n;i++) {
        cout<<ans[i]<<"\n";
    }
}
