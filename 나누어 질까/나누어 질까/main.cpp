#include <iostream>
#include <fstream>
using namespace std;
int a[20],n;
int main()
{
    int i,j,l,r,ans=0;
    cin>>n>>l>>r;
    for(i=0;i<n;i++)cin>>a[i];
    for(i=l;i<=r;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i%a[j]==0)
            {
                ans++;
                break;
            }
        }
    }
    cout<<ans;
}
