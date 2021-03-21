#include<iostream>
using namespace std;
int n, m;
string str;
void perm(int a)
{
    if (str.size() == m)
    {
        for (int i = 0; i < str.size(); i++)
            cout << (str[i] - '0') << ' ';
        cout << '\n';
        return;
    }
    for (int i = a; i <= n; i++)
    {
        str += (i + '0');
        perm(i+1);
        str.pop_back();
    }
}
int main()
{
    cin >> n >> m;
    perm(1);
    return 0;
}
