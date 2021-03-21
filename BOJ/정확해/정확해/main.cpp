#include <iostream>
using namespace std;
int a, b, n, res;

int main()
{
    int i, j;
    cin>>a>>b>>n;
    int k=a+b, l=a-1;
    for(i=1; i<=a+b; i++)
    {
        int p=1;
        for(j=1; j<=n; j++)
        {
            if(p>(a+b)/i)
            {
                p=a+b+1;
                break;
            }
            p*=i;
        }
        k=a+b;
        l=a-1;
        if(k<i) k=i;
        if(l<i) l=i;
        res+=k/i-l/i-k/p+l/p;
    }
    cout<<res;
}
