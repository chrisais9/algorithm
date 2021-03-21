#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int v[1000000],n,ans=1;
void f(int x,int id)
{
    if(x<=3)
    {
        if(x!=0)ans=(ans*x)%10007;
        return;
    }
    if(n<id)n=id;
    v[id]=x;
    f(x/2,id*2);
    f(x-x/2,id*2+1);
}
int main()
{
    int i,t;
    cin>>t;
    f(t,1);
    cout<<ans;
    
}
