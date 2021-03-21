#include <iostream>
using namespace std;
int n, m, k;
int map[16][16];
int tb[16][16];
int main()
{
    cin>>n>>m>>k;
    tb[1][1] = 1;
    int cnt = 0;
    int mx, my;
    if (k == 0)
    {
        mx = 1;
        my = 1;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cnt++;
                if (cnt == k)
                {
                    mx = i;
                    my = j;
                    break;
                }
            }
        }
    }
    for (int i = 1; i <= mx; i++)for (int j = 1; j <= my; j++)tb[i][j] += tb[i - 1][j] + tb[i][j - 1];
    int tmp = tb[mx][my];
    tb[mx][my] = 1;
    for (int i = mx; i <= n; i++)
    {
        for (int j = my; j <= m; j++)
        {
            if (i == mx && j == my)continue;
            tb[i][j] += tb[i - 1][j] + tb[i][j - 1];
        }
    }
    cout<<tmp*tb[n][m];
}
