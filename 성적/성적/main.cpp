#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int,int> ci;
vector<ci> v;
bool cmp(ci a,ci b)
{
    return (double)a.first/a.second<(double)b.first/b.second;
}
int n;
int main()
{
    int i,j;
    cin>>n;
    for(i=0;i<n;i++)
    {
        int ti,pi;
        cin>>ti>>pi;
        v.push_back(make_pair(ti,pi));
    }
    sort(v.begin(),v.end(),cmp);
    for(i=0;i<n;i++)
    {
        cout<<v[i].first<<" "<<v[i].second<<" "<<(double)v[i].first/v[i].second<<endl;
    }
}
