#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#define MOD 999983
using namespace std;
int K;
string good;
long long d[60][600];
long long ans = 0;
bool c[10];
int main(){
    cin>> K >> good;
    int i,j,k;
    int len = good.size();
    for(int i=0; i<len; i++) c[(int)(good[i]-'0')] = true;
    d[0][0] = 1;
    for(i=1; i<=K*10; i++) d[0][i] = 0;
    
    for(i=1; i<=K; i++)
        for(j=0; j<=K*10; j++)
            for(k=0; k<=9; k++)
                if(c[k] && j+k <= K*10)
                    d[i][j+k] = (d[i][j+k] + d[i-1][j]) % MOD;
    
    for(i=0; i<=10*K; i++) ans = (ans+2*d[K][i]*d[K][i])%MOD;
    for(i=0; i<=10*K; i++)
    {
        for(j=0; j<=10*K; j++)
        {
            ans = (ans - ((d[K/2][i] * d[K-K/2][j])%MOD) * ((d[K/2][i]*d[K-K/2][j])%MOD))%MOD;
            if(ans<0)ans+=MOD;
        }
    }
    cout<<(long long)ans<< endl;
} 
