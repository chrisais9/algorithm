#include <iostream>
#include <string>
using namespace std;
int main()
{
    int ans=0;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==',')ans++;
    }
    cout<<ans+1;
}
