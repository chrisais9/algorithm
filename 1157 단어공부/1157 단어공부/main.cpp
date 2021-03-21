#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;
int tb[200];
int main()
{
    string s;
    char a;
    int i,mx=0;
    cin>>s;
    for(i=0;i<s.size();i++)
    {
        if(isupper(s[i]))tb[s[i]-'A']++;
        else if(islower(s[i]))tb[s[i]-'a']++;
    }
    for(i=0;i<26;i++)
    {
        if(tb[i]>mx)
        {
            a=i+'A';
            mx=tb[i];
        }
    }
    int cnt=0;
    for(i=0;i<26;i++)if(tb[i]==mx)cnt++;
    if(cnt>=2)
    {
        cout<<'?'<<endl;
        return 0;
    }
    cout<<a<<endl;
}
