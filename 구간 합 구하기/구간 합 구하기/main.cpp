#include <iostream>
#include <vector>
using namespace std;
vector<long long int> tree;
int n,m,tn=1;
void update(int x,int dif)
{
    tree[x]+=dif;
    x>>=1;
    while (x>=1)
    {
        tree[x]=tree[x*2]+tree[x*2+1];
        x>>=1;
    }
}
long long int query(int s,int e)
{
    long long int sum=0;
    while(s<e)
    {
        if((s&1))sum+=tree[s++];
        if(!(e&1))sum+=tree[e--];
        s>>=1;
        e>>=1;
    }
    if(s==e)sum+=tree[s];
    return sum;
}
int main()
{
    cin>>n>>m;
    while(tn<=n)tn<<=2;
    tree.resize(tn<<2,0);
    for(int i=0;i<m;i++)
    {
        int q,x,y;
        cin>>q>>x>>y;
        if(q)cout<<query(x+tn-1,y+tn-1)<<endl;
        else update(x+tn-1,y);
    }
}
