#include <iostream>
#include <algorithm>
#include <vector>
#define MAXN 100000
using namespace std;
int x[MAXN],l[MAXN];
int X[4*MAXN];
vector< pair<int, int> > ev;
int nxt[17][4 * MAXN];
int main()
{
    int C,N;
    cin>>C>>N;
    int M = 0;
    for(int i = 0;i < N;++i)
    {
        cin>>x[i]>>l[i];
        X[M++] = x[i];
        X[M++] = x[i] + l[i];
        X[M++] = x[i] + C;
        X[M++] = min(C,x[i] + l[i]) + C;
        ev.push_back(make_pair(x[i],x[i] + l[i]));
        ev.push_back(make_pair(x[i]+C,min(C,x[i]+l[i])+C));
    }
    sort(X,X + M);
    M=unique(X,X+M)-X;
    sort(ev.begin(),ev.end());
    
    int N2 = 2 * N;
    
    for(int i = 0,pos = 0,best = 0;i < M;++i)
    {
        while(pos < N2 && ev[pos].first == X[i])
        {
            int e = lower_bound(X,X + M,ev[pos].second) - X;
            best = max(best,e);
            ++pos;
        }
        
        nxt[0][i] = best;
    }
    
    for(int i = 1;i <= 16;++i)
        for(int j = 0;j < M;++j)
            nxt[i][j] = nxt[i - 1][ nxt[i - 1][j] ];
    
    int ans = N;
    
    for(int i = 0;i < N;++i)
    {
        int s = x[i],cont = 0;
        int pos = lower_bound(X,X + M,s) - X;
        
        for(int j = 16,to;j >= 0;--j)
        {
            to = nxt[j][pos];
            if(X[to] - s < C)
            {
                pos = to;
                cont |= (1 << j);
            }
        }
        ans = min(ans,cont);
    }
    cout<<ans;
}
