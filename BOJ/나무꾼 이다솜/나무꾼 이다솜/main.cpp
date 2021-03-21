#include <iostream>
#include <algorithm>
using namespace std;
int n,c,w,tb[1001],mx;

int main()
{
    int i,j,sup=0,sum=0,tp=0;
    cin>>n>>c>>w;
    for(i=0;i<n;i++)cin>>tb[i];
    sort(tb,tb+n);
    for(i=tb[n-1];i>=1;i--)
    {
        sup=0,sum=0,tp=0;
        for(j=0;j<n;j++)
        {
            sup=(tb[j]-1)/i;
            sum=((tb[j]/i)*i*w)-sup*c;
            if(sum>0)tp+=sum;
        }
        if(mx<tp)mx=tp;
    }
    cout<<mx;
}
