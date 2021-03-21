#include <iostream>
#include <algorithm>
using namespace std;
struct in
{
    int x,y;
    bool operator()(in a,in b)
    {
        if(a.y!=b.y)return a.y<b.y;
        return a.x<b.x;
    }
    
};
in temp[102];
int tb[102],n;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        if(x>y)swap(x,y);
        temp[i].x = x;
        temp[i].y = y;
    }
    sort(temp,temp+n,in());
    int ans = 0;
    for(int i = 0;i<n;i++)
    {
        tb[i] = 1;
        for(int j=0;j<i;j++)if(temp[j].x<=temp[i].x&&temp[j].y<=temp[i].y)tb[i]=max(tb[i],tb[j]+1);
        ans=max(ans,tb[i]);
    }
    cout<<ans;
}
