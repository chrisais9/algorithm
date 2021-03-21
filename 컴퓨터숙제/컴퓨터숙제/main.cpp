#include <iostream>
using namespace std;
int n;
int main()
{
    cin>>n;
    for(int i=2;i*i<=n;i++)
    {
        if(n % i == 0)
        {
            cout<<n/i<<endl;
            return 0;
        }
    }
    cout<<n<<endl;
}
