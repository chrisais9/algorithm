#include <iostream>
#include <algorithm>
using namespace std;
int n, l, a[1001];

int main() {
    cin>>n>>l;
    int i;
    for (i = 0; i < n; i++)cin>>a[i];
    sort(a, a + n);
    int tmp = a[0],cnt = 1;
    for (i = 0; i < n; i++)
        if (tmp + l - 1 < a[i])
        {
            tmp = a[i];
            cnt++;
        }
    cout<<cnt;
}
