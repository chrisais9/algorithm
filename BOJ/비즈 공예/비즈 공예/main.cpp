#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
typedef long long ll;
int n,sum;
ll dp[6][6][11][11][11][11][11];
vector<int> a;
ll dy(int prev,int cur,int N){
    if(N==0) return 1;
    ll &ret=dp[prev][cur][a[1]][a[2]][a[3]][a[4]][a[5]];
    if(ret!=-1) return ret;
    ret=0;
    for(int i=1;i<=n;++i)
    {
        if(prev==i || cur==i || !a[i]) continue;
        a[i]--;
        ret+=dy(cur,i,N-1);
        a[i]++;
    }
    return ret;
}
int main()
{
    a.reserve(10);
    ifstream in("input.txt");
    ofstream out("output.txt");
    in>>n;
    for(int i=1;i<=n;++i) in>>a[i],sum+=a[i];
    memset(dp,-1,sizeof(dp));
    out<<dy(0,0,sum);
}

