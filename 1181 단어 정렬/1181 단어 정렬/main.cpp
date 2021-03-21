#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<string> s;
bool cmp(string a,string b)
{
    if(a.size()==b.size())return a<b;
    else return a.size()<b.size();
}
int main()
{
    int i;
    string t;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>t;
        s.push_back(t);
    }
    sort(s.begin(),s.end(),cmp);
    for(i=0;i<s.size();i++)
    {
        if(i!=0&&s[i]==s[i-1])continue;
        cout<<s[i]<<endl;
    }
}
