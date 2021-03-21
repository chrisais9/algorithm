#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        string x;
        cin>>x;
        cout<<(x[x.size()/2]==x[x.size()/2-1] ? "Do-it" : "Do-it-Not" )<<endl;
    }
}
