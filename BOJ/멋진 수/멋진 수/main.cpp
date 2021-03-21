#include <iostream>
#include <fstream>
using namespace std;
int flag,cnt;
void f(int x,int prev)
{
    if(x<=0||flag)return;
    if(prev==(x&1))cnt++;
    else cnt=0;
    if(cnt==2)flag=1;
    f(x>>1,x&1);
    
    
}
int main()
{
    int i,ans=0,l,r;
    cin>>l>>r;
    for(i=l;i<=r;i++)
    {
        flag=0;
        f(i,2);
        if(flag)ans++;
    }
    cout<<ans;
}
