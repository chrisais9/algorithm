#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<string,int> ci;
vector<ci> data;
vector<int> ans;
string query;
int n,sr,er;
int f(int tsr,int ter,int pos,int c)
{
    int flag=-1;
    for(int i=tsr;i<ter;i++)
    {
        if(data[i].first[pos]==c)
        {
            if(flag==-1)sr=i;
            if(pos==data[i].first.size()-1)
            {
                flag=data[i].second;
                break;
            }
            flag=0;
        }
        if(flag!=-1&&data[i].first[pos]!=c)
        {
            er=i;
            break;
        }
    }
    return flag;
}
int main()
{
    int i;
    cin>>query>>n;
    for(i=0;i<n;i++)
    {
        string t;
        cin>>t;
        data.push_back(make_pair(t,i+1));
    }
    sort(data.begin(),data.end());
    sr=0;
    er=n;
    int pos=0,x;
    for(i=0;i<query.size();i++)
    {
        x=f(sr,er,pos,query[i]);
        if(x>0)
        {
            sr=0;
            er=n;
            pos=0;
            ans.push_back(x);
        }
        else if(x==-1)
        {
            sr=0;
            er=n;
            pos=0;
            ans.push_back(0);
        }
        else
        {
            pos++;
        }
    }
    if(x==0)ans.push_back(0);
    cout<<ans.size()<<endl;
    for(i=0;i<ans.size();i++)cout<<ans[i]<<endl;
}

