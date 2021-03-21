#include <iostream>
using namespace std;
int n,m;
int main() {
    cin>>n>>m;
    int tb[51][51];
    int ans=9999;
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>tb[i][j];
        }
    }
    for(int i=0;i<n-7;i++) {
        for(int j=0;j<m-7;j++) {
            int w=0,b=0;
            for(int k=0;k<8;k++) {
                for(int l=0;l<8;l++) {
                    if((k+i+l+j)%2==1) {
                        if(tb[i+k][j+l]=='B')b++;
                        else w++;
                    } else {
                        if(tb[i+k][j+l]=='B')w++;
                        else b++;
                    }
                }
            }
            ans = ans > w ? w : ans;
            ans = ans > b ? b : ans;
        }
    }
    cout<< ans;
}
