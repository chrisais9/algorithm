#include <stdio.h>
#include <algorithm>
#define INF 0x7fffffff
using namespace std;
typedef pair<int,int> ci;
int n;
ci r[500000],ans[500000];
int main()
{
    int i,a,b;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d %d",&a,&a,&b);
        r[i].first=-a;
        r[i].second=b;
    }
    sort(r,r+n);
    ci temp;
    for(i=0;i<n;i++)
    {
        temp.first=r[i].second;
        temp.second=r[i].first;
        ans[i].first=ans[i].second=INF;
        *lower_bound(ans,ans+i,temp)=temp;
    }
    printf("%d",lower_bound(ans,ans+n,ci(INF,INF))-ans);
}
