#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct opdata
{
    string name;
    int op,rA_flag,C_flag;
}
vector<opdata> dic;
int main()
{
    dic.push_back({"ADD",00000,-1,0});
    dic.push_back({"ADDC",00001,-1,1});
    
    dic.push_back({"SUB",00010,0,0});
    dic.push_back({"SUBC",00011,-1,1});
    
    dic.push_back({"MOV",00000,-1,0});
    
    dic.push_back(make_pair("MOV",00100));
    dic.push_back(make_pair("MOVC",00101));
    
    dic.push_back(make_pair("AND",00110));
    dic.push_back(make_pair("ANDC",00111));
    
    dic.push_back(make_pair("OR",01000));
    dic.push_back(make_pair("ORC",01001));
    
    dic.push_back(make_pair("NOT",00001));
    cout<<dic.size()<<endl;
}
