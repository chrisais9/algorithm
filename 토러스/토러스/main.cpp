#include <iostream>
#include <vector>
using namespace std;
int n,m;
int tb[110][110];
bool is_arr()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(tb[i][j]!=(i-1)*n+j)return false;
        }
    }
    return true;
}
void rotate_right(int x)
{
    int temp=tb[x][m];
    for(int i=m;i>=1;i--)
    {
        tb[x][i]=tb[x][i-1];
    }
    tb[x][0]=temp;
}
void rotate_left(int x)
{
    
}
int main()
{
    
}
