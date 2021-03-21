#include <cstdio>
#include <algorithm>
using namespace std;

int n;
long long int x[101], y[101];

struct Inter
{
    long long int st, ed;
    
    bool operator < (const Inter &A) const
    {
        if(st!=A.st) return st<A.st;
        else return ed<A.ed;
    }
} arr[10001];

inline long long int abs(long long int x)
{
    if(x<0) return -x;
    return x;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int i, j;
    
    scanf("%d", &n);
    for(i=1; i<=n; i++) scanf("%I64d %I64d", &x[i], &y[i]);
    
    long long int st=0, ed=4000000000, mid=(st+ed)/2, res;
    while(st<=ed)
    {
        bool poss=true;
        int c=0;
        for(i=1; i<=n; i++)
        {
            for(j=i+1; j<=n; j++)
            {
                long long int dis=abs(x[i]-x[j])+abs(y[i]-y[j]);
                if(dis>mid) {poss=false; break; }
                ++c;
                if(y[i]<y[j]) arr[c].st=y[i], arr[c].ed=y[j];
                else arr[c].st=y[j], arr[c].ed=y[i];
                arr[c].st-=(mid-dis)/2, arr[c].ed+=(mid-dis)/2;
            }
            if(poss==false) break;
        }
        
        if(poss==false)
        {
            st=mid+1, mid=(st+ed)/2;
            continue;
        }
        
        sort(arr+1, arr+c+1);
        
        long long int start=arr[1].st, end=arr[1].ed;
        for(i=2; i<=c; i++)
        {
            if(end<arr[i].st) {poss=false; break; }
            if(end>=arr[i].ed) start=arr[i].st, end=arr[i].ed;
            else start=arr[i].st;
        }
        
        if(poss) ed=mid-1,res=mid;
        else st=mid+1;
        
        mid=(st+ed)/2;
    }
    
    printf("%lld", res);
    
    return 0;
}
