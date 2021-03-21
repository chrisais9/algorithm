#include <iostream>
using namespace std;
int n, k, r;
int main()
{
    int i,j,t;
    cin>>n>>k;
    for(i=1;i<=n;i++)
    {
        t=i;
        for(j=2;j<=k;j++)
        {
            do
            {
                if(t%j!=0)break;
                t /= j;
            }while(1);
        }
        cout<<r<<" "<<t<<endl;
        if(t==1)r++;
    }
    cout<<r;
}
