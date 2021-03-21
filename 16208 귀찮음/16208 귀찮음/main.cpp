#include <iostream>
#include <queue>
using namespace std;
int n;
priority_queue<int> pq;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        pq.push(-x);
    }
    long long int ans=0;
    while(pq.size()>1)
    {
        
        int a=-pq.top();
        pq.pop();
        int b=-pq.top();
        pq.pop();
        ans+=a*b;
        pq.push(-(a+b));
    }
    cout<<ans;
}
