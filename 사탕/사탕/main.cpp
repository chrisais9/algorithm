#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, input[52], t, primecheck[500001];
long long int d[2][500001], res;
vector <int> v, cnt;

int main()
{
    int i, j, k;
    cin>>n;
    for(i=1; i<=n; i++) cin>>input[i];

    sort(input+1, input+n+1);
    input[++n]=1000000000;
    
    int st=1;
    for(i=2; i<=n; i++) if(input[i]!=input[st]) v.push_back(input[st]), cnt.push_back(i-st), st=i;
    
    d[t][0]=1;
    int lim=0;
    for(j=0; j<v.size(); j++)
    {
        t=!t;
        for(i=0; i<=lim; i++) d[t][i]=d[!t][i];
        for(i=lim; i>=0; i--) if(d[!t][i]) for(k=1; k<=cnt[j]; k++) d[t][i+v[j]*k]+=d[!t][i];
        lim+=v[j]*cnt[j];
    }
    
    for(i=2; i<=500000; i++)if(primecheck[i]==0)
    {
        res+=d[t][i];
        for(j=2*i; j<=500000; j+=i) primecheck[j]=1;
    }
    cout<<res;
}
