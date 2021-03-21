#include <iostream>
#include <vector>
#include <algorithm>
#define LONG_LONG_MAX 4611686018427387903
using namespace std;
long long n,d;
vector<long long> h;

int main ()
{
    int tc;
    cin>>tc;
    while (tc--)
    {
        cin>>n>>d;
        h.resize(n);
        for (int i=0; i<n; i++) cin>>h[i];
        if (abs(h[0]-h[n-1]) > (n-1)*d)
        {
            cout<<"impossible"<<endl;
            continue;
        }
        vector<long long> tb(n);
        for (int i=0; i<n; i++)for (int j=-n+1; j<=n-1; j++)tb.push_back(h[i] + j*d);
        
        sort(tb.begin(),tb.end());
        tb.erase(unique(tb.begin(),tb.end()),tb.end());
        int H=tb.size();
        vector<long long> best(H, LONG_LONG_MAX);
        for (int i=0; i<H; i++)if (tb[i]==h[0]) best[i]=0;
        for (int t=1; t<n; t++)
        {
            vector<long long> next(H, LONG_LONG_MAX);
            int j=0;
            for (int i=0; i<H; i++)
            {
                while (j<H && tb[j]<tb[i]-d) j++;
                while (j+1<H && tb[j+1]<=tb[i]+d && best[j+1]<=best[j]) j++;
                if(next[i]>best[j] + abs(tb[i]-h[t]))next[i]=best[j] + abs(tb[i]-h[t]);
            }
            best=next;
        }
        for (int i=0; i<H; i++)if(tb[i]==h[n-1]) cout<<best[i]<<endl;
    }
}


