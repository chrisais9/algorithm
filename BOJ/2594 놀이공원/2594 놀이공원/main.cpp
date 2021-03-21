#include <iostream>
#include <vector>
using namespace std;
typedef pair<int,int> ci;
vector<ci> v;
int n;
int main()
{
    int i,x,y,ans=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x>>y;
        v.push_back(make_pair(x/100*60+x%100-10,y/100*60+y%100+10));
    }
    v.push_back(make_pair(0,600));
    v.push_back(make_pair(1320,0));
    sort(v.begin(),v.end());
    int cmp=v[0].second;
    for(i=1;i<v.size();i++)
    {
        if(ans<v[i].first-cmp)ans=v[i].first-cmp;
        if(v[i].second>cmp)cmp=v[i].second;
    }
    cout<<ans;
}
