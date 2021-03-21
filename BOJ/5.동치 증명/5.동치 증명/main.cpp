#include <iostream>
#include <vector>
#define mp(a, b) make_pair((a), (b))
#define pb(a) push_back((a))
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;
typedef pair<lld, int> pli;
typedef pair<int, lld> pil;
typedef vector<vector<int>> Matrix;
typedef vector<vector<int>> Adj;
typedef vector<int> Vi;
typedef vector<int> Row;
int n, m, scc_cnt;
vector<vector<int>> adj, radj;
vector<int> vis, stk, scc_id;

void dfs(int cur)
{
    vis[cur] = 1;
    for (int nxt : adj[cur])
    {
        if (!vis[nxt])
        {
            dfs(nxt);
        }
    }
    stk.pb(cur);
}

void dfs2(int cur)
{
    vis[cur] = 1;
    scc_id[cur] = scc_cnt;
    for (int nxt : radj[cur])
    {
        if (!vis[nxt])
        {
            dfs2(nxt);
        }
    }
}

int main()
{
    int t;
    cin>>t;
    
    while (t--)
    {
        cin>>n>>m;
        adj.assign(n+1, vector<int>());
        radj.assign(n+1, vector<int>());
        vis.assign(n+1, 0);
        for (int i = 0; i < m; ++i)
        {
            int u, v;
            cin>>u>>v;
            adj[u].pb(v);
            radj[v].pb(u);
        }
        
        
        for (int i = 1; i <= n; ++i)
        {
            if (!vis[i])dfs(i);
        }
        
        
        vis.assign(n+1, 0);
        scc_id.assign(n+1, 0);
        scc_cnt = 0;
        while (!stk.empty())
        {
            int i = stk.back();
            stk.pop_back();
            if (!vis[i])
            {
                dfs2(i);
                ++scc_cnt;
            }
        }
        if (scc_cnt == 1)
        {
            cout<<0<<endl;
            continue;
        }
        vector<vector<int>> scc_adj(scc_cnt);
        vector<vector<int>> rscc_adj(scc_cnt);
        for (int i = 1; i <= n; ++i)
        {
            for (int j : adj[i])
            {
                if (scc_id[i] != scc_id[j])
                {
                    scc_adj[scc_id[i]].pb(scc_id[j]);
                    rscc_adj[scc_id[j]].pb(scc_id[i]);
                }
            }
        }
        
        int a = 0, b = 0;
        for (int i = 0; i < scc_cnt; ++i)
        {
            if (scc_adj[i].empty()) ++a;
            if (rscc_adj[i].empty()) ++b;
        }
        cout<<max(a,b)<<endl;
    }
}

