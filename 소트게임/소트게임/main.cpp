#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>
using namespace std;
typedef pair<string,int> ci;
queue<ci> q;
set<string> visited;
int main()
{
    int i,n,k;
    cin>>n>>k;
    string tb,an;
    for (i=0;i<n;i++)cin>>tb[i];
    an=tb;
    sort(an.begin(),an.end());
    q.push(make_pair(tb,0));
    visited.insert(tb);
    int flag = 0;
    while (!q.empty())
    {
        ci temp=q.front();
        q.pop();
        string cur = temp.first;
        int cnt=temp.second;
        if (cur==an)
        {
            flag=1;
            cout << cnt << endl;
            break;
        }
        for (int i = 0; i <= cur.size()-k; i++)
        {
            string temp = cur;
            reverse(temp.begin()+i,temp.begin()+i+k);
            if (!visited.count(temp))
            {
                visited.insert(temp);
                q.push(make_pair(temp,cnt+1));
            }
        }
    }
    if(!flag) cout<<-1<<endl;
}
