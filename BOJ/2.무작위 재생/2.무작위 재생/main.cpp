#include <iostream>
#include <vector>
using namespace std;
vector<int> data;
int c[100010],d[200010];
int n,m,ans;
int main()
{
    int tcn;
    cin>>tcn;
    while (tcn--)
    {
        int i,t;
        cin>>n>>m;
        t=ans=0;
        for (i = 1; i <= n + m; i++)
        {
            if (i <= m)
            {
                int x;
                cin>>x;
                data.push_back(x);
                c[x]++;
                if (c[x]>1)t++;
            }
            if (i>n)
            {
                if (c[data[i-n]]>1)t--;
                c[data[i-n]]--;
            }
            if(t==0&&(i<=n||d[i-n]))d[i]=1;
            if (i > m && d[i]) ans++;
        }
        cout<<ans<<endl;
    }
}

