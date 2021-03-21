#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef pair<int,string> ci;
int N;
vector<ci> v;
bool cmp(ci a, ci b)
{
    if (a.first < b.first) return true;
    else if (a.first == b.first) return false;
    return false;
}
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; i++) cin >> v[i].first >> v[i].second;
    stable_sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++) cout << v[i].first << " " << v[i].second << "\n";
}
