#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> ci;
vector<ci> v;
int tb[101][101],ck[101][101];
int n,m;
int ct(int fr,int se)
{
    int cnt=0;
    int x=v[fr].first,y=v[fr].second,rx=v[se].first-x,ry=v[se].second-y;
    do
    {
        if(x<0||x>=n||y<0||y>=m)
        {
            if(cnt>=3)return cnt;
            else break;
        }
        if(tb[x][y])
        {
            cnt++;
            ck[x][y]=1;
        }
        x+=rx;
        y+=ry;
    }while(1);
    x=v[fr].first;
    y=v[fr].second;
    rx=v[se].first-x;
    ry=v[se].second-y;
    do
    {
        if(x<0||x>=n||y<0||y>=m)return -1;
        ck[x][y]=0;
        x+=rx;
        y+=ry;
    } while (1);
}
int main()
{
    int i,j,t,ans=0;
    cin>>n>>m>>t;
    for(i=0;i<t;i++)
    {
        int x,y;
        cin>>x>>y;
        tb[x][y]=1;
        v.push_back(make_pair(x,y));
    }
    sort(v.begin(),v.end());
    for(i=0;i<t;i++)
    {
        if(ck[v[i].first][v[i].second])continue;
        for(j=0;j<t;j++)
        {
            if(i==j||ck[v[j].first][v[j].second])continue;
            ans=max(ans,ct(i,j));
        }
    }
    cout<<ans;
}
