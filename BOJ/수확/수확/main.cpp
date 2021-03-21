#include <iostream>
#include <vector>
using namespace std;
int n,dfs_ans,grd_ans;
vector<int> v;
void greedy(int p1,int p2,int cost,int dep)
{
    if(dep==n+1)
    {
        grd_ans=cost;
        return;
    }
    if(v[p1]<v[p2])greedy(p1+1,p2,cost+v[p1]*dep,dep+1);
    else greedy(p1,p2-1,cost+v[p2]*dep,dep+1);
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    greedy(0,n-1,0,1);
    cout<<grd_ans;
}
