#include <iostream>
#include <string>
using namespace std;
typedef unsigned long long int lld;
string mas;
bool check(lld x)
{
    for(int i=0;i<mas.size();i++)
    {
        if(mas[i]=='0'||mas[i]=='1')continue;
        if(x==197834650456)cout<<x%(mas[i]-'0')<<endl;
        if(x%(mas[i]-'0'))
        {
            cout<<mas[i]<<endl;
            return false;
        }
    }
    return true;
}
lld toint(string s)
{
    lld x=0;
    int t=1;
    for(int i=s.size()-1;i>=0;i--)
    {
        x+=t*(s[i]-'0');
        t*=10;
    }
    return x;
}
int main()
{
    cin>>mas;
    /*
    for(int i=0;i<=9;i++)
    {
        string t=mas;
        t+=(char)(i+'0');
        if(check(toint(t)))
        {
            cout<<t;
            return 0;
        }
    }
    for(int i=0;i<=9;i++)
    {
        for(int j=0;j<=9;j++)
        {
            string t=mas;
            t.push_back((char)(i+'0'));
            t.push_back((char)(j+'0'));
            
            if(check(toint(t)))
            {
                cout<<t;
                return 0;
            }
            
        }
    }
    for(int i=0;i<=9;i++)
    {
        for(int j=0;j<=9;j++)
        {
            for(int k=0;k<=9;k++)
            {
                string t=mas;
                t.push_back((char)(i+'0'));
                t.push_back((char)(j+'0'));
                t.push_back((char)(k+'0'));
                if(check(toint(t)))
                {
                    cout<<1<<endl;
                    cout<<t;
                    return 0;
                }
            }
        }
    }
    */
    for(int i=0;i<=9;i++)
    {
        for(int j=0;j<=9;j++)
        {
            for(int k=0;k<=9;k++)
            {
                for(int l=0;l<=9;l++)
                {
                    string t=mas;
                    t.push_back((char)(i+'0'));
                    t.push_back((char)(j+'0'));
                    t.push_back((char)(k+'0'));
                    t.push_back((char)(l+'0'));
                    cout<<t<<endl;
                    if(check(toint(t)))
                    {
                        cout<<t;
                        return 0;
                    }
                }
            }
        }
    }
    
    
}

