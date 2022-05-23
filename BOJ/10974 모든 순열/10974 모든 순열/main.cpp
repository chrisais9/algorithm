#include <iostream>
#include <algorithm>
using namespace std;
int n,tb[10];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++)tb[i]=i+1;
    do {
        for(int i=0;i<n;i++)
            cout<<tb[i]<<" ";
        cout<<"\n";
    } while(next_permutation(tb, tb+n));
}
