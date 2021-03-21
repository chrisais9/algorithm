#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
int n,d,ck[10000],mi=9999999;
struct inp
{
    int s,e,l;
    bool operator ()(inp a,inp b)
    {
        return a.s<b.s;
    }
}data;
vector<inp> v;
void f(int now,int x,int dis)
{
    if(now==d)
    {
        if(mi>dis)mi=dis;
        return;
    }
    for(int i=x;i<v.size();i++)
    {
        if(ck[i]==0&&now<=v[i].s)
        {
            ck[i]=1;
            f(v[i].e,i,dis+v[i].s-v[i].e+v[i].l);
            ck[i]=0;
        }
    }
    
}
int main()
{
    int i,j,a,b,c;
    cin>>n>>d;
    for(i=0;i<n;i++)
    {
        cin>>a>>b>>c;
        if(b<=d&&a-b+c<0)
        {
            data.s=a;
            data.e=b;
            data.l=c;
            v.push_back(data);
        }
    }
    sort(v.begin(),v.end(),inp());
    data.s=d;
    data.e=d;
    data.l=0;
    v.push_back(data);
    f(0,0,d);
    cout<<mi;
}
