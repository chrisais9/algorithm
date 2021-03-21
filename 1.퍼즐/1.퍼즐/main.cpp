#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
bool flag;
void f(string t)
{
    int i,j;
    if (flag) return;
    if (t.empty())
    {
        flag=true;
        return;
    }
    for (i=0;i<t.length()&&!flag;i++)
    {
        for (j=i;j<t.length()&&t[i]==t[j];j++);
        if (j-i>=2)
        {
            f(t.substr(0,i)+t.substr(j));
        }
        i=j-1;
    }
}
int main()
{
    int tc;
    cin>>tc;
    while (tc--)
    {
        string s;
        cin>>s;
        flag=false;
        f(s);
        cout<<flag<<endl;
    }
}
