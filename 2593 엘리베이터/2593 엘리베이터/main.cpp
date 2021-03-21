#include <cstdio>
#include <vector>
#include <queue>
#define INF    987654321
using namespace std;


int n, m, start, goal;
vector<int> elevator[100001], flo[101];
int cnt[101], parent[101];
priority_queue<pair<int, int> > que;

void dijkstra()
{
    for (int i = 0; i < elevator[start].size(); i++) {
        cnt[elevator[start][i]] = 1;
        que.push(make_pair(-1, elevator[start][i]));
    }
    
    while (!que.empty()) {
        int ele = que.top().second;
        int c = que.top().first * -1;
        que.pop();
        
        if (c <= cnt[ele]) {
            for (int i = 0; i < flo[ele].size(); i++) {
                int other = flo[ele][i];
                for (int j = 0; j < elevator[other].size(); j++) {
                    int next = elevator[other][j];
                    
                    if (cnt[next] == 0 || c + 1 < cnt[next]) {
                        cnt[next] = c + 1;
                        parent[next] = ele;
                        que.push(make_pair((c + 1) * -1, next));
                    }
                }
            }
        }
    }
}

void print(int num)
{
    if (num == 0)    return;
    print(parent[num]);
    printf("%d\n", num);
}

void solve()
{
    int ans = INF, last;
    
    dijkstra();
    for (int i = 0; i < elevator[goal].size(); i++) {
        if (cnt[elevator[goal][i]] < ans) {
            ans = cnt[elevator[goal][i]];
            last = elevator[goal][i];
        }
    }
    
    if (ans >= INF || ans == 0)    printf("-1\n");
    else {
        printf("%d\n", ans);
        print(last);
    }
}

int main()
{
    int x, y;
    
    scanf("%d %d", &n, &m);
    
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &x, &y);
        while (x <= n) {
            elevator[x].push_back(i);
            flo[i].push_back(x);
            x += y;
        }
    }
    scanf("%d %d", &start, &goal);
    
    solve();
    
    return 0;
}

