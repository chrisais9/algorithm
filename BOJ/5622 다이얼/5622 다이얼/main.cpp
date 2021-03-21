#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef pair<string,int> ci;
vector<ci> dial;
string inp;
int main()
{
    dial.push_back({"ABC",2});
    dial.push_back({"DEF",3});
    dial.push_back({"GHI",4});
    dial.push_back({"JKL",5});
    dial.push_back({"MNO",6});
    dial.push_back({"PQRS",7});
    dial.push_back({"TUV",8});
    dial.push_back({"WXYZ",9});
    cin>>inp;
    int sm=0;
    for(int i=0;i<inp.size();i++) for(int j=0;j<dial.size();j++)for(int k=0;k<dial.size();k++)if(inp[i]==dial[j].first[k])sm+=dial[j].second+1;
    cout<<sm<<endl;
}
