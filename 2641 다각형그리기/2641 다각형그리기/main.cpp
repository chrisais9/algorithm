#include <iostream>
#include <string.h>
using namespace std;
int n,m;
int tb[100],dt[100][100],ck[100],temp[100];
int f()
{
    int flag=1,t;
    for(int i=0;i<n;i++)if(tb[i]!=temp[i])flag=0;
    if(flag)return flag;
    flag=1;
    for(int i=0;i<n;i++)
    {
        if(temp[i]==1)t=3;
        else if(temp[i]==3)t=1;
        else if(temp[i]==2)t=4;
        else if(temp[i]==4)t=2;
        if(tb[n-i-1]!=t)flag=0;
    }
    return flag;
}
int main()
{
    int i,j,k,t,cnt=0;
    cin>>n;
    for(i=0;i<n;i++)cin>>tb[i];
    cin>>m;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)cin>>dt[i][j];
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)temp[j]=dt[i][j];
        for(j=0;j<n;j++)
        {
            t=temp[0];
            for(k=0;k<n-1;k++)temp[k]=temp[k+1];
            temp[n-1]=t;
            if(f())
            {
                cnt++;
                ck[i]=1;
                break;
            }
        }
    }
    cout<<cnt<<endl;
    for(i=0;i<m;i++)
    {
        if(ck[i]==1)
        {
            for(j=0;j<n;j++)cout<<dt[i][j]<<" ";
            cout<<endl;
        }
    }
}
