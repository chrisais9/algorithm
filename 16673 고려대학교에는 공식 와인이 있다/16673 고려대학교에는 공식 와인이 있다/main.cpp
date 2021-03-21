#include <iostream>
using namespace std;
int main()
{
    long long int sm=0;
    int c,k,p;
    cin>>c>>k>>p;
    for(int i=1;i<=c;i++)sm+=((k*i)+(p*i*i));
    cout<<sm;
}
