#include <iostream>
#include <string>
using namespace std;
string x;
int rangeMul(int s,int e) {
    if(s==e) return 1;
    return rangeMul(s+1, e) * (x[s]-'0');
}
int main() {
    cin>>x;
    int f=1,b=1;
    if(x.size() > 1) {
        for(int i=1;i<x.size();i++) {
            f = rangeMul(0, i);
            b = rangeMul(i, x.size());
            if(f == b) {
                cout<<"YES"<<endl;
                return 0;
            }
        }
    }
    cout<<"NO"<<endl;
}
