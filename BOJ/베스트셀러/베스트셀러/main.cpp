#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n;
struct dictionary
{
    string s;
    int cnt;
    bool operator ()(dictionary x,dictionary y)
    {
        return x.s<y.s;
    }
}temp;
vector<dictionary> v;
void fd(string t)
{
    for(int i=0;i<v.size();i++)
    {
        if(v[i].s.compare(t)==0)
        {
            v[i].cnt++;
            return;
        }
    }
    temp.s=t;
    temp.cnt=1;
    v.push_back(temp);
}
int main()
{
    int i,mx=0;
    string t;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>t;
        fd(t);
    }
    sort(v.begin(), v.end(), dictionary());
    for(i=0;i<v.size();i++)if(mx<v[i].cnt)mx=v[i].cnt,t=v[i].s;
    cout<<t;
}
