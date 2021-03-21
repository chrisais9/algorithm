#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
map<string, bool> ck;
int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        string s;
        cin >> s;
        sort(begin(s), end(s));
        ck[s] = 1;
    }
    cout << ck.size();
}
