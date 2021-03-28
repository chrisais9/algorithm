#include <iostream>
using namespace std;
int main() {
    int a,b,cnt=1;
    cin>>a>>b;
    while(1){
        if (a==b)break;
        else if(a > b) {
            cnt=-1;
            break;
        }
        else if((b%10) == 1) {
            b/=10;
            cnt++;
        }
        else if(!(b&1)) {
            b>>=1;
            cnt++;
        }
        else {
            cnt=-1;
            break;
        }
    }
    cout<<cnt;
}
