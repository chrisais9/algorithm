#include <iostream>
#include <algorithm>
using namespace std;
int n,k;
int rev(int n)
{
    int ret = 0;
    while(n>0)
    {
        ret = ret*10 + n%10;
        n/=10;
    }
    return ret;
}
int main()
{
    cin>>n>>k;
    int ans = 0;
    for(int i=1;i<=k;++i) ans = max(ans,rev(n*i));
    cout<<ans;
}
