#include <iostream>
using namespace std;
int n,d,k,c,mx;
int tb[60010],eat[3010];
int main()
{
    int i,t,cnt=0;
    cin>>n>>d>>k>>c;
    for(i=0;i<n;i++)
    {
        cin>>t;
        tb[i]=tb[i+n]=t;
    }
    eat[c]++;
    for(i=0;i<k;i++)eat[tb[i]]++;
    for(i=0;i<=d;i++)if(eat[i])cnt++;
    for(i=1;i<n;i++)
    {
        eat[tb[i-1]]--;
        if(eat[tb[i-1]]==0)cnt--;
        if(eat[tb[i+k-1]]==0)cnt++;
        eat[tb[i+k-1]]++;
        if(mx<cnt)mx=cnt;
    }
    cout<<mx;
    
}
