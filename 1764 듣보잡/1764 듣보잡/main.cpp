#include <iostream>
#include <set>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int n,m;
set<string> s;
vector<string> v;
int main()
{
    int i;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        string t;
        cin>>t;
        s.insert(t);
    }
    for(i=0;i<n;i++)
    {
        string t;
        cin>>t;
        if(s.find(t)!=s.end())v.push_back(t);
    }
    sort(v.begin(),v.end());
    cout<<v.size()<<endl;
    for(i=0;i<v.size();i++)cout<<v[i]<<endl;
}
