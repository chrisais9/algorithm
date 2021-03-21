#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
int arr[10001];
int main()
{
    int i,n;
    cin>>n;
    for(i=0;i<n;i++)cin>>arr[i];;
    
    sort(arr,arr+n);
    int idx_s=0,cnt=1,mx=1;
    for(int i=1;i<n;i++)
    {
        cnt++;
        while(arr[i]-arr[idx_s]>4)
        {
            idx_s++;
            cnt--;
        }
        mx=max(mx,cnt);
    }
    if(mx>5)mx=5;
    cout<<5-mx;
}
