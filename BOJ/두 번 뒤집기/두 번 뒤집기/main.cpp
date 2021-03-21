#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int arr[10001];
int tmp[10001];
vector <pair<int, int>> res;
void turn(int start, int finish)
{
    int tmp = 0;
    for (int i = start, j = 0; i <= (start + finish)/ 2; i++, j++)
    {
        tmp = arr[i];
        arr[i] = arr[finish - j];
        arr[finish - j] = tmp;
    }
}
bool check()
{
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] != i)  return false;
    }
    return true;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        tmp[i] = arr[i];
    }
    int cnt = 0, start = 0, finish = 0;
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] != i)
        {
            start = i;
            for (int j = i; j <= n; j++)
            {
                if (arr[j] == start)
                {
                    finish = j; break;
                }
            }
        }
        if (start != 0)
        {
            cnt++;
            turn(start, finish);
            res.push_back(make_pair(start, finish));
            start = 0; finish = 0;
        }
        if (check() == true && res.size() > 0)
        {
            if (res.size() == 1) cout <<"1 1"<< endl;
            for (auto i : res) cout << i.first << " " << i.second << endl;
            return 0;
        }
        if (cnt == 2) break;
    }
    start = 0; finish = 0; cnt = 0;
    res.clear();
    for (int i = 1; i <= n; i++) arr[i] = tmp[i];
    for (int i = n; i >= 1; i--)
    {
        if (arr[i] != i)
        {
            finish = i;
            for (int j = 1; j <= n; j++)
            {
                if (arr[j] == finish)
                {
                    start = j; break;
                }
            }
        }
        if (finish != 0)
        {
            cnt++;
            turn(start, finish);
            res.push_back(make_pair(start, finish));
            start = 0; finish = 0;
        }
        if (check() == true && res.size() > 0)
        {
            if (res.size() == 1) cout <<"1 1"<< endl;
            for (auto i : res) cout << i.first << " " << i.second << endl;
            return 0;
        }
    }
    if (cnt == 0)cout <<"1 1"<<endl<<"1 1"<<endl;
}
