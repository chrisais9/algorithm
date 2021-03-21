#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
#define INF 987654321
typedef pair<int, int> ii;
typedef pair< ii,  ii> pp;

char s[50][51];
int h, w;
int DX[] = {0, 0,-1, 1};
int DY[] = {1,-1, 0, 0};
bool aroundTrash(int y, int x)
{
    for(int d=0; d<4; ++d)
    {
        int dy = y+DY[d], dx = x+DX[d];
        if(dy < 0 || dx < 0 || dy >= h || dx >= w) continue;
        if(s[dy][dx] == 'g') return true;
    }
    return false;
}

ii reverse(const ii& p)
{
    return {-p.first, -p.second};
}

int main()
{
    int i, j;
    cin>>h>>w;
    for(i=0; i<h; ++i)cin>>s[i];
    
    priority_queue<pp> pq;
    ii passed[51][51];
    bool around[51][51];
    int endY, endX;
    for(i=0; i<h; ++i)
    {
        for(j=0; j<w; ++j)
        {
            passed[i][j] = {INF, INF};
            if(s[i][j] == 'S') pq.push({{0, 0}, {i, j}});
            else if(s[i][j] == 'F')
            {
                endY = i;
                endX = j;
            }
            around[i][j] = aroundTrash(i, j);
        }
    }
    
    while(!pq.empty())
    {
        pp cur = pq.top();
        pq.pop();
        
        int pass = -cur.first.first;
        int arnd = -cur.first.second;
        int y = cur.second.first;
        int x = cur.second.second;
        
        if(passed[y][x] < reverse(cur.first)) continue;
        passed[y][x] = reverse(cur.first);
        
        if(s[y][x] == 'F') break;
        
        for(i=0; i<4; ++i)
        {
            int dy = y+DY[i], dx = x+DX[i];
            if(dy < 0 || dx < 0 || dy >= h || dx >= w) continue;
            
            ii next = {pass, arnd};
            if(s[dy][dx]=='g') next = {pass + 1, arnd};
            if(s[dy][dx]=='.') next = {pass, arnd + around[dy][dx]};
            
            if(passed[dy][dx] <= next) continue;
            passed[dy][dx] = next;
            pq.push({reverse(next), {dy, dx}});
        }
    }
    cout<<passed[endY][endX].first<<passed[endY][endX].second;
    return 0;
}
