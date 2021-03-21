#include <iostream>
#include <string.h>
using namespace std;
void mtime(int t)
{
    int h=0,m=0,s=0;
    h=t/3600;
    t%=3600;
    m=t/60;
    t%=60;
    s=t;
    if(h<10)
    {
        if(h!=0)cout<<"0"<<h<<":";
        else cout<<"00:";
    }
    else cout<<h<<":";
    if(m<10)
    {
        if(m!=0)cout<<"0"<<m<<":";
        else cout<<"00:";
    }
    else cout<<m<<":";
    if(s<10)
    {
        if(s!=0)cout<<"0"<<s<<endl;
        else cout<<"00"<<endl;
    }
    else cout<<s<<endl;
}
int main()
{
    string a,b;
    int ta=0,tb=0;
    cin>>a>>b;
    ta=3600*((a[0]-'0')*10+(a[1]-'0'))+60*((a[3]-'0')*10+(a[4]-'0'))+((a[6]-'0')*10+(a[7]-'0'));
    tb=3600*((b[0]-'0')*10+(b[1]-'0'))+60*((b[3]-'0')*10+(b[4]-'0'))+((b[6]-'0')*10+(b[7]-'0'));
    if(ta<tb)mtime(tb-ta);
    else mtime(24*3600-(ta-tb));
}
