#include <iostream>
using namespace std;
int main() {
    int ans=0;
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) {
            char x;
            cin>>x;
            if(!((i+j)&1) && x=='F') ans++;
        }
    }
    cout<<ans;
}
