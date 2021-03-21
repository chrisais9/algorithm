#include <iostream>
using namespace std;
int k,tb[13],result[6];
void f(int x,int d) {
    if(x==2) {
        for(int i=0;i<2;i++) {
            cout<< result[i] << " ";
        }
        cout<< endl;
        return;
    }
    for(int i=x;i<k;i++) {
        result[d] = tb[i];
        f(i+1, d+1);
    }
}
int main() {
    while(1) {
        cin>>k;
        if(k==0) return 0;
        for(int i=0;i<k;i++) {
            cin>>tb[i];
        }
        f(0,0);
    }
}
