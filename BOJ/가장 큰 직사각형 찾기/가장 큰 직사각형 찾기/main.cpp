#include <iostream>
#include <vector>
#define M 30
using namespace std;
typedef pair<int,int> ci;
vector<ci> v;
int ck[M][M],n,tb[M],mx=0;
int main()
{
    int i,j,k,a,b,c,d,s=0,e;
    cin>>n;
    for(k=0;k<n;k++)
    {
        cin>>a>>b>>c>>d;
        for(i=a+1;i<=c;i++)
        {
            for(j=b+1;j<=d;j++)
            {
                ck[i][j]=1;
            }
        }
    }
    for(i=0;i<M;i++)
    {
        for(j=1;j<M;j++)
        {
            if(ck[i][j]==1&&ck[i][j-1]==0)s=j;
            else if(ck[i][j]==0&&ck[i][j-1]==1)
            {
                e=j;
                if(tb[i]<e-s)tb[i]=e-s;
            }
        }
    }
    for(i=0;i<M;i++)cout<<tb[i]<<" ";
    for(i=0;i<M;i++)
    {
        int flag=0;
        for(j=i;j<M;j++)
        {
            if(tb[i]>tb[j])
            {
                flag=1;
                mx=max(mx,(j-i)*tb[i]);
                break;
            }
        }
        if(!flag)mx=max(mx,(j-i)*tb[i]);
    }
    cout<<mx;
}
