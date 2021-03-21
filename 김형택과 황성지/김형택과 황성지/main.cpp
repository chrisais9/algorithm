#include <cstdio>

#define source 0
#define sink 2*c+1

int n, m, num[51][51], con[6000][6000], dx[5]={0, -1, 0, 1, 0}, dy[5]={0, 0, 1, 0, -1};
int visit[6000], via[6000], queue[6000][2], head, tail;
char input[51][51];

bool Valid(int x, int y)
{
    return (1<=x && x<=n && 1<=y && y<=m);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int i, j, k;
    
    scanf("%d %d", &n, &m);
    
    int c=0;
    for(i=1; i<=n; i++)
    {
        scanf("\n%s", &input[i][1]);
        for(j=1; j<=m; j++) if(input[i][j]!='#') num[i][j]=++c;
    }
    
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
        if(input[i][j]=='K')
            for(k=1; k<=4; k++)
            if(Valid(i+dx[k], j+dy[k]) && input[i+dx[k]][j+dy[k]]=='H')
            {
                printf("-1");
                return 0;
            }
    
    for(i=1; i<=n; i++) for(j=1; j<=m; j++)
    {
        if(input[i][j]=='#') continue;
        con[num[i][j]][num[i][j]+c]=1;
        if(input[i][j]=='K' || input[i][j]=='H') con[num[i][j]][num[i][j]+c]=600000;
        for(k=1; k<=4; k++)
            if(Valid(i+dx[k], j+dy[k]) && input[i+dx[k]][j+dy[k]]!='#')
                con[num[i][j]+c][num[i+dx[k]][j+dy[k]]]=600000;
        
        if(input[i][j]=='K') con[source][num[i][j]]=600000;
        else if(input[i][j]=='H') con[num[i][j]+c][sink]=600000;
    }
    
    int res=0, d = 0;
    while(1)
    {
        int sw=0;
        for(i=source; i<=sink; i++)
        {
            visit[i]=0;
            via[i]=-1;
        }
        
        head=tail=1;
        queue[1][0]=source;
        queue[1][1]=600000;
        visit[source]=1;
        while(head<=tail)
        {
            int r=queue[head][0], val=queue[head][1]; head++;
            
            if(r==sink)
            {
                res+=val;
                d=val;
                sw=1;
                break;
            }
            
            for(i=source; i<=sink; i++) if(visit[i]==0 && con[r][i])
            {
                visit[i]=1;
                via[i]=r;
                
                int d=val;
                if(d>con[r][i]) d=con[r][i];
                
                queue[++tail][0]=i;
                queue[tail][1]=d;
            }
        }
        
        if(sw==0) break;
        else
        {
            for(i=sink; via[i]!=-1; i=via[i])
            {
                con[via[i]][i]-=d;
                con[i][via[i]]+=d;
            }
        }
    }
    
    printf("%d", res);
    
    return 0;
}

