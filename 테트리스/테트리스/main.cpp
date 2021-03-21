#include <iostream>
using namespace std;

#define MN 101
#define MH 301
#define Bound 2147483647
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
int n, l, r;
int c[MN][MH][MH], d[MN];
bool ch[MN][MH][MH];
void input()
{
    cin>>n;
    for (int i = 1; i <= n; i++)cin>>d[i];
}
void upd(int x, int y, int z)
{
    if (x < MH && y < MH) {
        if (!c[l][x][y] || c[l][x][y] > z) {
            c[l][x][y] = z; ch[l][x][y] = 1;
        }
    }
}
void process()
{
    int i, j, k, t;
    
    c[0][0][0] = 0; ch[0][0][0] = 1;
    for (l = 1; l <= n; l++) {
        for (i = 0; i < MH; i++) {
            for (j = 0; j < MH; j++) {
                if (!ch[l-1][i][j]) continue;
                k = c[l-1][i][j];
                if (d[l] == 1) {
                    upd(i+4,j,k); upd(i,j+4,k); upd(i,j,k+4);
                }
                else if (d[l] == 2) {
                    t = max(i,j-2); upd(t+3,t+3,k);
                    t = max(j,k-2); upd(i,t+3,t+3);
                    t = max(max(i,j),k); upd(t+2,t+1,t+1);
                    t = max(i,j); upd(t+1,t+3,k);
                    t = max(j,k); upd(i,t+1,t+3);
                    t = max(max(i-1,j-1),k); upd(t+2,t+2,t+2);
                }
                else if (d[l] == 3) {
                    t = max(i-2,j); upd(t+3,t+3,k);
                    t = max(j-2,k); upd(i,t+3,t+3);
                    t = max(max(i,j),k); upd(t+1,t+1,t+2);
                    t = max(i,j); upd(t+3,t+1,k);
                    t = max(j,k); upd(i,t+3,t+1);
                    t = max(max(i,j-1),k-1); upd(t+2,t+2,t+2);
                }
                else if (d[l] == 4) {
                    t = max(max(i,j),k); upd(t+1,t+2,t+1);
                    t = max(i,j-1); upd(t+3,t+2,k);
                    t = max(j,k-1); upd(i,t+3,t+2);
                    t = max(max(i-1,j),k-1); upd(t+2,t+2,t+2);
                    t = max(i-1,j); upd(t+2,t+3,k);
                    t = max(j-1,k); upd(i,t+2,t+3);
                }
                else if (d[l] == 5) {
                    t = max(max(i,j),k-1); upd(t+1,t+2,t+2);
                    t = max(i-1,j); upd(t+3,t+2,k);
                    t = max(j-1,k); upd(i,t+3,t+2);
                }
                else if (d[l] == 6) {
                    t = max(max(i-1,j),k); upd(t+2,t+2,t+1);
                    t = max(i,j-1); upd(t+2,t+3,k);
                    t = max(j,k-1); upd(i,t+2,t+3);
                }
                else {
                    t = max(i,j); upd(t+2,t+2,k);
                    t = max(j,k); upd(i,t+2,t+2);
                }
            }
        }
    }
}
void output()
{
    int i, j;
    
    r = Bound;
    for (i = 0; i < MH; i++) {
        for (j = 0; j < MH; j++) {
            if (!ch[n][i][j]) continue;
            r = min(r,max(max(i,j),c[n][i][j]));
        }
    }
    cout<<r;
}
int main()
{
    input();
    process();
    output();
    return 0;
}
