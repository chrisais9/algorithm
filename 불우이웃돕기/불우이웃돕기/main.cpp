#include <iostream>
using namespace std;
int tb[200][200],sum=0,check[101],n;
int main()
{
    int i,j,min,t,cnt=0;
    cin>>n;
    for(i=0;i<n;i++)for(j=0;j<n;j++)cin>>tb[i][j];
    check[0]=1;
    do
    {
        min=0x7fffffff;
        cnt++;
        if(cnt==n)break;
        for(i=0;i<n;i++)
        {
            if(check[i])
            {
                for(j=0;j<n;j++)
                {
                    if(!check[j]&&min>tb[i][j])
                    {
                        t=j;
                        min=tb[i][j];
                    }
                }
            }
        }
        check[t]=1;
        sum+=min;
    }while(1);
    cout<<sum;
}
