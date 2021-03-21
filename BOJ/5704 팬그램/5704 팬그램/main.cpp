#include <iostream>
#include <string>
using namespace std;
int main()
{
    while (1)
    {
        int ans=0;
        int ck[30]={0,};
        string x;
        getline(cin,x);
        if(!x.compare("*"))return 0;
        for(int i=0;i<x.size();i++)
        {
            if(x[i] != ' ')
            {
                if(!ck[x[i]-'a'])ans++;
                ck[x[i]-'a']++;
            }
        }
        if(ans == 26)cout<<"Y"<<endl;
        else cout<<"N"<<endl;
    }
}
