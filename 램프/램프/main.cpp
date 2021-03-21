#include <iostream>
#include <algorithm>
using namespace std;
int n;
double x[5000], y[5000], r;
double f(double t)
{
    double rt = 0;
    for (int i = 1; i < n; i++)rt = max(rt, (y[i] - y[i - 1]) / (x[i] - x[i - 1])*(t - x[i]) + y[i]);
    return rt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i = 0; i < n; i++) cin>>x[i]>>y[i];
    double low = x[0], up = x[n - 1], m1, m2;
    while (up - low>1e-9)
    {
        m1 = (low * 2 + up) / 3;
        m2 = (low + up * 2) / 3;
        f(m1) < f(m2) ? up = m2 : low = m1;
    }
    cout.setf(ios::fixed);
    cout.precision(2);
    cout<<f(m1);
}
