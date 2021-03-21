#include <iostream>
using namespace std;

char input[51][51];
int n, m, dx[5]={0, -1, 0, 1, 0}, dy[5]={0, 0, 1, 0, -1}, visit[51][51];

bool valid(int x, int y)
{
    if(1<=x && x<=n && 1<=y && y<=m && visit[x][y]==0 && input[x][y]=='#') return true;
    return false;
}

void back(int x, int y, int k)
{
    int i;
    
    visit[x][y]=k;
    for(i=1; i<=4; i++) if(valid(x+dx[i], y+dy[i])) back(x+dx[i], y+dy[i], k);
}

bool fiximage()
{
    int i, j, k=0;
    bool r=false;
    
    for(i=1; i<=n; i++) for(j=1; j<=m; j++) visit[i][j]=0;
    for(i=1; i<=n; i++) for(j=1; j<=m; j++) if(input[i][j]=='#' && visit[i][j]==0) back(i, j, ++k);
    
    for(i=1; i<=n; i++)
    {
        int p=0, q=0;
        for(j=1; j<=m; j++) if(input[i][j]=='#')
        {
            if(visit[i][j]==p && q+1!=j) for(k=q+1; k<=j; k++) input[i][k]='#', visit[i][k]=p, r=true;
            p=visit[i][j], q=j;
        }
    }
    
    for(i=1; i<=m; i++)
    {
        int p=0, q=0;
        for(j=1; j<=n; j++) if(input[j][i]=='#')
        {
            if(visit[j][i]==p && q+1!=j) for(k=q+1; k<=j; k++) input[k][i]='#', visit[k][i]=p, r=true;
            p=visit[j][i], q=j;
        }
    }
    
    return r;
}

int main()
{
    int i;
    cin>>n>>m;
    for(i=0;i<=n;i++)cin>>input[i][1];
    while(fiximage());
    for(i=1;i<=n;i++)cout<<input[i][1];
}
