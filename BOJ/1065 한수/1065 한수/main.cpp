#include <iostream>
using namespace std;
int main() {
    int n, ans=0;
    cin>>n;
    if(n<100)cout<<n;
    else {
        for(int i=100;i<=n;i++) {
            int a=i/100;
            int b=(i%100)/10;
            int c=(i%100)%10;
            if(a-b==b-c) ans++;
        }
        cout<<ans+99;
    }
}
