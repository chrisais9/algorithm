#include <iostream>
#include <math.h>
using namespace std;

string om[10] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white"};
int value(string x) {
    for(int j=0;j<10;j++) {
        if(om[j] == x) {
            return j;
        }
    }
    return -1;
}
int main() {
    string x;
    long long int sum=0;
    cin>>x;
    sum+=value(x)*10;
    cin>>x;
    sum+=value(x);
    cin>>x;
    int dec=value(x);
    if(dec!=0) sum*=pow(10, dec);
    cout<<sum;
}
