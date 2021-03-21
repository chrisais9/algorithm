#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    int i,x,sum=0;
    in>>x;
    for(i=1;i<=9;i++)sum+=i*x;
    out<<sum;
}
