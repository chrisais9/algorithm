#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lld;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    lld a,b;
    cin>>a>>b;
    if(a==b)
    {
        cout<<"0"<<endl;
        return 0;
    }
    if(a>b)swap(a,b);
    cout<<b-a-1<<endl;
    for(lld i=a+1;i<b;i++)cout<<i<<" ";
}
