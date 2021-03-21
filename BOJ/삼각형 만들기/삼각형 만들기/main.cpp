#include <iostream>
#include <algorithm>
using namespace std;
int straw[1000005];
int n;
int main()
{
    cin>>n;
    for(int i=0;i<n;++i)cin>>straw[i];
    sort(straw,straw+n,greater<int>());
    for(int i=0;i<n;++i)
    {
        int a = straw[i];
        int b = straw[i+1];
        int c = straw[i+2];
        if(a+b>c && b+c>a && a+c>b)
        {
            cout<<a+b+c;
            return 0;
        }
    }
    cout<<-1;
}
