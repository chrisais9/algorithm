#include<iostream>
#include<algorithm>
#include<math.h>
#define INF 987654321
using namespace std;

int n,m,t,d,adj[26*26][26*26],map[26][26];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m>>t>>d;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            if(c>='A' && c<='Z') c = (int)(c-'A');
            else c = (int)(c-'a')+26;
            map[i][j]=c;
        }
    }
    for (int i = 0; i < 26 * 26; i++)
    {
        for (int j = 0; j < 26 * 26; j++)
        {
            if(i==j) adj[i][j]=0;
            else adj[i][j]=INF;
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                int ny = i+dx[k];
                int nx = j+dy[k];
                if(nx<0 || ny<0 || ny>=n || nx>=m) continue;
                if(abs(map[ny][nx]-map[i][j])>t) continue;
                int here = i*m+j;
                int there = ny*m+nx;
                if(map[i][j]>=map[ny][nx]) adj[here][there]=1;
                else adj[here][there]= (int)pow(map[ny][nx]-map[i][j],2);
            }
        }
    }
    
    for (int k = 0; k < n*m; k++)
    {
        for (int i = 0; i < n*m; i++)
        {
            for (int j = 0; j < n*m; j++)
            {
                adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
            }
            
        }
    }
    
    int ret=0;
    for (int i = 0; i < n*m; i++)
    {
        if (adj[0][i] + adj[i][0] <= d)
        {
            ret = max(ret,map[i/m][i%m]);
        }
    }
    cout<<ret;
    
    
}
