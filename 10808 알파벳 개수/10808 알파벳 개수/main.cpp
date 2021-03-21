#include <iostream>
#include <string>
using namespace std;
int a[30];
int  main()
{
    string x;
    cin>>x;
    for(int i=0;i<x.size();i++)a[x[i]-'a']++;
    for(int i=0;i<26;i++)cout<<a[i]<<" ";
}
