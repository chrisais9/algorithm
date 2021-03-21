#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;
vector< vector<int> > v(110);
int n,m;
int ck[5010],b[5010];
int f(int so)
{
    if(ck[so])return 0;
    ck[so]=1;
    for(int i=0;i<v[so].size();i++)
    {
        int si=v[so][i];
        if(!b[si]||f(b[si]))
        {
            b[si]=so;
            return 1;
        }
    }
    return 0;
}
int main()
{
    int i,t,x,ans=0;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        cin>>t>>x;
        v[t].push_back(x);
    }
    for(i=1;i<=n;i++)
    {
        memset(ck,0,sizeof(ck));
        if(f(i))ans++;
    }
    cout<<ans;
}
