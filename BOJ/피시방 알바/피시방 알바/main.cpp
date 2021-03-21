#include <iostream>
using namespace std;
int com[110];
int main()
{
    int i,n,x,ans=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x;
        if(com[x]==0)com[x]=1;
        else ans++;
    }
    cout<<ans;
}
