#include <iostream>
#include <string>
using namespace std;

int n,ck[101][101],isGroup=0;
string tb[101];
void f(int x, int y, char c) {
    if(x<0 || x>=n || y<0 || y>=n || c!= tb[x][y] || ck[x][y]) return;
    ck[x][y] = 1;
    isGroup=1;
    f(x+1,y,c);
    f(x-1,y,c);
    f(x,y+1,c);
    f(x,y-1,c);
}
int main() {
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>tb[i];
    }
    int group=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(!ck[i][j]) {
                isGroup=0;
                f(i,j,tb[i][j]);
                group+=isGroup;
            }
        }
    }
    cout<<group<<" ";
    
    group=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            ck[i][j]=0;
            if(tb[i][j]=='G') tb[i][j]='R';
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(!ck[i][j]) {
                isGroup=0;
                f(i,j,tb[i][j]);
                group+=isGroup;
            }
        }
    }
    cout<<group;
}
