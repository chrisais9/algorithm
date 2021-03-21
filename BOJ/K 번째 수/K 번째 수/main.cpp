#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
typedef long long int lld;
lld n,k;
int main(){
    cin>>n>>k;
    lld i,t,l=1,r=n*n,ans=0;
    lld mid,cnt;
    while (l<=r)
    {
        mid = (l+r)/2;
        cnt = 0;
        cout<<mid<<endl;
        for (i=1; i<=n; i++)
        {
            t=mid/i;
            cnt+=min(n,t);
            cout<<t<<" "<<cnt<<endl;
        }
        cout<<endl;
        if (cnt >= k)
        {
            ans = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    cout<<ans;
}

