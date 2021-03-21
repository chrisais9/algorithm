#include <iostream>
#include <vector>
#include <string>
using namespace std;
int tb[100010],n;
vector<int> v;
vector<string> way;
int main()
{
    ios::sync_with_stdio(false);
    int i,an=0;
    cin>>n;
    for(i=0;i<n;i++)cin>>tb[i];
    for(i=1;i<=n;i++)
    {
        v.push_back(i);
        way.push_back("+");
        while(!v.empty())
        {
            if(v.back()!=tb[an])break;
            an++;
            v.pop_back();
            way.push_back("-");
        }
    }
    if(!v.empty())cout<<"NO"<<endl;
    else for(i=0;i<way.size();i++)cout<<way[i]<<endl;
}
