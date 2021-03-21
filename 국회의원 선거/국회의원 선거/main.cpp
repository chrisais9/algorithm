#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
int cmp,n;
priority_queue<int,vector<int>,less<int>> pq;
int main()
{
    int i,t,ans=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>t;
        if(i==0)cmp=t;
        else pq.push(t);
    }
    do
    {
        if(pq.top()<cmp)break;
        t=pq.top();
        pq.pop();
        pq.push(t-1);
        cmp++;
        ans++;
    }while(1);
    cout<<ans;
}
