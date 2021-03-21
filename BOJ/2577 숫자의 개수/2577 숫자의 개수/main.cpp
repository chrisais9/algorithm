#include <iostream>
using namespace std;
int tb[10];
int main()
{
    int a,b,c,rst;
    cin>>a>>b>>c;
    rst=a*b*c;
    while(rst>0)
    {
        tb[rst%10]++;
        rst/=10;
    }
    for(int i=0;i<10;i++)cout<<tb[i]<<endl;
}
