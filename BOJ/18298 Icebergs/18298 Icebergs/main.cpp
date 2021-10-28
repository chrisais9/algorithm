#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
typedef long double lld;
typedef pair<lld,lld> pi;
vector<pi> v;
lld ccw(pi a, pi b, pi c) {
    return (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);
}
int main() {
    int n,m;
    cin>>m;
    lld ans=0;
    while(m--) {
        cin>>n;
        for(int i=0;i<n;i++) {
            lld x,y;
            cin>>x>>y;
            v.push_back(make_pair(x, y));
        }
        lld sum=0;
        for(int i=1;i<v.size()-1;i++) {
            sum+=ccw(v[0],v[i],v[i+1]);
        }
        ans+=abs(sum);
        v.clear();
    }
    cout<<(long long int)(ans/2);
}
