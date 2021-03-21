#include <stdio.h>
#include <iostream>
using namespace std;

int ans = -1, ans_x = -1, ans_y = -1;
int n,m,t,k;
struct ABC
{
    int x, y;
}dia[101];
void func(int x, int y)
{
    int i;
    int cnt = 0;
    for (i = 0; i < t; ++i)
    {
        if (x <= dia[i].x && dia[i].x <= x + k && y <= dia[i].y && dia[i].y <= y + k) cnt++;
    }
    if (cnt > ans)
    {
        ans = cnt;
        ans_x = (x + y) / 2;
        ans_y = (y - x) / 2;
    }
}
int main()
{
    int x,y,a,b,i,j;
    cin>>n>>m>>t>>k;
    for (i = 0; i < t; ++i)
    {
        cin>>a>>b;
        dia[i].x = a - b;
        dia[i].y = a + b;
    }
    for (i = 0; i < t; ++i)
    {
        for (j = 0; j < t; ++j)
        {
            x = dia[i].x;
            y = dia[j].y;
            if ((x + y) & 1) func(x + 1, y), func(x - 1, y);
            else func(x, y);
        }
    }
    cout<<ans_x+k/2<<" "<<ans_y<<endl<<ans;
}
