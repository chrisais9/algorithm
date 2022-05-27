#include <iostream>
using namespace std;
int tb[100001];
int main() {
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++) {
        cin>>tb[i];
    }
    int sum=0,mx=-987654321;
    for(int i=0;i<k;i++) {
        sum+=tb[i];
    }
    if(mx < sum) {
        mx = sum;
    }
    for(int i=k;i<n;i++) {
        sum-=tb[i-k];
        sum+=tb[i];
        if(mx < sum) {
            mx = sum;
        }
    }
    cout<<mx;
}
