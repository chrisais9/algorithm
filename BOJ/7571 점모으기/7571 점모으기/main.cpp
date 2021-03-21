#include <iostream>
#include <vector>
using namespace std;
typedef pair<int,int> ci;
vector<ci> v;
int n,m;
int main()
{
    int i,x,y;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }
    sort(v.begin(),v.end());
    int sum=0;
    for(i=0;i<n;i++)sum+=abs(v[i].first-v[m/2+m%2].first)+abs(v[i].second-v[m/2+m%2].second);
    cout<<sum;
    
}
