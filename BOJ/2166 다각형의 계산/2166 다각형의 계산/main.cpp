#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
typedef long long int lld;
typedef pair<lld,lld> pi;
vector<pi> v;
lld ccw(pi a, pi b, pi c) {
    return (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);
}
int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        lld x,y;
        cin>>x>>y;
        v.push_back(make_pair(x, y));
    }
    
    lld ans=0;
    for(int i=1;i<v.size()-1;i++) {
        ans+=ccw(v[0],v[i],v[i+1]);
    }
    cout<<abs(ans/2)<<(ans&1?".5":".0");
}
