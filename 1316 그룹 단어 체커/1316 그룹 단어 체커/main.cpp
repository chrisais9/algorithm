#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n;
vector<int> v;
int main()
{
    int i,j,ans=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        int flag=1;
        v.assign(30, 0);
        string x;
        cin>>x;
        for(j=0;j<x.size();j++)
        {
            if(!v[x[j]-'a'])v[x[j]-'a']=1;
            else if(v[x[j]-'a']&&j!=0&&x[j]!=x[j-1])
            {
                flag=0;
                break;
            }
        }
        if(flag)ans++;
    }
    cout<<ans;
}
