#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> dic;
int n,mx=0,ans_idx;
int ck[1010];
bool is_ok(string ned,string hay)
{
    int cnt=0,tn=0;
    for(int i=0;i<hay.size();i++)
    {
        if(ned[tn]==hay[i])
        {
            cnt++;
            tn++;
        }
    }
    if(cnt==ned.size())return true;
    else return false;
}
void f(int x,int d)
{
    if(d>mx)
    {
        ans_idx=x;
        mx=d;
    }
    for(int i=0;i<dic.size();i++)
    {
        if(ck[i]==0&&dic[i].size()-dic[x].size()==1&&is_ok(dic[x],dic[i]))
        {
            ck[i]=1;
            f(i,d+1);
            ck[i]=0;
        }
    }
}
int main()
{
    int i;
    string orig;
    cin>>n>>orig;
    dic.push_back(orig);
    for(i=0;i<n ;i++)
    {
        string t;
        cin>>t;
        dic.push_back(t);
    }
    f(0,0);
    cout<<dic[ans_idx];
}
