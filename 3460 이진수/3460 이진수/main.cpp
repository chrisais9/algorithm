#include <iostream>
using namespace std;
int main()
{
    int a,T;
    cin>>T;
    while(T--)
    {
        cin>>a;
        for(int i=0;a;i++,a>>=1)if(a&1)cout<<i<<" ";
    }
}
