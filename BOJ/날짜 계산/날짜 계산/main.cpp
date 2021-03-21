#include <iostream>
using namespace std;
int a,b,c;
int main()
{
    int i,ta=1,tb=1,tc=1;
    cin>>a>>b>>c;
    for(i=1;;i++)
    {
        if(ta==a&&tb==b&&tc==c)
        {
            cout<<i<<endl;
            return 0;
        }
        ta=(i%15)+1;
        tb=(i%28)+1;
        tc=(i%19)+1;
    }
}
