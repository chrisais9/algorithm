#include <iostream>
using namespace std;
bool ifzero(string x)
{
    for(int i=0;i<x.size();i++)if(x[i]!='2'&&x[i]!='0'&&x[i]!='1'&&x[i]!='8')
        return false;
    return true;
}
int main()
{
    string x;
    cin>>x;
    if(!ifzero(x))cout<<0<<endl;
    else
    {
        int two=0,zero=0,one=0,eight=0;
        for(int i=0;i<x.size();i++)
        {
            if(x[i]=='2')two++;
            if(x[i]=='0')zero++;
            if(x[i]=='1')one++;
            if(x[i]=='8')eight++;
        }
        if(two==zero&&zero==one&&one==eight)cout<<
    }
}
