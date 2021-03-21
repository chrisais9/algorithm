#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
int n,m,dx[4]={-1,0,1,0},dy[4]={0,1,0,-1},tb[1010][1010],ck[2][1010][1010];
struct wall
{
    int x,y,key;
};
int bfs(int sx,int sy)
{
    queue<wall> q;
    q.push({sx,sy,1});
    while(!q.empty())
    {
        wall temp=q.front();
        q.pop();
        if(temp.x==n&&temp.y==m)return ck[temp.key][n][m];
        for(int i=0;i<4;i++)
        {
            int tx=temp.x+dx[i],ty=temp.y+dy[i];
            if(tx<=0||tx>n||ty<=0||ty>m)continue;
            if(tb[tx][ty]==1&&temp.key)//벽이 있고 키가 있으면
            {
                ck[0][tx][ty]=ck[1][temp.x][temp.y]+1;
                q.push({tx,ty,0});
            }
            if(!tb[tx][ty]&&!ck[temp.key][tx][ty])
            {
                ck[temp.key][tx][ty]=ck[temp.key][temp.x][temp.y]+1;
                q.push({tx,ty,temp.key});
            }
        }
    }
    return -1;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        string parse;
        cin>>parse;
        for(int j=1;j<=m;j++)tb[i][j]=parse[j-1]-'0';
    }
    ck[1][1][1]=1;
    cout<<bfs(1,1);
}
