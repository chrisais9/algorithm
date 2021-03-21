#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int n, x[101] = { -1 }, y[101] = { -1 }, szx = 1, szy = 1, s[101][101], r = 1e9;
pair<int, int> p[100];
int main()
{
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>p[i].first>>p[i].second;
        x[szx++] = p[i].first;
        y[szy++] = p[i].second;
    }
    
    sort(x, x + szx);
    sort(y, y + szy);
    szx = unique(x, x + szx) - x;
    szy = unique(y, y + szy) - y;

    for (int i = 0; i < n; i++)
    {
        int tx = lower_bound(x, x + szx, p[i].first) - x,
        ty = lower_bound(y, y + szy, p[i].second) - y;
        s[tx][ty]++;
    }
    
    for (int i = 1; i < szx; i++)
    {
        for (int j = 1; j < szy; j++) s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
    }

    for (int i = 1; i < szx; i++)
    {
        for (int j = 1; j < szy; j++)
        {
            int k = 0, l = j;
            while (l >= 0)
            {
                if (s[i][j] - s[k][j] - s[i][l] + s[k][l] < n / 2) l--;
                else
                {
                    r = min(r, (x[i] - x[k + 1] + 2)*(y[j] - y[l + 1] + 2));
                    k++;
                }
            }
        }
    }
    cout<<r;
}
