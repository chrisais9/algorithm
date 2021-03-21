#include <iostream>
using namespace std;
long long int tb[200][200][200];
int main()
{
    int i,j,k,n,l,r;
    cin>>n>>l>>r;
    tb[1][1][1]=tb[2][2][1]=tb[2][1][2]=1;
    for(i=3;i<=n;i++)
    {
        for(j=1;j<=l;j++)
        {
            for(k=1;k<=r;k++)
            {
                tb[i][j][k]+=tb[i-1][j-1][k];
                tb[i][j][k]%=1000000007;
                tb[i][j][k]+=tb[i-1][j][k-1];
                tb[i][j][k]%=1000000007;
                tb[i][j][k]+=tb[i-1][j][k]*(i-2);
                tb[i][j][k]%=1000000007;
            }
        }
    }
    cout<<tb[n][l][r];
}
