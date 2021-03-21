#include <iostream>
#include <algorithm>
using namespace std;
int d[5555];
int main(){
    int n,m,ans=1;
    cin>>n>>m;
    for(int i=0; i<n; i++) d[i] = i;
    for(int i=0; i<m; i++)
    {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        if(x>y) d[y] = max(d[y],x);
    }
    for(int k=1; k<=n; k++)
    {
        if(n%k!=0) continue;
        bool ok = true;
        for(int i=0; i<n; i++)
        {
            int j = (i+k)/k*k;
            if(d[i]>=j)
            {
                ok=false;
                break;
            }
        }
        if(ok)
        {
            ans = n/k;
            break;
        }
    }
    cout<<ans;
    return 0;
}

