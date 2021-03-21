#include <iostream>
#include <vector>
using namespace std;
vector<int> coin;
int n,k;
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        coin.push_back(x);
    }
    int ans=0;
    for(int i=coin.size()-1;i>=0;i--)
    {
        for(int j=0;;j++)
        {
            if(k-coin[i]>0)
            {
                cout<<coin[i]<<" "<<k<<endl;
                k-=coin[i];
                break;
            }
            ans++;
        }
    }
    cout<<ans;
}
