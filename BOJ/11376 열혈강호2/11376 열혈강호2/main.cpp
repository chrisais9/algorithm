#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;
vector< vector<int> > v(1010);
int ck[1010],b[1010];
int n,m;
int f(int so)
{
    if(ck[so]==1)return 0;
    ck[so]=1;
    for(int i=0;i<v[so].size();i++)
    {
        int si=v[so][i];
        if(b[si]==0||f(b[si]))
        {
            b[si]=so;
            return 1;
        }
    }
    return 0;
}
int main()
{
    int i,j,t,x,ans=0;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        cin>>t;
        for(j=0;j<t;j++)
        {
            cin>>x;
            v[i].push_back(x);
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=0;j<2;j++)
        {
            memset(ck,0,sizeof(ck));
            if(f(i))ans++;
        }
    }
    cout<<ans<<endl;
}

