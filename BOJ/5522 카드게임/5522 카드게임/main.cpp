#include <iostream>
using namespace std;
int main() {
    int cnt=0;
    for(int i=0;i<5;i++) {
        int x;
        cin>>x;
        cnt+=x;
    }
    cout<<cnt;
}
