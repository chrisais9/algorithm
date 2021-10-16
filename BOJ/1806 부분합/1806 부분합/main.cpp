#include <iostream>
#include <algorithm>
#define INF 0x7fffffff
using namespace std;
int tb[100001];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,s=0,e=0,sum,ans=INF;
    cin >> n >> m;
    for(int i=0;i<n;i++) cin>>tb[i];
    sum=tb[0];
    while (s<=e && e<n) {
        if(sum==m) {
            ans = min(ans, e-s+1);
            sum+=tb[++e];
        } else if(sum<m) {
            sum+=tb[++e];
        } else {
            ans = min(ans, e-s+1);
            sum-=tb[s++];
        }
    }
    cout << (ans==INF ? 0 : ans) << endl;
}
