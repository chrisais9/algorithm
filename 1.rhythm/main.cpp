#include <iostream>
#include <algorithm>
using namespace std;
int N, val[2][1000], dp[1001][1001];
int hexa(int a, int b)
{
    int &ret = dp[a][b];
    if(ret != 99999) return ret;
    if(b == N) return ret = 0;
    
    int temp = abs(val[0][a]-val[1][b]);
    cout<<temp<<endl;
    return ret = min(hexa(a, b+1), hexa(a+1, b+1) + temp);
}

int main()
{
    cin>>N;
    for(int i=0; i<2; i++){
        for(int j=0; j<N; j++)cin>>val[i][j];
        sort(val[i], val[i]+N);
        reverse(val[i], val[i]+N);
    }
    memset(dp, 99999, sizeof(dp));
    dp[0][0]=0;
    cout<<hexa(0,0);
}
