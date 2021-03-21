#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n+m;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
}

