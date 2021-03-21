#include <iostream>
#include <queue>
#include <math.h>
using namespace std;
typedef pair<int,int> ci;
int tb[1010][1010];
int dx[9]={-1,-1,-1,0,1,1,1,0},dy[9]={-1,0,1,1,1,0,-1,-1};
int n,mx,my;
struct tt
{
    int t1;
    double dis=-1.0;
}ans[1010];
void draw(int x1,int y1,int x2,int y2,int num)
{
    for(int i=x1;i<=x2;i++)
    {
        for(int j=y1;j<=y2;j++)
        {
            tb[i][j]=num;
        }
    }
}
double get_dis(int ax,int ay,int bx,int by)
{
    return sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by));
}
void bfs(int x,int y)
{
    bool flag=0;
    int cn=tb[x][y];
    int ck[1010][1010]={0,};
    queue<ci> q;
    q.push(make_pair(x,y));
    while(!q.empty())
    {
        ci temp=q.front();
        q.pop();
        for(int i=0;i<8;i++)
        {
            if(temp.first+dx[i]<=0||temp.first+dx[i]>mx||temp.second+dy[i]<=0||temp.second+dy[i]>my)continue;
            if(tb[temp.first+dx[i]][temp.second+dy[i]]!=0&&tb[temp.first+dx[i]][temp.second+dy[i]]!=cn)
            {
                flag=1;
                double t=get_dis(x,y,temp.first+dx[i],temp.second+dy[i]);
                if(ans[cn].dis>t||ans[cn].dis==-1.0)
                {
                    ans[cn].dis=t;
                    ans[cn].t1=tb[temp.first+dx[i]][temp.second+dy[i]];
                }
            }
            if(!ck[temp.first+dx[i]][temp.second+dy[i]])
            {
                ck[temp.first+dx[i]][temp.second+dy[i]]=1;
                q.push(make_pair(temp.first+dx[i],temp.second+dy[i]));
            }
        }
        if(flag)return;
        
    }
}
int main()
{
    int i,j;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        if(mx<x1)mx=x1;
        if(mx<x2)mx=x2;
        if(my<y1)my=y1;
        if(my<y2)my=y2;
        draw(x1,y1,x2,y2,i);
    }
    
    for(i=1;i<=mx;i++)
    {
        for(j=1;j<=my;j++)
        {
            if(tb[i][j])bfs(i,j);
        }
    }
    for(i=1;i<=n;i++)
    {
        cout<<i<<" "<<ans[i].t1<<" ";
        printf("%.3lf\n",ans[i].dis);
    }
}
