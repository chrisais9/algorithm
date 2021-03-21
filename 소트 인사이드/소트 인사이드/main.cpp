#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    int i,j;
    string s;
    in>>s;
    for(i=0;i<s.size()-1;i++)for(j=i+1;j<s.size();j++)if(s[i]<s[j])swap(s[i],s[j]);
    out<<s;
}
