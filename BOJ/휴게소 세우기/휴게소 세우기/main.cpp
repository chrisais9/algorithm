#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int tb[500];
int isAvail(int k)
{
    int i,cnt=0;
    for(i=2;i<=n+2;++i)
    {
        if(tb[i]-tb[i-1]>k) cnt+=(tb[i]-tb[i-1]-1)/k;
    }
    if(cnt<=m)return 1;
    return 0;
}
int main()
{
    int i;
    cin>>n>>m>>tb[n+2];
    for(i=2;i<=n+1;++i)cin>>tb[i];
    sort(tb,tb+n+2);
    int left=0,right=99999999,mid;
    while(left<right)
    {
        mid=(left+right)/2;
        if(isAvail(mid))right=mid;
        else left=mid+1;
    }
    cout<<left;
}
