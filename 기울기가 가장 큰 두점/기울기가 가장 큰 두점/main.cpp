#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
struct data
{
    int x, y, idx;
    bool operator ()(data a,data b)
    {
        if(a.x==b.x)return a.idx<b.idx;
        return a.x<b.x;
    }
} p[50005];
int n;
double sol = -0.1;
int res1, res2, m1, m2;
int main()
{
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        cin>>p[i].x>>p[i].y;
        p[i].idx = i;
    }
    sort(p+1, p+n+1, data());
    for (int i = 1; i < n; i++)
    {
        if (p[i].idx < p[i+1].idx)
        {
            m1 = p[i].idx;
            m2 = p[i+1].idx;
        }
        else
        {
            m1 = p[i+1].idx;
            m2 = p[i].idx;
        }
        if (p[i].x == p[i+1].x)
        {
            if (sol < -0.5)
            {
                if (m1 < res1 || (m1 == res1 && m2 < res2))
                {
                    res1 = m1;
                    res2 = m2;
                }
            }
            else
            {
                sol = -1;
                res1 = m1;
                res2 = m2;
            }
        }
        else
        {
            if (sol < -0.5) continue;
            if (sol+1e-7 < abs((double)(p[i+1].y-p[i].y)/(double)(p[i+1].x-p[i].x)))
            {
                sol = abs((double)(p[i+1].y-p[i].y)/(double)(p[i+1].x-p[i].x));
                res1 = m1;
                res2 = m2;
            }
            else if (abs((double)(p[i+1].y-p[i].y)/(double)(p[i+1].x-p[i].x) - sol) < 1e-7)
            {
                if (m1 < res1 || (m1 == res1 && m2 < res2))
                {
                    res1 = m1;
                    res2 = m2;
                }
            }
        }
    }
    cout<<res1<<" "<<res2<<endl;
}
