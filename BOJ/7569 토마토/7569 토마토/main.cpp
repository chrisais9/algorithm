#include<iostream>
#include<vector>
#include<queue>

#define endl "\n"
#define MAX 100
using namespace std;

int M, N, H, Empty_Space, Answer = 0;
int MAP[MAX][MAX][MAX];
bool Visit[MAX][MAX][MAX];
bool Tomato_State;

int dx[] = { 0, 0, 1, -1, 0, 0 };
int dy[] = { 1, -1, 0, 0, 0, 0 };
int df[] = { 0, 0, 0, 0, 1, -1 };

vector<pair<pair<int, int>, int >> Ripen_Tomato;
queue<pair<pair<int, int>, int>> Q;

void Input()
{
    Tomato_State = true;
    cin >> M >> N >> H;
    for (int k = 0; k < H; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cin >> MAP[i][j][k];        // x, y, 높이
                if (MAP[i][j][k] == 0) Tomato_State = false;
                if (MAP[i][j][k] == 1) Q.push(make_pair(make_pair(i, j), k));
            }
        }
    }
}

bool Check_Tomato_State()
{
    for (int k = 0; k < H; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (MAP[i][j][k] == 0) return false;
            }
        }
    }
    return true;
}

void BFS()
{
    while (Q.empty() == 0)
    {
        int Qs = Q.size();
        
        for (int Q_s = 0; Q_s < Qs; Q_s++)
        {
            int x = Q.front().first.first;
            int y = Q.front().first.second;
            int f = Q.front().second;
            Q.pop();
            
            for (int i = 0; i < 6; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                int nf = f + df[i];
                
                if (nx >= 0 && ny >= 0 && nf >= 0 && nx < N && ny < M && nf < H)
                {
                    if (MAP[nx][ny][nf] == 0)
                    {
                        MAP[nx][ny][nf] = 1;
                        Q.push(make_pair(make_pair(nx, ny), nf));
                    }
                }
            }
            if (Q.size() == 0 && Check_Tomato_State() == true)
            {
                cout << Answer << endl;
                return;
            }
            else if (Q.size() == 0 && Check_Tomato_State() == false)
            {
                cout << -1 << endl;
                return;
            }
        }
        Answer++;
    }
}

void Solution()
{
    if (Tomato_State == true)
    {
        cout << 0 << endl;
        return;
    }
    
    BFS();
}

void Solve()
{
    Input();
    Solution();
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    //freopen("Input.txt", "r", stdin);
    Solve();
    
    return 0;
}
