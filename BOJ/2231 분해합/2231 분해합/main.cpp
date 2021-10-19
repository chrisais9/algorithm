#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    for(int i=1;i<n;i++) {
        int t=i,sum=i;
        while(t) {
            sum+=t%10;
            t/=10;
        }
        if(sum==n) {
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<0<<endl;
}
