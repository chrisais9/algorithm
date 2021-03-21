#include <iostream>
using namespace std;
int main()
{
    string a,b;
    cin>>a>>b;
    swap(a[0],a[2]);
    swap(b[0],b[2]);
    int ia,ib;
    ia=(a[0]-'0')*100+(a[1]-'0')*10+(a[2]-'0');
    ib=(b[0]-'0')*100+(b[1]-'0')*10+(b[2]-'0');
    cout<<max(ia,ib);
}
