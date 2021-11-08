#include <iostream>
#include <string>
#include <vector>
using namespace std;
int pi[1000010],tb[1000010];
vector<int> ans;
int main(){
    string s, p;
    getline(cin, s);
    getline(cin, p);
    
    for(int i=1,j=0;i<p.size();i++){
        while(j>0 && p[i]!=p[j]) j=pi[j-1];
        if(p[i] == p[j]) {
            j++;
            pi[i]=j;
        }
    }
    
    for(int i=0,j=0;i<s.size();i++){
        while(j>0 && s[i]!=p[j]) j=pi[j-1];
        if(s[i] == p[j]){
            if(j==p.size()-1){
                ans.push_back(i-p.size()+1);
                j = pi[j];
            } else {
                j++;
            }
        }
    }
    
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]+1<<" ";
    }
}
