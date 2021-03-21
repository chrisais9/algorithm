#include <iostream>
#include <algorithm>
using namespace std;
double tb[10010];
int n;
int main()
{
    int i,j;
    double ans=0;
    cin>>n;
    for(i=0;i<n;i++)cin>>tb[i];
    for(i=0;i<n;i++)
    {
        double x=1.0;
        for(j=i;j<n;j++)
        {
            x*=tb[j];
            ans=max(ans,x);
        }
    }
    printf("%.3lf",ans);
}
