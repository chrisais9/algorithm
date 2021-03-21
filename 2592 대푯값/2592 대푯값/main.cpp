#include <iostream>
using namespace std;
int ck[10];
int main()
{
    int i,mx=0,sm=0,x;
    for(i=0;i<10;i++)
    {
        cin>>x;
        ck[x/10]++;
        sm+=x;
        if(mx<ck[x/10])mx=ck[x/10];
    }
    cout<<sm/10<<endl;
    for(i=1;i<=10;i++)
    {
        if(ck[i]==mx)
        {
            cout<<i*10<<endl;
            return 0;
        }
    }
}
