#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
class data
{
public:
    char dat[12];
    bool operator < (const data &a)const
    {
        int i;
        for(i=0; dat[i] && a.dat[i] ;i++)if(dat[i] != a.dat[i]) return dat[i] < a.dat[i];
        if(!dat[i]) return true;
        else return false;
    }
} dat[100001],temp[100001];
int n;
long long cnt;
void Merge(int s,int e)
{
    if(s >= e) return;
    int m;
    m = (s+e)>>1;
    Merge(s,m);
    Merge(m+1,e);
    int S=s,M=m+1,C=s;
    while(S<=m && M<=e)
    {
        if(dat[S] < dat[M])
        {
            temp[C] = dat[S];
            C++;
            S++;
        }
        else
        {
            temp[C] = dat[M];
            C++;
            M++;
            cnt += (long long)(m-S+1);
        }
    }
    while(S<=m)
    {
        temp[C] = dat[S];
        C++;
        S++;
    }
    while(M<=e)
    {
        temp[C] = dat[M];
        C++;
        M++;
    }
    for(S=s;S<=e;S++)dat[S] = temp[S];
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)cin>>dat[i].dat;
    stable_sort(dat, dat+n);
    for(int i=0;i<n;i++)reverse(dat[i].dat,dat[i].dat+strlen(dat[i].dat));
    cnt=0;
    Merge(0,n-1);
    cout<<cnt;
}
