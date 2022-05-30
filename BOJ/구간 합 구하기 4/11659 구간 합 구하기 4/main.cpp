#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long lld;
int sqrtN;
struct Query {
    int idx, s, e;
};
bool cmp(const Query &a, const Query &b) {
    if(a.s/sqrtN != b.s/sqrtN) return a.s/sqrtN < b.s/sqrtN;
    return a.e < b.e;
}
vector<Query> q;
vector<int> v;
lld res = 0;
lld ans[100010];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, qn;
    cin >> n >> qn;
    sqrtN = sqrt(n);
    v.resize(n+1);
    
    for(int i=1;i<=n;i++) {
        cin>>v[i];
    }
    for(int i=0; i<qn; i++){
        int s, e; cin >> s >> e;
        q.push_back({i, s, e});
    }
    sort(q.begin(), q.end(), cmp);
    
    int s = q[0].s, e = q[0].e;
    for(int i=s; i<=e; i++){
        res += v[i];
    }
    ans[q[0].idx] = res;
    
    for(int i=1; i<qn; i++){
        while(s < q[i].s) res-=v[s++];
        while(s > q[i].s) res+=v[--s];
        while(e < q[i].e) res+=v[++e];
        while(e > q[i].e) res-=v[e--];
        ans[q[i].idx] = res;
    }
    for(int i=0; i<qn; i++) cout << ans[i] << "\n";
}
