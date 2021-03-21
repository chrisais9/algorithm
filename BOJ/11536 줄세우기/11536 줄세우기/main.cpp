#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> v,t;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string x;
        cin>>x;
        v.push_back(x);
    }
    t=v;
    sort(t.begin(),t.end());
    int flag=1;
    for(int i=0;i<v.size();i++)
    {
        cout<<v.size()-i-1<<" "<<i<<endl;
        if(!v[v.size()-i-1].compare(t[i]))
        {
            flag=0;
            break;
        }
    }
    if(!flag)
    {
        flag=1;
        for(int i=0;i<v.size();i++)
        {
            if(v[v.size()-i-1].compare(t[i]))
            {
                cout<<v[1]<<" "<<t[1];
                flag=0;
                break;
            }
        }
        if(!flag) cout<<"DECREASING";
        else cout<<"NEITHER";
    }
    else cout<<"INCREASING";
}

