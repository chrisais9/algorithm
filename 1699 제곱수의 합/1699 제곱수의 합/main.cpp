#include <iostream>
#include <math.h>
using namespace std;

int D[100001] = { 0, };
int n;

int DP(int k){
    if (D[k] != 0)return D[k];
    
    for (int i = 1; i*i<=k; i++){
        if (D[k] > DP(k - i*i) + 1 || D[k] == 0)
            D[k] = DP(k - i*i) + 1;
    }
    return D[k];
}

int main(){
    cin >> n;
    D[1] = 1;
    cout << DP(n) << endl;
    return 0;
}
