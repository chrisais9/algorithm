#include <iostream>
#include <string>
using namespace std;
int main()
{
    string x;
    bool flag=0,pal=0;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>x;
    for(int i=0;i<x.size()/2;i++)
    {
        if(x[i]!=x[x.size()-i-1])
        {
            flag=1;
            break;
        }
        else if(x[i]!=x[i+1])pal=1;
    }
    if(flag)cout<<x.size()<<endl;
    else
    {
        if(pal)cout<<x.size()-1<<endl;
        else cout<<-1<<endl;
    }
}
