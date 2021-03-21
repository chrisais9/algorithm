#include <iostream>
#include <string>
#include <vector>
#include <memory.h>
using namespace std;
int d[50][1<<15];
int main()
{
    vector<string> patterns;
    int n,k;
    cin >> n >> k;
    patterns.resize(n);
    for(int i=0; i<n; i++) cin >> patterns[i];
    memset(d,0,sizeof(d));
    for(int i=0; i<patterns[0].size(); i++)
    {
        for(char c = 'a' ; c<='z'; c++)
        {
            int v=0;
            for(int j=0; j<n; j++)
            {
                if(patterns[j][i]==c || patterns[j][i]=='?')
                    v |= (1<<j);
            }
            if(i==0) d[i][v]++;
            else for(int j=0; j<(1<<n); j++) d[i][j&v] = (d[i][j&v]+d[i-1][j])%1000003;
        }
    }
    int ans=0;
    for(int i=0; i<(1<<n); i++)
    {
        int bit=0;
        for(int j=0; j<n; j++) if(i&(1<<j)) bit++;
        if(bit==k) ans = (ans + d[patterns[0].size()-1][i])%1000003;
    }
    cout << ans << endl;
}
