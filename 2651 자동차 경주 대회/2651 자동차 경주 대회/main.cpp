#include <iostream>
#include <vector>
using namespace std;
int tb[110],tm[110],dis[110],way[110];
int n,l;
void path(int x)
{
    if(tb[x]==0)return;
    path(tb[x]);
    cout<<x<<" ";
}
int main()
{
    int i,j;
    cin>>l>>n;
    for(i=1;i<=n+1;i++)
    {
        cin>>dis[i];
        dis[i]+=dis[i-1];
    }
    for(i=1;i<=n;i++)cin>>tm[i];
    for(i=0;i<=n+1;i++)tb[i]=0x7fffffff;
    tb[0]=0;
    for(i=1;i<=n+1; i++)
    {
        for(j=i-1; j>=0; j--)
        {
            if(dis[i]-dis[j]<=l)
            {
                if(tb[j]+tm[i]<tb[i])
                {
                    tb[i]=tb[j]+tm[i];
                    way[i]=j;
                }
            }
        }
    }
    cout<<tb[n+1]<<endl;
    vector<int> an;
    for(i=way[n+1];i!=0;i=way[i])an.push_back(i);
    cout<<an.size()<<endl;
    for(auto t:an)cout<<t<<" ";
}
