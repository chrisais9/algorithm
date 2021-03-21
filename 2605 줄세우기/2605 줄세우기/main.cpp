#include <iostream>
using namespace std;
int n;
int tb[110];
int main()
{
    int i,j,now=0,x,cnt=1;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x;
        if(x>0)for(j=now;j>now-x;j--)tb[j]=tb[j-1];
        tb[now-x]=cnt++;
        now++;
    }
    for(j=0;j<n;j++)cout<<tb[j]<<" ";
}
