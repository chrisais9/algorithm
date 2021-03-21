#include <iostream>
#include <queue>
using namespace std;
int main() {
    int n,k;
    queue<int> q;
    cin>>n>>k;
    cout<<"<";
    for(int i=0;i<n;i++) q.push(i+1);
    while(1) {
        for(int i=0;i<k-1;i++) {
            q.push(q.front());
            q.pop();
        }
        cout<<q.front();
        q.pop();
        if(q.empty()) break;
        cout<<", ";
    }
    cout<<">";
}
