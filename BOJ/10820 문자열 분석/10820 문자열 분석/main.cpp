#include<iostream>
#include<string>
using namespace std;

string str;
int up,dn,num,sp;
int main() {
    while (getline(cin, str, '\n'))
    {
        up=0,dn=0,num=0,sp=0;
        for (int i=0;i<str.size();++i)
        {
            if (str[i] >= 65 && str[i] <= 90) up++;
            else if (str[i] >= 97 && str[i] <= 122) dn++;
            else if (str[i] == ' ')sp++;
            else num++;
        }
        cout<<dn<<" "<<up<<" "<<num<<" "<<sp<<endl;
    }
}
