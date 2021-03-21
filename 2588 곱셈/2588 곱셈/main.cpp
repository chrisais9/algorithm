#include <iostream>
using namespace std;
int main()
{
    int x,y,ans;
    cin>>x>>y;
    ans=x*y;
    cout<<x*(y%10)<<endl;
    y/=10;
    cout<<x*(y%10)<<endl;
    y/=10;
    cout<<x*(y%10)<<endl;
    cout<<ans;
}
