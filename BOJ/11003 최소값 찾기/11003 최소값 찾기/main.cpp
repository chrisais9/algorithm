#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int arr[5000003];
vector<int> vc;

int main()
{
    int n, l;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>l;
    deque <int> dq;
    for (int i = 1; i <= n; i++)
    {
        cin>>arr[i];
        if (dq.empty())dq.push_back(arr[i]);
        else
        {
            while (!dq.empty() && dq.back() > arr[i]) dq.pop_back();
            dq.push_back(arr[i]);
        }
        if (i > l&&dq.front() == arr[i - l]) dq.pop_front();
        vc.push_back(dq.front());
    }
    for (int i = 0; i < n; i++)cout<<vc[i]<<" ";
}
