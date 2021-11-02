#include <iostream>
using namespace std;
int tb[100010],ck[100010],ck2[100010],ans;
void f(int x) {
    ck[x]=1;
    if(!ck[tb[x]]){
        f(tb[x]);
    } else if(!ck2[tb[x]]) {
        for(int i=tb[x];i!=x;i=tb[i]) ans++;
        ans++;
    }
    ck2[x]=1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n;
    while(n--) {
        cin>>m;
        for(int i=1;i<=m;i++) {
            cin>>tb[i];
        }
        for(int i=0;i<=m;i++) {
            ck[i]=0;
            ck2[i]=0;
        }
        ans=0;
        for(int i=1;i<=m;i++) {
            if(!ck[i]) {
                f(i);
            }
        }
        cout<<m-ans<<endl;
    }
}
