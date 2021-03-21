#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;
int tb[101][101];
int main()
{
    int n, m;
    cin>>n>>m;
    
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) i == j ? tb[i][j] = 0 : tb[i][j] = INF;
    for (int i = 0; i < m; i++)
    {
        int x, y, c;
        cin>>x>>y>>c;
        tb[x][y] = min(tb[x][y], c);
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if (tb[i][j] > tb[i][k] + tb[k][j])
                    tb[i][j] = tb[i][k] + tb[k][j];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)cout<<(tb[i][j]==INF?0:tb[i][j])<<" ";
        cout<<endl;
    }
}
