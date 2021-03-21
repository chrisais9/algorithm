#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> ci;
vector<ci> v;
int n, r;
int main()
{
    cin>>n;
    for (int i=0;i<n;i++)
    {
        ci temp;
        cin>>temp.first;
        temp.second=i;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    for (int i = 0; i < n; i++)r=max(r,v[i].second-i);
    cout<<r;
}

