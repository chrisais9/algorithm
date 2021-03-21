#include <iostream>
using namespace std;
#define M 10000000
char che[M+1];
int prime[664580];
int main()
{
    long long i,j,k=0;
    for(i=2;i<=M;i++)
    {
        if(che[i]==0)
        {
            prime[k++]=i;
            for(j=i*i;j<=M;j+=i)che[j]=1;
        }
    }
    double a,b,t;
    int s=0;
    cin>>a>>b;
    for(i=0;i<k;i++)
    {
        t=(double)prime[i]*prime[i];
        if(t>b)break;
        for(;t<a;t*=prime[i]);
        for(;t<=b;t*=prime[i])s++;
    }
    cout<<s;
}
