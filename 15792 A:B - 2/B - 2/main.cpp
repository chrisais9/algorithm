#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a,b;
    cin>>a>>b;
    cout<<a/b<<".";
    a%=b;
    for(int i=0;i<1500;i++)
    {
        a*=10;
        cout<<a/b;
        a%=b;
        if(a==0)break;
    }
}
