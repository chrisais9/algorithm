#include <iostream>
#include <algorithm>
using namespace std;
int mi[3], mx[3];
int main() {
    int n;
    cin>>n;
    int a,b,c;
    cin>>a>>b>>c;
    mi[0]=mx[0]=a;
    mi[1]=mx[1]=b;
    mi[2]=mx[2]=c;
    
    for(int i=0;i<n-1;i++) {
        cin>>a>>b>>c;
        mx[0]=max(mx[0],mx[1]);
        mx[2]=max(mx[1],mx[2]);
        mx[1]=max(mx[0],mx[2])+b;
        mx[0]+=a;
        mx[2]+=c;
        
        mi[0]=min(mi[0],mi[1]);
        mi[2]=min(mi[1],mi[2]);
        mi[1]=min(mi[0],mi[2])+b;
        mi[0]+=a;
        mi[2]+=c;
    }
    
    cout<<max(mx[0],max(mx[1],mx[2]))<<" "<<min(mi[0],min(mi[1],mi[2]));
}
