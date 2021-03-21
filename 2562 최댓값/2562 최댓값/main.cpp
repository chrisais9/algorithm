#include <iostream>
using namespace std;
int main()
{
    int x,mx=0,idx=-1;
    for(int i=0;i<9;i++)
    {
        cin>>x;
        if(x>mx)
        {
            idx=i;
            mx=x;
        }
    }
    cout<<mx<<endl<<idx+1;
}
