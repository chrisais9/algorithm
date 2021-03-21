#include <iostream>
#include <vector>
#include <string>
using namespace std;
int n;
vector<int> v;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string x;
        cin>>x;
        if(!x.compare("push"))
        {
            int t;
            cin>>t;
            v.push_back(t);
        }
        else if(!x.compare("pop"))
        {
            if(!v.empty())
            {
                cout<<v.back()<<endl;
                v.pop_back();
            }
            else cout<<-1<<endl;
        }
        else if(!x.compare("size"))cout<<v.size()<<endl;
        else if(!x.compare("empty"))cout<<v.empty()<<endl;
        else if(!x.compare("top"))
        {
            if(!v.empty())cout<<v.back()<<endl;
            else cout<<-1<<endl;
        }
    }
}
