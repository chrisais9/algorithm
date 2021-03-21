#include <iostream>
using namespace std;
int n,tb[300000];
int f(int x)
{
    int sm=0;
    while(x>0)
    {
        sm+=x%10;
        x/=10;
    }
    return sm;
}
int main()
{
    int i,x,cnt,mx=0;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        if(tb[i]==0)
        {
            int ck[300000]={0,};
            x=i;
            cnt=1;
            tb[x]=ck[x]=1;
            while(1)
            {
                x=(x+f(x))%n;
                if(ck[x] )break;
                tb[x]=ck[x]=1;
                cnt++;
            }
            if(mx<cnt)mx=cnt;
        }
    }
    cout<<mx;
}
