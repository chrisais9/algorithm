#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> ci;
vector<ci> v;
int n,m,ans=0x7fffffff;
int ck[1001];
int main()
{
    int i,j,a;
    int p1=0,p2=0;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>a;
            v.push_back(make_pair(a,i));
        }
    }
    sort(v.begin(),v.end());
    do
    {
        if(ck[v[p2+1].second]-1>0)
        {
            p2++;
            ck[v[p2].second]--;
            ans=min(ans,abs(v[p1].first-v[p2].first));
        }
        else
        {
            p1++;
            if(p1>v.size())break;
            ck[v[p1].second]++;
        }
    }while(1);
    cout<<ans;
    
    
}
