#include <iostream>
#include <fstream>
#include <memory.h>
#include <algorithm>
using namespace std;
long long D[55][111][111];
long long cnt[55];
long long power[55];
int n,d;
long long go(int level, int add, int upgrades)
{
    long long &ans = D[level][add][upgrades];
    if(ans!=-1) return ans;
    ans=0;
    if(level==n) return ans;
    long long maxupgrades = min((long long)upgrades,cnt[level]+add);
    for(int i=0; i<=maxupgrades; i++)
    {
        long long thislevel = power[level] * (cnt[level]+add-i);
        long long nextlevel = go(level+1,i,upgrades-i);
        ans = max(ans,thislevel+nextlevel);
    }
    return ans;
}
int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    cin>>n;
    for(int i=0; i<n; i++)cin>>cnt[i];
    for(int i=0; i<n; i++)cin>>power[i];
    cin>>d;
    memset(D,-1,sizeof(D));
    cout<<go(0,0,d);
    return 0;
}

