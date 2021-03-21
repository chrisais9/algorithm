#include <stdio.h>
#include <iostream>
using namespace std;
int n;
int a[10010],b[10010],D[10010][10],dir[10010][10],cnt[10010][10];

int func(int idx, int turn)
{
    if (idx == n) return 0;
    if (D[idx][turn] != -1) return D[idx][turn];
    int now = (a[idx] + turn) % 10;
    int cl = (b[idx] - now + 10) % 10;
    int l = cl + func(idx + 1, (turn + cl) % 10);
    int costright = (now - b[idx]  + 10) % 10;
    int r = costright + func(idx + 1, turn);
    
    if (l < r)
    {
        D[idx][turn] = l;
        dir[idx][turn] = 1;
        cnt[idx][turn] = cl;
    }
    else
    {
        D[idx][turn] = r;
        dir[idx][turn] = -1;
        cnt[idx][turn] = costright;
    }
    return D[idx][turn];
}

int main(void)
{
    int i;
    cin>>n;
    for (i = 0; i < n; i++)scanf("%1d", &a[i]);
    for (i = 0; i < n; i++)scanf("%1d", &b[i]);
    for (i = 0; i < n; i++)for (int j = 0; j < 10; j++) D[i][j] = -1;
    cout<<func(0,0)<<endl;
    int turn = 0;
    for (i = 0; i < n; i++)
    {
        int j = dir[i][turn] * cnt[i][turn];
        
        cout<<i+1<<" "<<j<<endl;
        if (dir[i][turn] == 1)
        {
            turn += cnt[i][turn];
            turn %= 10;
        }
    }
    return 0;
}

