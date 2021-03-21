#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool cmp(string a, string b)
{
    return (a + b).compare(b + a) > 0;
}
int main()
{
    int k, n;
    cin >> k >> n;
    vector<string> v;
    string s, longest = "";
    getline(cin, s);
    while (k--)
    {
        getline(cin, s);
        v.push_back(s);
        if (longest.size() < s.size())
        {
            if (longest.size() == 0) longest = s;
            if (longest.compare(s) > 0) longest = s;
        }
    }
    sort(v.begin(), v.end(), cmp);
    int size = v.size();
    string ans = "";
    for (int i = 0; i < size; ++i) ans += v[i];
    for (int j = n; j > size; --j) ans += longest;
    cout << ans;
}
