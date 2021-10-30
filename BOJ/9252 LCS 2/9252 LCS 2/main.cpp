#include <iostream>
#include <algorithm>
using namespace std;
 
int tb[1010][1010];
char a[1010],b[1010];
 
void f(int i,int j){
    if(!tb[i][j])return;
    if(a[i-1]==b[j-1]){
        f(i-1, j-1);
        cout<<a[i-1];
    } else {
        tb[i-1][j]>tb[i][j-1]?f(i-1,j):f(i,j-1);
    }
}
 
int main(){
    cin>>a>>b;
    int i,j=0;
    for(i=0;a[i];++i){
        for(j=0;b[j];++j) {
            if(a[i]==b[j])tb[i+1][j+1]=tb[i][j]+1;
            else tb[i+1][j+1]=max(tb[i][j+1],tb[i+1][j]);
        }
    }
    cout<<tb[i][j]<<'\n';
    f(i,j);
}
