#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
int n,m,k,dx[4]={-1,0,1,0},dy[4]={0,1,0,-1},tb[1010][1010],ck[11][1010][1010];
struct wall
{
    int x,y,key;
};
int bfs(int sx,int sy)
{
    queue<wall> q;
    q.push({sx,sy,k});
    while(!q.empty())
    {
        wall temp=q.front();
        q.pop();
        if(temp.x==n&&temp.y==m)return ck[temp.key][n][m];
        for(int i=0;i<4;i++)
        {
            int tx=temp.x+dx[i],ty=temp.y+dy[i];
            if(tx<=0||tx>n||ty<=0||ty>m)continue;
            if(ck[temp.key][tx][ty])continue;
            if(tb[tx][ty]&&temp.key)
            {
                ck[temp.key-1][tx][ty]=ck[temp.key][temp.x][temp.y]+1;
                q.push({tx,ty,temp.key-1});
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
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        string parse;
        cin>>parse;
        for(int j=1;j<=m;j++)tb[i][j]=parse[j-1]-'0';
    }
    ck[k][1][1]=1;
    cout<<bfs(1,1);
}
