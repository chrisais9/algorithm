#include <iostream>
using namespace std;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int n,m,k;
int tb[110][110],ck[110][110];
void draw(int sx,int sy,int ex,int ey)
{
    int i,j;
    for(i=sx;i<ex;i++)
    {
        for(j=sy;j<ey;j++)
        {
            tb[i][j]=1;
        }
    }
}
void flood(int x,int y,int t)
{
    for(int i=0;i<4;i++)
    {
        if(x+dx[i]<0||x+dx[i]>=n||y+dy[i]<0||y+dy[i]>=m)continue;
        if(tb[x+dx[i]][y+dy[i]]==0&&ck[x+dy[i]][y+dy[i]]==0)
        {
            cout<<x<<y<<endl;
            ck[x+dx[i]][y+dy[i]]=t;
            flood(x+dx[i],y+dy[i],t);
        }
    }
}
int main()
{
    int i,j,cnt=0;
    int x1,y1,x2,y2;
    cin>>n>>m>>k;
    swap(n,m);
    for(i=0;i<k;i++)
    {
        cin>>x1>>y1>>x2>>y2;
        draw(x1,y1,x2,y2);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cout<<tb[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cout<<i<<" "<<j<<endl;
            if(tb[i][j]==0&&ck[i][j]==0)flood(i,j,++cnt);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cout<<ck[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
