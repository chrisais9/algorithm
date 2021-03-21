#include <iostream>
#include <string>
using namespace std;
string s[5];
int n;
int main()
{
    int a,b,c,d,i,ai,bi,ci,di;
    for(i=0;i<4;i++)
    {
        cin>>s[i];
        if(n<s[i].size())n=s[i].size();
    }
    for(a=0;a<n;a++)
    {
        for(ai=0;ai<=n-s[a].size();ai++)
        {
            for(b=0;b<n;b++)
            {
                for(bi=0;bi<n-s[b].size();b++)
                {
                    
                }
            }
        }
    }
    
}
