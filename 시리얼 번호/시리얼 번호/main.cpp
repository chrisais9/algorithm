#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<string> v;
int n;
int fc(string x)
{
    int sum=0;
    for(int i=0;i<x.length();i++)
    {
        if(x[i]-'0'<=9)sum+=x[i]-'0';
    }
    return sum;
}
struct sortf
{
    bool operator () (string x,string y)
    {
        if(x.length()!=y.length())return x.length()<y.length();
        else
        {
            int xn=fc(x);
            int yn=fc(y);
            if(xn!=yn)return xn<yn;
            else return x<y;
        }
    };
};
int main()
{
    string temp;
    int i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end(),sortf());
    for(i=0;i<v.size();i++)cout<<v[i]<<endl;
}

