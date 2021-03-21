#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int i,j,n,m,r=0,c=0;
    bool ck;
    char s[50][51];
    cin>>n>>m;
    for(i=0; i<n; i++)cin>>s[i];
    for(i=0; i<n; i++)
    {
        ck=1;
        for(j=0; j<m && ck; j++) ck &= s[i][j]=='.';
        r+=ck;
    }
    for(i=0; i<m; i++)
    {
        ck=1;
        for(j=0; j<n && ck; j++) ck &= s[j][i]=='.';
        c+=ck;
    }
    cout<<r+c-min(r,c);
}
