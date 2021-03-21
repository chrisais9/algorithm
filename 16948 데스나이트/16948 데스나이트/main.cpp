#include <iostream>
#include <queue>
using namespace std;
typedef pair<int,int> ci;
int dx[6]={-2,-2,0,0,2,2},dy[6]={-1,1,-2,2,-1,1};
int ck[210][210],n;
int bfs(int sx,int sy,int ex,int ey)
{
    queue<ci> q;
    q.push(make_pair(sx,sy));
    while(!q.empty())
    {
        ci temp=q.front();
        q.pop();
        if(temp.first==ex&&temp.second==ey)return ck[temp.first][temp.second];
        for(int i=0;i<6;i++)
        {
            int tx=temp.first+dx[i];
            int ty=temp.second+dy[i];
            if(tx<0||ty<0||tx>=n||ty>=n||ck[tx][ty])continue;
            q.push(make_pair(tx,ty));
            ck[tx][ty]=ck[temp.first][temp.second]+1;
        }
    }
    return -1;
}
int main()
{
    int sx,sy,ex,ey;
    cin>>n>>sx>>sy>>ex>>ey;
    cout<<bfs(sx,sy,ex,ey);
}
