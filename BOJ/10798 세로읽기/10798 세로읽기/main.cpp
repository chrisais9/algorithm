#include <iostream>
#include <string>
using namespace std;
int main()
{
    int i,j,mx=0;
    string s[5];
    for(i=0;i<5;i++)
    {
        cin>>s[i];
        if(mx<s[i].size())mx=s[i].size();
    }
    for(i=0;i<mx;i++)
    {
        for(j=0;j<5;j++)
        {
            if(s[j].size()>i)cout<<s[j][i];
        }
    }
    
}
