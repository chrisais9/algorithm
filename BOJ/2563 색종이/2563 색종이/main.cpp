#include <iostream>
using namespace std;
int tb[110][110];
int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        int a,b;
        cin>>a>>b;
        for(int j=a;j<a+10;j++) {
            for(int k=b;k<b+10;k++) {
                tb[j][k]=1;
            }
        }
    }
    
    int ans=0;
    for(int i=0;i<=100;i++) {
        for(int j=0;j<=100;j++) {
            if(tb[i][j]) ans++;
        }
    }
    cout<<ans;
}
