#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string s,b;
    cin>>s>>b;
    for(int i=0;i<b.size();i++)s.erase(remove(s.begin(), s.end(),b[i]), s.end());
    if(s.size()==0)cout<<"FRULA"<<endl;
    else cout<<s;
}
