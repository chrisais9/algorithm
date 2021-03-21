#include <iostream>
using namespace std;
int main()
{
    int a,x;
    cin>>a;
    for(int i=0;i<9;i++)
    {
        cin>>x;
        a-=x;
    }
    cout<<a;
}
