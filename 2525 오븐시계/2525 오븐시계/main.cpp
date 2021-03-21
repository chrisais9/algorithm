#include <iostream>
using namespace std;
int main()
{
    int h,m,e,t;
    cin>>h>>m>>e;
    t=h*60+m+e;
    t%=1440;
    cout<<t/60<<" "<<t%60;
}
