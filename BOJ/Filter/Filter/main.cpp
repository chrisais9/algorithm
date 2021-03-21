#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int tb[41][41];
vector<int> v;
int n,m,T;
int main()
{
    int i,j,k,l,ans=0;
    cin>>n>>m;
    for(i=0;i<n;i++)for(j=0;j<m;j++)cin>>tb[i][j];
    cin>>T;
    for(i=0;i<n-2;i++)
    {
        for(j=0;j<m-2;j++)
        {
            v.clear();
            for(k=i;k<i+3;k++)
            {
                for(l=j;l<j+3;l++)
                {
                    v.push_back(tb[k][l]);
                }
            }
            sort(v.begin(),v.end());
            if(T<v[4])ans++;
        }
    }
    cout<<ans;
}
