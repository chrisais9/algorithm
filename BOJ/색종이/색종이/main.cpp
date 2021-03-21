#include <iostream>
using namespace std;
int tb[200][200],n,ans;
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
int f(int x,int y)
{
    int i,cnt=0;
    for(i=0;i<4;i++)
    {
        if(tb[x+dx[i]][y+dy[i]]==1)cnt++;
    }
    return cnt;
}
int main()
{
    int i,j,k,a,b;
    cin>>n;
    for(k=0;k<n;k++)
    {
        cin>>a>>b;
        for(i=a+1;i<=a+10;i++)
        {
            for(j=b+1;j<=b+10;j++)
            {
                tb[i][j]=1;
            }
        }
    }
    
    for(i=0;i<=26;i++)
    {
        for(j=0;j<=26;j++)
        {
            if(tb[i][j]!=1)
            {
                cout<<f(i,j)<<" ";
                ans+=f(i,j);
            }
            else cout<<"0 ";
        }
        cout<<endl;
    }
    cout<<ans;
        
}
