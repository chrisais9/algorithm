#include <iostream>
using namespace std;
int ans=0,n,tb[15];

int isAvailable(int x) {
    for (int i=0;i<x;i++) {
        if (tb[x]==tb[i] || x-i==abs(tb[x]-tb[i])) return 0;
    }
    return 1;
}
void f(int x) {
    if (x==n) {
        ans++;
        return;
    }
    for (int i=0;i<n;i++) {
        tb[x] = i;
        if(isAvailable(x)) f(x+1);
    }
}
int main() {
    cin>>n;
    f(0);
    cout<<ans;
}
