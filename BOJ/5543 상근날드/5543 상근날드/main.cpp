#include <iostream>
using namespace std;
int ham[4],dri[3];
int main()
{
    int i,j,ans=999999999;
    for(i=0;i<3;i++)cin>>ham[i];
    for(i=0;i<2;i++)cin>>dri[i];
    for(i=0;i<3;i++)for(j=0;j<2;j++)if(ans>ham[i]+dri[j]-50)ans=ham[i]+dri[j]-50;
    cout<<ans;
}
