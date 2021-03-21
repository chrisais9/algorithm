#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
set<string> s;
vector<string> inp,ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int K, t;
    cin>>K>>t;
    for (int i = 0; i < t; ++i)
    {
        string str;
        cin >> str;
        ans.push_back(str);
    }
    for(int i=t-1;i>=0;--i)
    {
        string str = ans[i];
        if (s.find(str) == s.end())
        {
            s.insert(str);
            inp.push_back(str);
        }
    }
    int siz = inp.size();
    for (int i = siz-1; i >=siz-K && i>=0; --i) cout << inp[i] << endl;
}
