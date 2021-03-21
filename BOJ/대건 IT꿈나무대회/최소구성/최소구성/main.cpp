#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;
int cnt=0,flag=0;
void f(int x)
{
    if(flag)return;
    if(x==0)
    {
        flag=1;
        return;
    }
    int t=sqrt(x);
    cnt++;
    f(x-t*t);
}
int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    int x;
    in>>x;
    f(x);
    out<<cnt;
}
