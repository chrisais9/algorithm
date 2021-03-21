#include <iostream>
#include <algorithm>
#include <queue>
#define N 100000
using namespace std;
int n,m,k,e[N];

struct abc
{
    int num,data,ck;
}A[N];
struct qstr
{
    int data,num,p;
}Q[N];
bool cmp(const abc &x,const abc &y)
{
    return x.data<y.data;
}
int binary(int temp)
{
    int f=1,l=n,mid;
    while(f<=l)
    {
        mid=(f+l)/2;
        if(temp==A[mid].data)return mid;
        if(temp<A[mid].data)l=mid-1;
        else f=mid+1;
    }
    return -1;
}
void bfs()
{
    int f=0,r=1,t,z,i;
    while(1)
    {
        if(f==r)break;
        z=1;
        f++;
        for(i=0;i<k;i++,z*=2)
        {
            t=Q[f].data^z;
            if(A[t].ck||binary(t))continue;
            r++;
            Q[r].data=A[t].data;
            Q[r].num=A[t].num;
            Q[f].p=f;
            A[t].ck=1;
            
        }
    }
    
}
int main()
{
    char c;
    int i,j;
    cin>>n>>k;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=k;j++)
        {
            cin>>c;
            A[i].data=A[i].data*2+(c-'0');
            A[i].num=i;
        }
    }
    Q[1].data=A[1].data;
    Q[1].num=A[1].num;
    A[1].ck=1;
    sort(A+1,A+n+1,cmp);
    cin>>m;
    for(i=1;i<=m;i++)cin>>e[i];
    bfs();
    cout<<1<<endl;
}
