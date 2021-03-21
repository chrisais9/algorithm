#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int t=1;
    for(int i=0;i<n*2-1;i++) {
        if(i<n) {
            for(int j=0;j<i;j++) {
                cout<<" ";
            }
            for(int j=0;j<n-i-1;j++) {
                cout<<"*";
            }
            for(int j=0;j<n-i;j++) {
                cout<<"*";
            }
        } else {
            t+=2;
            for(int j=i;j<n*2-2;j++) {
                cout<<" ";
            }
            for(int j=0;j<t;j++) {
                cout<<"*";
            }
        }
        cout<<endl;
    }
}
