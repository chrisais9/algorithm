#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int n,ka[30];
string key;
bool f(string x)
{
    int a[26]={0,},i,ck=0,flag;
    for(i=0;i<x.size();i++)a[x[i]-'A']++;
    for(i=0;i<=25;i++)
    {
        flag=abs(a[i]-ka[i]);
        if(flag==1)ck++;
        else if(flag>1)ck=99;
    }
    if(ck<2||(ck==2&&key.size()==x.size())) return true;
    return false;
}
int main()
{
    int i,ans=0;
    cin>>n>>key;
    n--;
    for(i=0;i<key.size();i++)ka[key[i]-'A']++;
    for(i=0;i<n;i++)
    {
        string x;
        cin>>x;
        if(f(x))ans++;
    }
    cout<<ans;
}
