#include <iostream>
#include <string>
using namespace std;
int main()
{
    int T;
    cin>>T;
    for(int k=0;k<T;k++)
    {
        int a;
        string x;
        cin>>a>>x;
        for(int i=0;i<x.size();i++)
        {
            for(int j=0;j<a;j++)cout<<x[i];
        }
        cout<<endl;
    }
}
