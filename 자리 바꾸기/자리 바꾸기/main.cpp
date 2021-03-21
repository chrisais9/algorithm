#include <iostream>
using namespace std;

int n,k,num[300001],c[10],path[10];
long long int dis[10][10],ans,sum;

void back(int l)
{
    int i,j;
    if(l==k)
    {
        sum=0;
        for(i=0;i<k;i++)
        {
            for(j=i+1;j<k;j++)
            {
                sum+=dis[path[i]][path[j]];
            }
        }
        if(sum<ans || ans==-1) ans=sum;
    }
    for(i=1;i<=k;i++)
    {
        if(c[i]==0)
        {
            c[i]=1;
            path[l]=i;
            back(l+1);
            c[i]=0;
        }
    }
}

void process()
{
    int i,j,l,cnt;
    for(i=1;i<=k;i++)
    {
        for(j=1;j<=k;j++)
        {
            if(i==j) continue;
            cnt=0;
            dis[i][j]=0;
            for(l=0;l<n;l++)
            {
                if(num[l]==j) cnt++;
                if(num[l]==i) dis[i][j]+=cnt;
            }
        }
    }
    for(i=1;i<=k;i++) dis[0][i]=0;
    ans=-1;
    back(0);
    cout<<ans;
    
}

int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>num[i];
    process();
}
