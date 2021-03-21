#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    while(1) {
        int tb[1001][1001] = {0,};
        int n,m;
        cin>>n>>m;
        if(n==0 && m==0)break;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cin>>tb[i][j];
            }
        }
        
        for(int i=1;i<n;i++) {
            for(int j=1;j<m;j++) {
                tb[i][j] = min(tb[i])
            }
        }
        
    }
}
