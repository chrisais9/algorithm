#include<iostream>
#include<string>
#include<queue>
using namespace std;
int n, m;
int rx, ry, bx, by, ox, oy, ans, flag;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
char board[11][11];
int ck[11][11][11][11];
struct loc {
    int rx,ry,bx,by;
};
queue<loc> q;

int main(void)
{
    cin>>n>>m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin>>board[i][j];
            if (board[i][j] == 'R') {
                rx = i;
                ry = j;
            }
            if (board[i][j] == 'B') {
                bx = i;
                by = j;
            }
            if (board[i][j] == 'O') {
                ox = i;
                oy = j;
            }
        }
    }
    q.push({rx,ry,bx,by});
    ck[rx][ry][bx][by] = 1;
    
    while (!q.empty()) {
        int qn = q.size();
        while (qn--) {
            rx = q.front().rx;
            ry = q.front().ry;
            bx = q.front().bx;
            by = q.front().by;
            q.pop();
 
            if (ans > 10) break;
            if (rx == ox && ry == oy) {
                flag = 1;
                break;
                
            }

            for (int i=0;i<4;i++) {
                int rtx = rx+dx[i];
                int rty = ry+dy[i];
                int btx = bx+dx[i];
                int bty = by+dy[i];
 
                while (1) {
                    if (board[rtx][rty] == '#') {
                        rtx-=dx[i];
                        rty-=dy[i];
                        break;
                    }
                    if (board[rtx][rty] == 'O') break;
                    rtx+=dx[i];
                    rty+=dy[i];
                }
                while (1) {
                    if (board[btx][bty] == '#') {
                        btx-=dx[i];
                        bty-=dy[i];
                        break;
                    }
                    if (board[btx][bty] == 'O') break;
                    btx+=dx[i];
                    bty+=dy[i];
                }
 
                if (btx == ox && bty == oy) continue;
                if (rtx == btx && rty == bty) {
                    switch (i) {
                        case 0:
                            rx > bx ? rtx++ : btx++;
                            break;
                        case 1:
                            rx < bx ? rtx-- : btx--;
                            break;
                        case 2:
                            ry > by ? rty++ : bty++;
                            break;
                        case 3:
                            ry < by ? rty-- : bty--;
                            break;
                    }
                }
                
                if (!ck[rtx][rty][btx][bty]) {
                    ck[rtx][rty][btx][bty]=1;
                    q.push({rtx,rty,btx,bty});
                }
            }
        }
        if (flag) break;
        else ans++;
    }
    cout<<(flag?ans:-1);
}
