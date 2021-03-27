#include <iostream>
#include <cmath>
using namespace std;
typedef long long lld;
bool ck[1000001];
lld tb[1000001];
int main(void){
    lld min;
    lld max;
    cin >> min >> max;
    lld cnt = 0;
    for(lld i=2; i<=sqrt(max); i++) {
        tb[i] = i*i;
        cnt++;
    }
    int ans=0;
    for(int i=2; i<cnt+2; i++){
        lld div_min = min;
        if(div_min % tb[i] != 0) div_min = (min/tb[i] + 1) * tb[i];
        for(lld t = div_min; t <=max; t += tb[i]) if(!ck[t-min]){
            ck[t-min] = true;
            ans++;
        }
    }
    cout << max - min - ans + 1;
}
