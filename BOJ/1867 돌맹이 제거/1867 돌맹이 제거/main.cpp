#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;
vector< vector<int> > v(501);
int n,k,cnt;
int ar[501],br[501],ck[501];
bool f(int a)
{
    if(ck[a]==cnt)return false;
    ck[a]=cnt;
    for (int i=0;i<v[a].size();i++)
    {
        int b=v[a][i];
        if(br[b]==-1||f(br[b]))
        {
            br[b] = a;
            ar[a] = b;
            return true;
        }
    }
    return false;
}
int main()
{
    cin>>n>>k;
    for(int i=0;i<k;i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
    }
    memset(ar, -1, sizeof(ar));
    memset(br, -1, sizeof(br));
    int ans = 0;
    for (int st = 1; st <= n; st++)
    {
        cnt++;
        ans+=f(st);
    }
    cout<<ans;
}
