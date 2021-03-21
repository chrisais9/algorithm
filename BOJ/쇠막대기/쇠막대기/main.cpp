#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    int i,sum=0,cnt=0,sw=0;
    cin>>s;
    for(i=0;i<s.size();i++)
    {
        if(s[i]=='(')
        {
            cnt++;
            sw=1;
        }
        else
        {
            cnt--;
            if(sw==1)
            {
                cout<<"*";
                sum++;
            }
            else
            {
                sum+=cnt;
                cout<<"%";
            }
            sw=0;
        }
        cout<<cnt<<"("<<sum<<") ";
    }
    cout<<endl;
    cout<<sum;
}
