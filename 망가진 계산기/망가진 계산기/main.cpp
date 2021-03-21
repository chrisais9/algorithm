#include <iostream>
#include <fstream>
using namespace std;
int mx,d,p,flag;
int cnt(int x)
{
    int t=0;
    do
    {
        if(x<=0)return t;
        x/=10;
        t++;
    }while(1);
}
void f(int dep,int num)
{
    if(flag||cnt(num)>d)return;
    if(dep==p)
    {
        mx=num;
        flag=1;
    }
    for(int i=9;i>=2;i--)f(dep+1,num*i);
}
int main()
{
    cin>>d>>p;
    f(0,1);
    cout<<mx;
}
