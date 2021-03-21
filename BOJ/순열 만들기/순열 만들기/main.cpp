#include <iostream>
#include <algorithm>

using namespace std;
int a[10010];
int main() {
    int j,k, l, m, n;
    cin>>n>>m>>l;
    if (n > m * l || n + 1 < m + l)
    {
        cout<<-1;
        return 0;
    }
    for (int i = 0; i < n; i++) a[i] = i + 1;
    j=0;
    for (int i = 1; i <= m; i++)
    {
        k=min(j+l,n-m+i);
        reverse(a+j,a+k);
        j=k;
    }
    
    for (int i = 0; i < n; i++) cout<<a[i];
}
