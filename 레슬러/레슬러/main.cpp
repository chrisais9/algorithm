#include <iostream>
#include <algorithm>
#define MN 10001
using namespace std;

struct data {
    int a, b, id;
}d[MN];
bool cmp(data &a, data &b)
{
    return a.a+b.a*a.b > b.a+a.a*b.b;
}
int n;
int main()
{
    int i;
    cin>>n;
    for (i = 1; i <= n; i++)
    {
        cin>>d[i].a>>d[i].b;
        d[i].id = i;
    }
    std::sort(d+1, d+n+1, cmp);
    for (i = 1; i <= n; i++)cout<<d[i].id;
}
