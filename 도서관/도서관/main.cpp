#include <iostream>
#include <algorithm>
using namespace std;
int n, m, a[10000], res;
int main()
{
    cin>>n>>m;
    for (int i = 0; i < n; i++)cin>>a[i];
    sort(a, a + n);
    for (int i = 0; i < n; i += m)
    {
        cout<<(a[n - 1 - i]>0)*a[n - 1 - i]<<" "<<(a[i] < 0)*a[i]<<endl;
        res += (a[n - 1 - i]>0)*a[n - 1 - i] - (a[i] < 0)*a[i];
    }
    res = res * 2 - max(abs(a[0]), abs(a[n - 1]));
    cout<<res;
    return 0;
}
