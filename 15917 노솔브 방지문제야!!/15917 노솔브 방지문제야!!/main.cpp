#include <iostream>
using namespace std;
int x;
int main()
{
    int q;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>q;
    while(q--)
    {
        cin>>x;
        if((x&(-x))==x)cout<<1<<"\n";
        else cout<<0<<"\n";
    }
}
