#include <iostream>
using namespace std;
int n;
int tb[31];
int main()
{
    tb[0]=1;
    tb[1]=0;
    tb[2]=3;
    cin>>n;
    if (n % 2 == 0)
    {
        for (int i = 4; i <= n; i+=2)
        {
            tb[i]=tb[i-2]*3;
            for(int j=4;i-j>=0;j+=2)tb[i]+=tb[i-j]*2;
        }
    }
    cout << tb[n] << endl;
}
