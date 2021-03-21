#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
char tb[1002][1002];
int ck[1002][1002][12];
int n,m,k;
int dx[4] = {0,1,0,-1},dy[4] = {-1,0,1,0};
struct wall
{
    int x,y,day,key;
};
int bfs()
{
    queue<wall>q;
    q.push({0,0,0,0});
    ck[0][0][0]=0;
    while (!q.empty())
    {
        wall temp=q.front();
        q.pop();
        if (temp.x==n-1&&temp.y==m-1)return temp.day+1;
        for (int i=0;i<4;i++)
        {
            int tx=temp.x+dx[i],ty=temp.y+dy[i];
            if (tx<0||tx>=n||ty<0||ty>=m)continue;
            if (tb[tx][ty]=='0')
            {
                if (temp.day+1<ck[tx][ty][temp.key])
                {
                    ck[tx][ty][temp.key]=temp.day+1;
                    q.push({tx,ty,temp.day+1,temp.key});
                }
            }
            else
            {
                if (temp.key<k)
                {
                    if(temp.day%2==0)
                    {
                        if (temp.day+1<ck[tx][ty][temp.key+1])
                        {
                            q.push({tx,ty,temp.day+1,temp.key+1});
                            ck[tx][ty][temp.key+1]=temp.day+1;
                        }
                    }
                    else q.push({temp.x,temp.y,temp.day+1,temp.key});
                }
            }
        }
    }
    return -1;
}
int main()
{
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>tb[i][j];
            for(int a=0;a<11;a++)ck[i][j][a]=987654321;
        }
    }
    cout<<bfs();
}
