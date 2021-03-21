#include <iostream>
using namespace std;
int ans;
int main()
{
    int s,e,g,t,flag=0;
    cin>>g;
    s=e=1;
    while(s <= e)
    {
        t=e*e-s*s;
        if(s+1==e&&g<t) break;
        if(g<=t) s++;
        else e++;
        if(t==g)
        {
            cout<<e;
            flag=1;
        }
    }
    if(!flag)cout<<-1;
}
