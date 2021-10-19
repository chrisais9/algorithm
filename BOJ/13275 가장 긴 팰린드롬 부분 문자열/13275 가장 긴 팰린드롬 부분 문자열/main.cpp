#include <iostream>
#include <string>
using namespace std;
string s;
int tb[200010];
int main() {
    cin>>s;
    string t;
    for(int i=0;i<s.size();i++) {
        t+='#';
        t+=s[i];
    }
    t+='#';
    s=t;
    int r=0,p=0;
    for(int i=0;i<s.size();i++) {
        if(i<=r) tb[i] = min(tb[2*p-i],r-i);
        else tb[i] = 0;
        while(i-tb[i]-1>=0 && i+tb[i]+1<s.size() && s[i-tb[i]-1]==s[i+tb[i]+1]) tb[i]++;
        if (r<i+tb[i]) {
            r=i+tb[i];
            p=i;
        }
    }
    int mx=0;
    for(int i=0;i<s.size();i++){
        if(mx<tb[i])mx=tb[i];
    }
    cout<<mx;
}
