#include <iostream>
#include <memory.h>
using namespace std;
int n;
int tb[101],ck[101],ins[101],flag;
void f(int x, int e)
{
    ck[x]=1;
    if (tb[x]==e)flag=1;
    if (!ck[tb[x]])f(tb[x],e);
}
int main()
{
    int i,ans=0;
    cin>>n;
    for(i=1;i<=n;i++)cin>>tb[i];
    for (i=1;i<=n;i++)
    {
        memset(ck,0,sizeof(ck));
        flag=0;
        f(i,i);
        if(flag)
        {
            ins[i]=1;
            ans++;
        }
    }
    cout<<ans<<endl;
    for(i=1;i<=n;i++)if(ins[i])cout<<i<<endl;
}
