#include <iostream>
#include <fstream>
using namespace std;

typedef long long int lld;
int n,m,i,j;
lld tb[21][21]={1},dv;
lld gcd(lld a, lld b)
{
    return b ? gcd(b, a%b) : a;
}
int main()
{
    cin>>n>>m;
    for(i=1;i<=n;i++)for(j=1;j<=i;j++)tb[i][j]=tb[i-1][j-1]+(i-1)*tb[i-1][j];
    for(i=1;i<=n;i++)tb[n][i]+=tb[n][i-1];
    dv=gcd(tb[n][n],tb[n][m]);
    cout<<tb[n][m]/dv<<"/"<<tb[n][n]/dv;
}
