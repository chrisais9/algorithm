#include <iostream>
#include <queue>
using namespace std;
struct point{
    int x,y,flag;
};
queue<point> q;
int w, h, tb[101][101];
int main()
{
    int x, y, flag;
    cin >> w >> h;
    q.push({0,0,0});
    while(!q.empty()) {
        point temp = q.front();
        x = temp.x;
        y = temp.y;
        flag = temp.flag;
        
        if(!temp.flag) {
            if(tb[x+1][y] < tb[x][y]) {
                
            }
            q.push
        }
        
    }
    
}
