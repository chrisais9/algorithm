#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("input.txt");
    char a[1000001],state=0;
    int i,one=0,zero=0;
    in>>a;
    for(i=0;a[i];i++)
    {
        if(state!=a[i])
        {
            state=a[i];
            if(state=='1')one++;
            else zero++;
        }
    }
    out<<(one>zero?zero:one);
}

