#include <iostream>
#include <string>
using namespace std;
int main()
{
    string a;
    cin>>a;
    for(int i=0;i<a.size();i++)cout<<(char)((((a[i]-'A')-3+26)%26)+'A');
}
