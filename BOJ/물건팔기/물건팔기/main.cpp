#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> ci;
vector<ci> v;
int n;
int main()
{
    int i,j,x,y,mx=0,ans=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }
    sort(v.begin(),v.end());
    for(i=0;i<n;i++)
    {
        int t=0;
        for(j=0;j<n;j++)
        {
            if(v[j].first>=v[i].first&&v[i].first-v[j].second>=0)
            {
                t+=v[i].first-v[j].second;
            }
        }
        if(mx<t)
        {
            mx=t;
            ans=v[i].first;
        }
    }
    cout<<ans;
}
