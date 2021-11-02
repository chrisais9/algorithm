#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int main() {
    int n,x,ans = 0;
    cin>>n;
    v.push_back(-0x7fffffff);
    while(n--) {
        cin>>x;
        if (v.back() < x) {
            v.push_back(x);
            ans++;
        }
        else {
            vector<int>::iterator it = lower_bound(v.begin(), v.end(), x);
            *it = x;
        }
    }
    cout<<ans;
}
