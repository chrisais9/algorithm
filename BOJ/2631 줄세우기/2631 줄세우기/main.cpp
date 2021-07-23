#include<iostream>
using namespace std;

int n, d[201], tb[201];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i=0; i<n; i++) cin>>d[i];
    int mx = 0;
    for (int i=0;i<n;i++) {
        tb[i] = 1;
        for (int j=0;j<n;j++) {
            if (d[j] < d[i] && tb[i] < tb[j]+1) {
                tb[i] = tb[j] + 1;
            }
        }
        if (mx < tb[i]) mx = tb[i];
    }
    cout << n - mx << endl;
}
