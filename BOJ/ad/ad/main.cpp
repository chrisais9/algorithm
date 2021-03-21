#include <iostream>
using namespace std;
int tb[5],sm;
int main()
{
    for(int i=0;i<5;i++)
    {
        cin>>tb[i];
        sm+=tb[i];
    }
    sort(tb,tb+5);
    cout<<sm/5<<" "<<tb[2];
}
