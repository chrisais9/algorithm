#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int i = 0, j;
    int n;
    cin>>n;
    while(n)
    {
        i++;
        for(j=i;j;j/=10)if(j%1000==666)break;
        if(j) n--;
    }
    cout<<i;
    return 0;
}
