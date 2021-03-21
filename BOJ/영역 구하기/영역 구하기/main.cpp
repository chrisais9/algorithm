#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> ans;
int tb[101][101];
int ck[101][101];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int n,m,k;
int t;
void draw(int sx,int sy,int ex,int ey)
{
    for(int i=sx;i<ex;i++)for(int j=sy;j<ey;j++)tb[i][j]=1;
}
void flood(int x,int y)
{
    for(int i=0;i<4;i++)
    {
        if(x+dx[i]<0||x+dx[i]>=n||y+dy[i]<0||y+dy[i]>=m)continue;
        if(!ck[x+dx[i]][y+dy[i]]&&!tb[x+dx[i]][y+dy[i]])
        {
            ck[x+dx[i]][y+dy[i]]=1;
            t++;
            flood(x+dx[i],y+dy[i]);
        }
    }
}
int main()
{
    int i,j;
    cin>>m>>n>>k;
    for(i=0;i<k;i++)
    {
        int sx,sy,ex,ey;
        cin>>sx>>sy>>ex>>ey;
        draw(sx,sy,ex,ey);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(!tb[i][j]&&!ck[i][j])
            {
                t=1;
                ck[i][j]=1;
                flood(i,j);
                ans.push_back(t);
            }
        }
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(i=0;i<ans.size();i++)cout<<ans[i]<<" ";
    
}
