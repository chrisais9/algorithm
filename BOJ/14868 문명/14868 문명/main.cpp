#include <iostream>
#include <queue>
using namespace std;
int n,k;
typedef pair<int,int> ci;
queue<ci> civil;
queue<int> day;
int ck[2010][2010],tb[100001],rnk[100001];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int fd(int q)
{
    if (tb[q] == q)
        return q;
    
    return tb[q] = fd(tb[q]);
}
void mg(int a, int b)
{
    a = fd(a);
    b = fd(b);
    
    if (rnk[a] > rnk[b])swap(a, b);
    tb[a] = b;
    if (rnk[a] == rnk[b])rnk[b]++;
}

int main()
{
    int civil_n=1,ans=0;
    cin>>n>>k;
    for(int i=0;i<k;i++)
    {
        int x,y;
        cin>>x>>y;
        day.push(0);
        civil.push(make_pair(x,y));
        tb[i]=ck[x][y]=civil_n++;
        for(int j=0;j<4;j++)
        {
            int mx=x+dx[i],my=y+dy[i];
            if(mx>=n||mx<0||my>=n||my<0)continue;
            if(fd(ck[mx][my])!=ck[x][y])
            {
                mg(ck[mx][my],ck[x][y]);
                civil_n--;
            }
        }
    }
    while(civil_n>1)
    {
        ci now;
        now=civil.front();
        int nday=day.front();
        civil.pop();
        day.pop();
        if(ans<nday)ans=nday;
        for(int i=0;i<4;i++)
        {
            int mx=now.first+dx[i],my=now.second+dy[i];
            if(mx>n||mx<=0||my>n||my<=0)continue;
            if(ck[mx][my])
            {
                if(fd(ck[mx][my])!=ck[now.first][now.second])
                {
                    mg(ck[mx][my],ck[now.first][now.second]);
                    civil_n--;
                }
            }
            else ck[mx][my]=ck[now.first][now.second];
            if(civil_n==1)ans=nday+1;
            civil.push(make_pair(mx,my));
            day.push(nday+1);
        }
    }
    cout<<ans;
}
