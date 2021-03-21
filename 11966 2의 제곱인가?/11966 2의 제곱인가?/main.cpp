#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int x;
    cin>>x;
    while(x>1)
    {
        if(x%2!=0)
        {
            cout<<"0"<<endl;
            break;
        }
        x>>=1;
    }
    if(x<=1)cout<<"1"<<endl;
}
