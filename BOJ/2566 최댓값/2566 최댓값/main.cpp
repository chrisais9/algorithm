#include <iostream>
using namespace std;
int main()
{
    int i,j,mx=0,t,x,y;
    for(i=1;i<=9;i++)
    {
        for(j=1;j<=9;j++)
        {
            cin>>t;
            if(t>mx)
            {
                mx=t;
                x=i;
                y=j;
            }
        }
    }
    cout<<mx<<endl<<x<<" "<<y<<endl;
    
}
