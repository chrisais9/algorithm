#include <iostream>
#include <queue>
using namespace std;
typedef pair<int,int> ci;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
char tb[60][60];
int n,m;
int bfs(int x,int y)
{
    int mx=0,ck[60][60]={0,};
    ci temp;
    queue<ci> q;
    q.push(make_pair(x,y));
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        int tx=temp.first,ty=temp.second;
        for(int i=0;i<4;i++)
        {
            if(tx+dx[i]<0||tx+dx[i]>=n||ty+dy[i]<0||ty+dy[i]>=m)continue;
            if(tb[tx+dx[i]][ty+dy[i]]=='L'&&(ck[tx+dx[i]][ty+dy[i]]==0||ck[tx+dx[i]][ty+dy[i]]>ck[tx][ty]+1))
            {
                ck[tx+dx[i]][ty+dy[i]]=ck[tx][ty]+1;
                q.push(make_pair(tx+dx[i],ty+dy[i]));
                if(mx<ck[tx][ty]+1)mx=ck[tx][ty]+1;
            }
        }
    }
    return mx;
}
int main()
{
    int i,j,ans=0;
    cin>>n>>m;
    for(i=0;i<n;i++)cin>>tb[i];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(tb[i][j]=='L')
            {
                int t=bfs(i,j);
                if(ans<t)ans=t;;
            }
        }
    }
    cout<<ans;
    
}
