#include <iostream>
#include <algorithm>
using namespace std;

int n, m, tb[101][101];
long long ans;

long long sum(int sx, int sy, int ex, int ey)
{
    long long ret = 0;
    for (int i = sy; i <= ey; i++)for (int j = sx; j <= ex; j++)ret += tb[i][j];
    return ret;
}

int main()
{
    int i,j;
    cin >> n >> m;
    for(i=0;i<n;i++)for(j=0;j<n;j++)
    {
        char tmp;
        cin >> tmp;
        tb[i][j] = tmp-'0';
    }
    for(i=0;i<m-2;i++)for(j=i+1;j<m-1;j++)
        ans=max(ans,sum(0, 0, i, n - 1)*sum(i+1, 0, j, n - 1)*sum(j+1, 0, m - 1, n-1));
    
    for(i=0;i<n-2;i++)for(j=i+1;j<n-1;j++)
        ans=max(ans,sum(0, 0, m-1, i)*sum(0, i+1, m-1, j)*sum(0, j+1, m - 1, n - 1));

    for(i=0;i<m-1;i++)for(j=0;j<n-1;j++)
        ans=max(ans,sum(0, 0, i, n-1)*sum(i+1,0,m-1,j)*sum(i+1,j+1,m-1,n-1));

    for(i=m-1;i>0;i--)for(j=0;j<n-1;j++)
        ans=max(ans,sum(i,0,m-1,n-1)*sum(0,0,i-1,j)*sum(0,j+1,i-1,n-1));

    for(i=0;i<n-1;i++)for(j=0;j<m-1;j++)
        ans=max(ans,sum(0,0,m-1,i)*sum(0,i+1,j,n-1)*sum(j+1,i+1,m-1,n-1));

    for(i=n-1;i>0;i--)for(j=0;j<m-1;j++)
        ans=max(ans,sum(0,i,m-1,n-1)*sum(0,0,j,i-1)*sum(j+1,0,m-1,i-1));
    cout<<ans;
}
