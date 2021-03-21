#include <iostream>
#include <queue>
#include <math.h>
#include <algorithm>
using namespace std;
int dx[5]={99,0,1,0,-1},dy[5]={99,1,0,-1,0};
int n,m,sx,sy,sd,ex,ey,ed;
int tb[110][110],ck[110][110];
struct dt {
    int x,y,dir;
};
void f(int x,int y,int dir)
{
    queue<dt> q;
    dt temp;
    temp.x=x;
    temp.y=y;
    temp.dir=dir;
    q.push(temp);
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        for(int i=1;i<=4;i++)
        {
            for(int j=1;j<=3;j++)
            {
                if(temp.x+dx[i]*j<=0||temp.x+dx[i]*j>n||temp.y+dy[i]*j<=0||temp.y+dy[i]*j>m)break;
                if(tb[temp.x+dx[i]*j][temp.y+dy[i]*j])break;
                int t=min(abs(i-temp.dir),4-abs(i-temp.dir));
                if(ck[temp.x+dx[i]*j][temp.y+dy[i]*j]==0||
                   ck[temp.x+dx[i]*j][temp.y+dy[i]*j]>ck[temp.x][temp.y]+t+1)
                {
                    ck[temp.x+dx[i]*j][temp.y+dy[i]*j]=ck[temp.x][temp.y]+t+1;
                    dt inp;
                    inp.x=temp.x+dx[i]*j;
                    inp.y=temp.y+dy[i]*j;
                    inp.dir=i;
                    if(inp.x==ex&&inp.y==ey)
                    {
                        cout<<ck[inp.x][inp.y]<<endl;
                        return;
                    }
                    q.push(inp);
                }
            }
        }
    }
    
}
int main()
{
    int i,j;
    cin>>n>>m;
    for(i=1;i<=n;i++)for(j=1;j<=m;j++)cin>>tb[i][j];
    cin>>sx>>sy>>sd;
    cin>>ex>>ey>>ed;
    if(sd==2)sd=3;
    else if(sd==3)sd=2;
    if(ed==2)ed=3;
    else if(ed==3)ed=2;
    f(sx,sy,sd);
}

