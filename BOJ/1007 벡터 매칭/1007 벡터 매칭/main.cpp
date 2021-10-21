#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <math.h>
using namespace std;
typedef long long int lld;
int a[20], b[20];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, num;
    cin>>n;
    for(int t=0;t<n;t++) {
        cin>>num;
        lld mi = 9223372036854775807;
        for (int i=0;i<num;i++) {
            cin>>a[i]>>b[i];
        }
        vector<int> v;
        for(int i=0;i<num/2;i++)
            v.push_back(0);
        for(int i=0;i<num/2;i++)
            v.push_back(1);
        do {
            lld ta=0,tb=0,t;
            for(int i=0;i<num;i++) {
                if(v[i]==0) {
                    ta += a[i];
                    tb += b[i];
                } else {
                    ta -= a[i];
                    tb -= b[i];
                }
            }
            t = ta*ta+tb*tb;
            mi = min(mi, t);
        } while(next_permutation(v.begin(), v.end()));
        printf("%.12lf\n", sqrt(mi));
    }
}
