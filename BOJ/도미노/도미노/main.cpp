#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> ci;
int n,m,l,flag=0;
int dm[4]={-99,-99,-1,1};
int tb[101][101];
int vck[10010],ck[101];
vector<ci> v;
vector<int> order;
void f(int d)
{
    if(flag)return;
    if(d==(n*m)/2)
    {
        for(int i=0;i<order.size();i++)
        {
            cout<<min(v[order[i]].first,v[order[i]].second)
            <<" "<<max(v[order[i]].first,v[order[i]].second)<<endl;
        }
        flag=1;
        return;
    }
    for(int i=0;i<v.size();i++)
    {
        int x=v[i].first,y=v[i].second;
        if(!tb[x][y]&&!ck[x]&&!ck[y]&&!vck[i])
        {
            order.push_back(i);
            vck[i]=ck[x]=ck[y]=1;
            f(d+1);
            vck[i]=ck[x]=ck[y]=0;
            order.pop_back();
        }
    }
}
int main()
{
    int i,j;
    cin>>n>>m>>l;
    for(i=0;i<l;i++)
    {
        int x,y;
        cin>>x>>y;
        tb[x][y]=tb[y][x]=1;
    }
    dm[0]=-m;
    dm[1]=m;
    for(i=1;i<=n*m;i+=2)
    {
        for(j=0;j<4;j++)
        {
            if(tb[i][i+dm[j]]||i+dm[j]<=0||i+dm[j]>n*m||(i%m==0&&i+dm[j]==i+1)||(i%m==1&&i+dm[j]==i-1))continue;
            v.push_back(make_pair(i,i+dm[j]));
        }
    }
    cout<<endl;
    f(0);
    
}
