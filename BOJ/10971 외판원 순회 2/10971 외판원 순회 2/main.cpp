#include <iostream>
#include <algorithm>
using namespace std;
 
int n, tb[16][16], mask[16][1 << 16];
int tsp(int x, int visited) {
    if (visited == (1 << n) - 1) {
        if (tb[x][0] == 0)
            return 999999999;
        else
            return tb[x][0];
    }
 
    if (mask[x][visited])
        return mask[x][visited];
 
    int m = 0x7fffffff - 99999999;
    for (int i=0;i<n;i++) {
        if (visited & (1<<i)) continue;
        if (!tb[x][i]) continue;
        m = min(m, tsp(i, (visited | (1 << i))) + tb[x][i]);
    }
 
    mask[x][visited] = m;
    return mask[x][visited];
}
int main() {
    cin>>n;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            cin>>tb[i][j];
    cout<<tsp(0, 1);
}
