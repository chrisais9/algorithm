#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;
struct shark
{
    int a,b,c;
};
vector< vector<int> > v(51);
vector<shark> data;
int ck[51],b[51];
int n;
int f(int so)
{
    if(ck[so])return 0;
    ck[so]=1;
    for(int i=0;i<v[so].size();i++)
    {
        int si=v[so][i];
        if(!b[si]||f(b[si]))
        {
            b[si]=so;
            return 1;
        }
    }
    return 0;
}
int main()
{
    int i,j,ans=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        shark te;
        cin>>te.a>>te.b>>te.c;
        data.push_back(te);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)continue;
            if (data[i].a == data[j].a && data[i].b == data[j].b && data[i].c == data[j].c && i>j)continue;
            if (data[i].a >= data[j].a && data[i].b >= data[j].b && data[i].c >= data[j].c)
            {
                v[i+1].push_back(j+1);
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=0;j<2;j++)
        {
            memset(ck,0,sizeof(ck));
            if(f(i))ans++;
        }
    }
    cout<<n-ans;
}
