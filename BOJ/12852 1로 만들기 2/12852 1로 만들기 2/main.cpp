#include<iostream>
using namespace std;
int tb[1000001], ck[1000001];
int main() {
    int n;
    cin>>n;
    
    ck[1]=-999999;
    tb[1]=0;
    
    for (int i=2;i<=n;i++) {
        tb[i]=tb[i-1]+1;
        ck[i]=i-1;
        if(!(i&1) && tb[i]>tb[i/2]+1) {
            tb[i]=tb[i/2]+1;
            ck[i]=i/2;
        }
        if (i%3==0&&tb[i]>tb[i/3]+1) {
            tb[i]=tb[i/3]+1;
            ck[i]=i/3;
        }
    }
    cout<<tb[n]<<endl;
    while (n!=-999999) {
        cout<<n<<' ';
        n=ck[n];
    }
}
