#include <iostream>
using namespace std;
int main()
{
    int i,j,tb[1010],rtb[1010],a[1010],n,mx=0;
    cin>>n;
    for(i=1;i<=n;i++)cin>>a[i];
    for(i=1;i<=n;i++)
    {
        tb[i]=1;
        for(j=1;j<=i;j++)if(a[i]>a[j]&&tb[i]<tb[j]+1)tb[i]=tb[j]+1;
    }
    
    for(i=n;i>=1;i--)
    {
        rtb[i]=1;
        for(j=n;j>=i;j--)if(a[i]>a[j]&&rtb[i]<rtb[j]+1)rtb[i]=rtb[j]+1;
    }
    for(i=0;i<=n;i++){
        if(mx<tb[i]+rtb[i])mx=tb[i]+rtb[i];
    }
    cout<<mx-1;
}
