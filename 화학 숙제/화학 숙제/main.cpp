#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct data
{
    int a,b,c;
    bool operator()(data x,data y)
    {
        return x.a<y.a;
    }
};
int n,ans;
vector<data> v;
int ck[3][100010];
void er(int x)
{
    ans++;
    if(ans>=n)return;
    for(int i=0;i<n;i++)
    {
        if(ck[1][i]==x||ck[2][i]==x)
        {
            ck[0][i]=-1;
            er(x);
        }
    }
}
int main()
{
    int i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        data temp;
        cin>>temp.a;
        v.push_back(temp);
    }
    for(i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v[i].b=x;
    }
    for(i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v[i].c=x;
    }
    sort(v.begin(),v.end(),data());
    for(i=0;i<n;i++)
    {
        ck[0][v[i].a]=i+1;
        if(ck[1][v[i].b])er(v[i].b);
        else ck[1][v[i].b]=i+1;
        if(ck[2][v[i].c])er(v[i].c);
        else ck[2][v[i].c]=i+1;
    }
    cout<<ans<<endl;
    for(i=0;i<3;i++)
    {
        for(int j=1;j<=n;j++)cout<<ck[i][j]<<" ";
        cout<<endl;
    }
}


