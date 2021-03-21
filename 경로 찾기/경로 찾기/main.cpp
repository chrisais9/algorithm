#include <iostream>
using namespace std;
int tb[110][110],data[110][110],way[110][110];
int n;
void f(int x,int y)
{
    if(x==1&&y==1)return;
    if(way[x][y]==1)
    {
        cout<<"R ";
        f(x,y-1);
    }
    else
    {
        cout<<"D ";
        f(x-1,y);
    }
}
int main()
{
    int i,j;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cin>>data[i][j];
        }
    }
    for(i=0;i<=n;i++) tb[i][0]=tb[0][i]=-101;
    tb[0][1]=0;
    tb[1][0]=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(tb[i][j-1]>tb[i-1][j])
            {
                way[i][j]=1;
                tb[i][j]=tb[i][j-1]+data[i][j];
            }
            else
            {
                way[i][j]=2;
                tb[i][j]=tb[i-1][j]+data[i][j];
            }
        }
    }
    cout<<tb[n][n]<<endl;
    f(n,n);
}
