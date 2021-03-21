#include <iostream>
using namespace std;
int tb[31][31],ck[31][31],n,m;
int dx[8]={-2,-2,-1,1,2,2,1,-2},dy[8]={-1,1,2,2,1,-1,-2,-2};
int sx,sy,ex,ey,a_cnt,a_min=999999;
void f(int x,int y,int d)
{
    cout<<x<<" "<<y<<" "<<d<<endl;
    if(d>a_min)return;
    for(int i=0;i<8;i++)
    {
        int mx=x+dx[i],my=y+dy[i];
        if(mx==ex&&my==ey)
        {
            if(a_min>d)
            {
                a_cnt=1;
                a_min=d;
            }
            else if(a_min==d)a_cnt++;
            return;
        }
        if(mx<0||mx>=n||my<0||my>=m)continue;
        if(ck[mx][my]==0)
        {
            if(tb[mx][my]==0)
            {
                ck[mx][my]=1;
                f(mx,my,d+1);
                ck[mx][my]=0;
            }
            if(tb[mx][my]==1)
            {
                ck[mx][my]=1;
                f(mx,my,d);
                ck[mx][my]=0;
            }
        }
    }
}
int main()
{
    int i,j;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>tb[i][j];
            if(tb[i][j]==3)
            {
                sx=i;
                sy=j;
            }
            else if(tb[i][j]==4)
            {
                ex=i;
                ey=j;
            }
        }
    }
    f(sx,sy,0);
    cout<<a_min<<endl<<a_cnt;
}
