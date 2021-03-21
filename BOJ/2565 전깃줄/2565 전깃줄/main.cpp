#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair <int,int> ci;
vector<ci> v;
int tb[101];
int main()
{
    int i,j,n,mx;
    ci temp;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> temp.first >> temp.second;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    for(i=0;i<n;i++)
    {
        mx=0;
        for(j=0;j<i;j++)
        {
            if(v[i].second>v[j].second&&mx<tb[j])mx=tb[j];
        }
        tb[i]=mx+1;
    }
    cout << n-*max_element(tb,tb+n);
}
