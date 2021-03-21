#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <ctype.h>
#include <memory.h>
using namespace std;
string a;
int n, b[3000], visited[3000], s, e, r;
vector<int> vt[3000];
int valid(char a, char b)
{
    int x,y;
    if(isupper(a))
    {
        x=a-'A';
        y=b-'a';
        return x*26+y+1;
    }
    else
    {
        x=a-'a';
        y=b-'A';
        return x*26+y+26*26+1;
    }
}
int dfs(int here)
{
    if (visited[here])return 0;
    visited[here] = 1;
    for (auto next : vt[here])
    {
        if (!b[next] || dfs(b[next]))
        {
            b[next] = here;
            return 1;
        }
    }
    return 0;
}
int bmatch()
{
    int ret = 0;
    for (int i = 1; i <= 26 * 26; i++)
    {
        memset(visited, 0, sizeof(visited));
        if (dfs(i))ret++;
    }
    return ret;
}
int main()
{
    int i,x,y;
    cin>>a;
    n=a.size();
    s=valid(a[0],a[1]);
    e=valid(a[n-2],a[n-1]);
    if(s==e)r=1;
    else r=2;
    for(i=1;i<n-1;i++)
    {
        x=valid(a[i-1],a[i]);
        y=valid(a[i],a[i+1]);
        if(s!=x&&s!=y&&e!=x&&e!=y)
        {
            vt[x].push_back(y);
            vt[y].push_back(x);
        }
    }
    r+=bmatch();
    cout<<r;
    return 0;
}
