#include <iostream>
#include <algorithm>
using namespace std;
long long int x, y, w, s,m;
int main() {
    cin>>x>>y>>w>>s;
    m=(x+y)%2;
    if(x<y)swap(x,y);
    cout << min((x+y)*w, min((x-m)*s+m*w,y*s+(x-y)*w))<<endl;
}
