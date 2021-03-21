#include <iostream>
using namespace std;
int a[10][10];
int tb[10][10];
bool c[10][10];
bool c2[10][10];
bool c3[10][10];
const int n=9;
int cnt=0;
int square(int x, int y)
{
    return (x/3)*3+(y/3);
}
bool go(int z)
{
    cnt++;
    if (cnt >= 100000) return true;
    if (z == 81)return true;
    int x = z/n;
    int y = z%n;
    if (a[x][y] != 0)return go(z+1);
    else
    {
        for (int i=1; i<=9; i++)
        {
            if (c[x][i] == 0 && c2[y][i] == 0 && c3[square(x,y)][i]==0)
            {
                c[x][i] = c2[y][i] = c3[square(x,y)][i] = true;
                a[x][y] = i;
                if (go(z+1))return true;
                a[x][y] = 0;
                c[x][i] = c2[y][i] = c3[square(x,y)][i] = false;
            }
        }
    }
    return false;
}
int main()
{
    for(int k=0;k<81;k++)
    {
        cnt=0;
        memset(c,sizeof(c),0);
        memset(c2,sizeof(c2),0);
        memset(c3,sizeof(c3),0);
        memset(a,sizeof(a),0);
        int x,y,t;
        cin>>x>>y>>t;
        tb[x-1][y-1]=t;
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
            {
                a[i][j]=tb[i][j];
                if (a[i][j] != 0)
                {
                    c[i][a[i][j]] = c2[j][a[i][j]] = c3[square(i,j)][a[i][j]] = true;
                }
            }
        }
        if(!go(0))cout<<k+1<<endl;
        else cout<<"okay"<<endl;
    }
    cout<<-1<<endl;
}
