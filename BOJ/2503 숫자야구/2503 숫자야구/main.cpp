#include <iostream>
using namespace std;
int num[4],n,ck[10];
struct cc
{
    int t[4],s,b;
}d[100];
void ini(int nu)
{
    int cnt=0;
    do
    {
        if(nu==0)break;
        num[2-cnt++]=nu%10;
        nu/=10;
    }while(1);
}
void dini(int nu,int i)
{
    int cnt=0;
    do
    {
        if(nu==0)return;
        d[i].t[2-cnt++]=nu%10;
        nu/=10;
    }while(1);
}
int strike()
{
    int i,j,cnt;
    for(i=0;i<n;i++)
    {
        cnt=0;
        for(j=0;j<3;j++)if(d[i].t[j]==num[j])cnt++;
        if(cnt!=d[i].s)return 0;

    }
    return 1;
}
int ball()
{
    int i,j,k,cnt,flag;
    for(i=0;i<n;i++)
    {
        cnt=0;
        for(j=0;j<3;j++)
        {
            flag=0;
            for(k=0;k<3;k++)
            {
                if(j!=k&&d[i].t[j]==num[k])flag=1;
            }
            if(flag)cnt++;
        }
        if(cnt!=d[i].b)return 0;
    }
    return 1;
}
int main()
{
    int i,j,temp,ans=0,flag;
    cin>> n;
    for(i=0;i<n;i++)
    {
        cin>>temp>>d[i].s>>d[i].b;
        dini(temp,i);
    }
    for(i=100;i<=999;i++)
    {
        flag=0;
        ini(i);
        for(j=0;j<3;j++)
        {
            ck[num[j]]++;
            if(ck[num[j]]>=2)
            {
                flag=1;
                break;
            }
            if(num[j]==0)flag=1;
        }
        for(j=0;j<10;j++)ck[j]=0;
        if(flag==1)continue;
        if(strike()&&ball())ans++;
    }
    cout << ans;
}
