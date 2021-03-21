#include <iostream>
#include <queue>
using namespace std;
typedef pair<int,int> ci;
struct in
{
    bool operator() (const ci a,const ci b)
    {
        if(a.second==b.second)return a.first>b.first;
        return a.second>b.second;
    }
};
priority_queue<ci,vector<ci>,in> pq;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        ci temp;
        cin>>temp.first>>temp.second;
        pq.push(temp);
    }
    for(int i=0;i<n;i++)
    {
        cout<<pq.top().first<<" "<<pq.top().second<<"\n";
        pq.pop();
    }
}
