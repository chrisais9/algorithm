#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

int A, B, P, Q;
int mem[100001][4];

struct Z{
    int a, b;
};
queue <Z> que;

int& D(int a, int b)
{
    if (!a) return mem[b][0];
    if (a == A) return mem[b][1];
    if (!b) return mem[a][2];
    if (b == B) return mem[a][3];
    return mem[0][2];
}

void push(int a, int b, int d)
{
    if (D(a, b) < 2e9) return;
    D(a, b) = d; que.push({a, b});
}

int main()
{
    cin >> A >> B >> P >> Q;
    for (int i=0;i<=B;i++) for (int j=0;j<4;j++) mem[i][j] = 2e9;
    push(0, 0, 0);
    while (!que.empty()){
        Z q = que.front(); que.pop();
        int a = q.a, b = q.b, d = D(a, b);
        push(0, b, d+1);
        push(a, 0, d+1);
        push(A, b, d+1);
        push(a, B, d+1);
        int v = min(A-a, b);
        push(a+v, b-v, d+1);
        v = min(a, B-b);
        push(a-v, b+v, d+1);
    }
    printf("%d\n", D(P, Q) < 2e9 ? D(P, Q) : -1);
}
