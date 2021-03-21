#include <iostream>
using namespace std;
typedef long long lld;

int f(lld x)
{
    if(!x) return 0;
    return (x%10==5)+f(x/10);
}

int main( void )
{
    lld n;
    int k;
    cin>>n>>k;
    n++;
    
    lld num = 1;
    while(1)
    {
        cout<<n<<" "<<num<<endl;
        if( f(n) >= k ) break;
        while( (n/num)%10 == 5 ) num *= 10;
        n += num;
    }
    cout<<n;
}
