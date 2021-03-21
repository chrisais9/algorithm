#include <iostream>
#include <math.h>
using namespace std;
int gcd(int a,int b)
{
    if(a==0)return b;
    return gcd(b%a,a);
}
int main()
{
    int n,ans,x;
    cin>>n;
    while(n--)
    {
        ans=0;
        cin>>x;
        for(int j=1;j<=sqrt(x);j++)if(x%j==0)if(gcd(j,x/j)==1)ans++;
        cout<<ans<<"\n";
    }
}

