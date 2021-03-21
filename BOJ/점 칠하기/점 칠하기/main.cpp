#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int gcd(int x, int y)
{
    int z;
    while(1)
    {
        z = y;
        y = x%y;
        x = z;
        if(y==0)
            return x;
    }
}
int a[400];
vector<int> extract(int start, int k)
{
    vector<int> t;
    int i = start;
    do
    {
        i = (i+k)%360;
        t.push_back(a[i]);
    }while(i!=start);
    return t;
}
int solve(vector<int> t)
{
    int ans = 0;
    for(int i=0; i<t.size();){
        if(t[i]==0)
        {
            i++;
            continue;
        }
        i++;
        if(i==t.size()) break;
        if(t[i]==0)
        {
            i++;
            continue;
        }
        i++;
        ans+=2;
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int t;
        cin>>t;
        a[t] = 1;
    }
    int ans = 0;
    for(int k=1; k<360; k++)
    {
        int g = gcd(k,360);
        int sum = 0;
        for(int i=0; i<g; i++)
        {
            vector<int> t1 = extract(i,k);
            vector<int> t2 = t1;
            t2.push_back(t2[0]);
            t2.erase(t2.begin());
            sum += max(solve(t1),solve(t2));
        }
        ans= max(ans,sum);
    }
    cout<<ans;
    return 0;
}
