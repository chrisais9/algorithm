#include <iostream>]
using namespace std;
int tb[1000][1000],ck[1000],flag,n;
void f(int x)
{
    if(ck[x])flag=1;
    if(flag)return;
    ck[x]=1;
    for(int i=0;i<n;i++)
    {
        if(tb[x][i]==1&&tb[i][x]==0)
        {
            tb[x][i]=0;
            f(i);
        }
    }
    ck[x]=0;
}
int main()
{
    int i,j;
    char t;
    cin>>n;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>t;
            if(t=='N')tb[i][j]=0;
            else tb[i][j]=1;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(tb[i][j]==1&&tb[j][i]==0)
            {
                f(i);
                tb[i][j]=0;
            }
            if(flag)
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    cout<<"YES"<<endl;
}
