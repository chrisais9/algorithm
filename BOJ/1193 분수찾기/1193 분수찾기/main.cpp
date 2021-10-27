#include <iostream>
using namespace std;

int main() {
    int i,n;
    cin>>n;
    for(i=1;i<n;n-=i,i++);
    if (i&1) cout<<i+1-n<<'/'<<n<<endl;
    else cout<<n<<'/'<<i+1-n<<endl;
}
