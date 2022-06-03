#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector< pair<int,int> > v;

bool comp(const pair<int, double> a, const pair<int, double> b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        int x,y;
        cin>>x>>y;
        v.push_back(make_pair(x, y));
    }
    
    sort(v.begin(), v.end(), comp);
    
    int ans=0, end=0;
    for(int i=0;i<v.size();i++) {
        if(end<=v[i].first) {
            end=v[i].second;
            ans++;
        }
    }
    cout<<ans;
}
