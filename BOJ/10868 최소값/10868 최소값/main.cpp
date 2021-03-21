#include <iostream>
#include <algorithm>
using namespace std;
int tree[5000000];
int n,m,tn;
int find(int a,int b)
{
    int mi=1000000000;
    while(a<b)
    {
        if(a%2==1)
        {
            mi=min(mi,tree[a]);
            a++;
        }
        if(b%2==0)
        {
            mi=min(mi,tree[b]);
            b--;
        }
        
        a>>=1;
        b>>=1;
    }
    if(a==b)mi=min(mi,tree[a]);
    return mi;
}
int main()
{
    int i;
    cin>>n>>m;
    for(tn=1;tn<n;tn<<=1);
    for(i=tn;i<tn+n;i++)cin>>tree[i];
    for(i=tn-1;i>0;i--)
    {
        if(!tree[i*2])tree[i*2]=1000000000;
        if(!tree[(i*2)+1])tree[(i*2)+1]=1000000000;
        tree[i]=min(tree[i*2],tree[(i*2)+1]);
    }
    for(i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        cout<<find(tn+a-1,tn+b-1)<<endl;
    }
}
