#include <iostream>
using namespace std;

int n, m, row[11], col[11], checkrow[11][11], checkcol[11][11], res[11][11];

bool dfs(int x, int y)
{
    int i,p,q,r,s;
    if(x==n+1) return true;
    if(x==4 && y==9) x=x;
    for(i=0; i<m; i++)
    {
        if((checkrow[x][i]==1 && row[x]>n-y) || (checkcol[y][i]==1 && col[y]>n-x)) continue;
        p=checkrow[x][i];
        q=row[x];
        r=checkcol[y][i];
        s=col[y];
        res[x][y]=i;
        if(checkrow[x][i]==0)
        {
            checkrow[x][i]=1;
            row[x]--;
        }
        if(checkcol[y][i]==0)
        {
            checkcol[y][i]=1;
            col[y]--;
        }
        bool val=false;
        if(y<n) val=dfs(x, y+1);
        else val=dfs(x+1, n-m+2);
        if(val) return true;
        checkrow[x][i]=p;
        row[x]=q;
        checkcol[y][i]=r;
        col[y]=s;
    }
    return false;
}

int main()
{
    int i, j, k;
    
    cin>>n>>k;
    
    for(i=1; i<=n-m+1; i++)
    {
        for(j=1; j<=n-m+1; j++)
        {
            res[i][j]=0;
            checkrow[i][0]=checkcol[j][0]=1;
        }
        for(j=n-m+2; j<=n; j++)
        {
            res[i][j]=res[j][i]=j-(n-m+1);
            checkrow[i][j-(n-m+1)]=checkcol[j][j-(n-m+1)]=checkrow[j][j-(n-m+1)]=checkcol[i][j-(n-m+1)]=1;
        }
    }
    for(i=1; i<=n; i++) row[i]=col[i]=m;
    for(i=1; i<=n; i++) for(j=0; j<m; j++) if(checkrow[i][j]) row[i]--;
    for(i=1; i<=n; i++) for(j=0; j<m; j++) if(checkcol[i][j]) col[i]--;
    dfs(n-m+2, n-m+2);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++) cout<<res[i][j];
        cout<<endl;
    }
}

