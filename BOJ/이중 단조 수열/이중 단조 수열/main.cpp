#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> data;
int inc[1010],de[1000];
int main()
{
    int i,j,ans=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        int x;
        cin>>x;
        data.push_back(x);
    }
    for(i=0;i<n;i++)for(j=0;j<i;j++) if(data[i]>data[j]&&inc[i]<inc[j]+1)inc[i]=inc[j]+1;
    for(i=n-1;i>=0;i--)for(j=n-1;j>i;j--) if(data[i]>data[j]&&de[i]<de[j]+1)de[i]=de[j]+1;
    for(i=0;i<n;i++)ans=max(ans,inc[i]+de[i]);
    cout<<ans+1;
}
