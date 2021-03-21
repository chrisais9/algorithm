#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    int n,mi=987654321,mx=-987654321;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        mi=min(mi,x);
        mx=max(mx,x);
    }
    cout<<mi<<" "<<mx;
}
