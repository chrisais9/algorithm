#include <iostream>
#include <vector>
#define MAX 1000000000
using namespace std;
typedef pair<int,int> ci;
typedef pair<pair<int, int>, pair<int, int>> cci;
vector< vector<ci> > fig;
int n,rx,ry;
int ccw(ci a,ci b,ci c)
{
    int ck=a.first*b.second+b.first*c.second+c.first*a.second;
    ck-=(a.second*b.first + b.second*c.first + c.second*a.first);
    if(ck>0)return 1;
    else if(ck==0)return 0;
    else return -1;
}
int isIntersect(cci x,cci y)
{
    ci a = x.first;
    ci b = x.second;
    ci c = y.first;
    ci d = y.second;
    int ab = ccw(a, b, c)*ccw(a, b, d);
    int cd = ccw(c, d, a)*ccw(c, d, b);
    if (ab == 0 && cd == 0)
    {
        if (a > b)swap(a, b);
        if (c > d)swap(c, d);
        return c <= b&&a <= d;
    }
    return ab <= 0 && cd <= 0;
}
int main()
{
    int i,j,mx=0,my=0;
    cin>>n>>rx>>ry;
    rx*=-1;
    ry*=-1;
    fig.resize(n+1);
    for(i=0;i<n;i++)
    {
        int m;
        cin>>m;
        for(j=0;j<m;j++)
        {
            int x,y;
            cin>>x>>y;
            if(rx>0&&ry>0&&mx<x&&my<y)
            {
                mx=x;
                my=y;
            }
            if(rx<0&&ry>0&&mx>x&&my<y)
            {
                mx=x;
                my=y;
            }
            if(rx<0&&ry<0&&mx>x&&my>y)
            {
                mx=x;
                my=y;
            }
            if(rx>0&&ry<0&&mx<x&&my>y)
            {
                mx=x;
                my=y;
            }
            fig[i].push_back(make_pair(x,y));
        }
    }
    cci line;
    int tx=rx,ty=ry;
    for(i=1;;i++)
    {
        tx=rx*i;
        ty=ry*i;
        if(tx>mx&&ty>my)break;
    }
    line.first.first=0;
    line.first.second=0;
    line.second.first=tx;
    line.second.second=ty;
    int ans=0;
    for(i=0;i<n;i++)
    {
        for(j=1;j<fig[i].size();j++)
        {
            cci temp;
            temp.first.first=fig[i][j-1].first;
            temp.first.second=fig[i][j-1].second;
            temp.second.first=fig[i][j].first;
            temp.second.second=fig[i][j].second;
            if(isIntersect(line,temp))
            {
                ans++;
                break;
            }
        }
    }
    cout<<ans;
}
