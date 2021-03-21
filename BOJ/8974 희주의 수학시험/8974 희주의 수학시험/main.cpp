#include <iostream>
using namespace std;
int main()
{
    int i,j,t,a,b,sm=0;
    cin>>a>>b;
    for(t=i=1;i<=b;)
    {
        for(j=t;j&&i<=b;j--)
        {
            if(a<=i)sm+=t;
            i++;
        }
        t++;
    }
    cout<<sm;
}
