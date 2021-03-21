#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int tb[30010],a[30010],b[30010];
int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> tb[i];
    int acnt = 0, bcnt = 0;
    for (int i = 1; i <= N; i++)
    {
        if (tb[i - 1] != 1) a[i] = ++acnt;
        else a[i] = acnt;
        if (tb[N-i] != 2) b[N-i+1] = ++bcnt;
        else b[N-i+1] = bcnt;
    }
    int ans=987654321;
    for (int i = 0; i <= N; i++)ans=min(ans,a[i]+b[i+1]);
    cout << ans << endl;
}
