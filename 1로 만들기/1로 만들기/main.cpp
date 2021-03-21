#include <iostream>
#include <algorithm>
#include <memory.h>
#define MAX 9999999
using namespace std;
int tb[1000010];
int main()
{
    int i,n;
    cin>>n;
    memset(tb,MAX,sizeof(tb));
    tb[n]=0;
    for(i=n;i>=1;i--)
    {
        if(i==n||tb[i]!=MAX)
        {
            if(i%2==0)tb[i/2]=min(tb[i/2],tb[i]+1);
            if(i%3==0)tb[i/3]=min(tb[i/3],tb[i]+1);
            tb[i-1]=min(tb[i]+1,tb[i-1]);
        }
    }
    cout<<tb[1];
}
