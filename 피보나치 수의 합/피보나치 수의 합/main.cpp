#include <iostream>
#define MOD 10000
using namespace std;
typedef long long int lld;

lld a, b;

void arrayMul(lld copy[][2], lld left[][2], lld right[][2])
{
    lld temp[2][2]={0, };
    
    for(int i=0 ; i<2 ; i++)
        for(int j=0 ; j<2 ; j++)
            for(int k=0 ; k<2 ; k++)
                temp[i][j]+=left[i][k]*right[k][j],temp[i][j]%=MOD;
    
    for(int i=0 ; i<2 ; i++)
        for(int j=0 ; j<2 ; j++)
            copy[i][j]=temp[i][j];
}
void fastArrayMul(lld copy[][2], lld n)
{
    lld ret[2][2]={{1, 0}, {0, 1}}, mul[2][2]={{1, 1}, {1, 0}};
    
    while(n)
    {
        if(n&1) arrayMul(ret, ret, mul);
        arrayMul(mul, mul, mul);
        n>>=1;
    }
    
    for(int i=0 ; i<2 ; i++)
        for(int j=0 ; j<2 ; j++)
            copy[i][j]=ret[i][j];
}
lld getFibo(lld n)
{
    if(n==0) return 0;
    
    lld ret[2][2]={{1, 0}, {0, 1}};
    fastArrayMul(ret, n);
    
    return ret[0][1];
}

int main(void)
{
    cin>>a>>b;
    lld sol = getFibo(b+2) - getFibo(a-1+2);
    cout<<(sol+MOD)%MOD<<endl;
}
