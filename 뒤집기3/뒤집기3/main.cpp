#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s;
int main()
{
    int i,j;
    cin>>s;
    sort(s.begin(),s.end());
    cout<<s;
}

