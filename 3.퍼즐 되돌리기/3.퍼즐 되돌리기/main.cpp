#include <iostream>
#include <vector>
using namespace std;
int n,k,u;
int ck[1010];
vector< vector<int> > button;
vector<int> tb,order,gv;
void press(int num)
{
    int i;
    vector<int> temp;
    for(i=0;i<tb.size();i++)
    {
        temp.push_back(tb[button[num][i]]);
    }
    tb=temp;
}
int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
    
}
int dfs(int x)
{
    if(ck[x])return 0;
    ck[x]=1;
    return dfs(tb[x])+1;
    
}
int main()
{
    int i,j;
    cin>>n>>k>>u;
    button.resize(k+1);
    for(i=0;i<n;i++)tb.push_back(i);
    for(i=0;i<u;i++)
    {
        int x;
        cin>>x;
        order.push_back(x);
    }
    for(i=1;i<=k;i++)
    {
        for(j=0;j<n;j++)
        {
            int x;
            cin>>x;
            button[i].push_back(x-1);
        }
    }
    for(i=0;i<u;i++)press(order[i]);
    for(i=0;i<n;i++)
    {
        if(!ck[i])
        {
            int t=dfs(i);
            if(t>1)gv.push_back(t);
        }
    }
    if(gv.size()==0)cout<<1<<endl;
    else if(gv.size()==1)cout<<gv[0]<<endl;
    else
    {
        while (gv.size()<=1)
        {
            int a=gv.back();
            gv.pop_back();
            int b=gv.back();
            gv.pop_back();
            gv.push_back(gcd(a,b));
        }
        cout<<gv[0]<<endl;
    }
    
}
