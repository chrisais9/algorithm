#include <iostream>
using namespace std;
int main()
{
    int i,m;
    cin>>m;
    if(m%3==1)
    {
        for(i=0;i<(m/3)-1;i++)cout<<3<<" ";
        cout<<4;
    }
    else if(m%3==2)
    {
        cout<<2<<" ";
        for(i=0;i<m/3;i++)cout<<3<<" ";
    }
    else for(i=0;i<m/3;i++)cout<<3<<" ";
}
