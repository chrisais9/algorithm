#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int n;
vector<pair<int, int>> v;
vector<int> list;
bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
    if(a.first != b.first) return a.first < b.first;
    return a.second > b.second;
}
int main()
{
    cin>>n;
    int t, left, right;
    for(int i=0; i<n; i++)
    {
        cin>>t>>left>>right;
        v.push_back(make_pair(left, right));
    }
    sort(v.begin(), v.end(), compare);
    
    list.push_back(-v[0].second);
    int rear = 0;
    for(int i=1; i<n; i++)
    {
        if(v[i-1].first == v[i].first && v[i-1].second == v[i].second) continue;
        
        if(-list[rear] >= v[i].second)
        {
            list.push_back(-v[i].second);
            rear++;
        }
        else
        {
            long idx = upper_bound(list.begin(), list.end(), -v[i].second) - list.begin();
            list[idx] = -v[i].second;
        }
    }
    cout<<rear+1;
}
