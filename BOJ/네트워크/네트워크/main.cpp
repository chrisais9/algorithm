#include <iostream>
using namespace std;

int n, d[41], f[50000][41];

inline int func(int n, int m)
{
    if(f[n][m]!=-1) return f[n][m];
    
    int i, res=0;
    for(i=0; i<=m; i++) res+=func(n-1, m-i);
    
    f[n][m]=res;
    return res;
}

int dyn(int n)
{
    if(d[n]!=-1) return d[n];
    int i, j, k, l, e[41][41][41]={0,};
    e[0][0][0]=1;
    for(i=1; i<=n; i++)
    {
        int val=dyn(i-1);
        
        for(j=0; j<=n; j++) for(k=0; k<=n; k++) e[i][j][k]=e[i-1][j][k];
        for(j=0; j<=n; j++) for(k=0; k<=n; k++) if(e[i-1][j][k])
        {
            for(l=1; i*l+j<=n; l++)
            {
                if(l==1) e[i][i*l+j][k+l]+=e[i-1][j][k]*val;
                else e[i][i*l+j][k+l]+=e[i-1][j][k]*func(val, l);
            }
        }
    }
    
    d[n]=0;
    if(n==::n) for(i=0; i<=n; i++) d[n]+=e[n][n][i];
    else for(i=0; i<=n; i+=2) d[n]+=e[n][n][i];
    
    return d[n];
}

int main()
{
    int i, j;
    cin>>n;
    if(n==1)
    {
        cout<<1;
        return 0;
    }
    for(i=1; i<=n; i++) d[i]=-1;
    d[0]=1;
    for(i=1; i<50000; i++) for(j=0; j<=40; j++) f[i][j]=-1;
    f[0][0]=1;
    cout<<dyn(n);
    return 0;
}
