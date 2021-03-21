#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
struct aa
{
    int h,m,s;
}data;
vector<int> p;
vector<aa> v;
bool ik(int h,int m,int s)
{
    for(int i=0;i<v.size();i++)
    {
        if(v[i].h==h&&v[i].m==m&&v[i].s==s)return false;
    }
    return true;
}
int main()
{
    string t;
    cin>>t;
    p.push_back((t[0]-'0')*10+(t[1]-'0'));
    p.push_back((t[3]-'0')*10+(t[4]-'0'));
    p.push_back((t[6]-'0')*10+(t[7]-'0'));
    sort(p.begin(), p.end());
    do
    {
        cout<<p[0]<<" "<<p[1]<<" "<<p[2]<<endl;
        if(p[0]>=1&&p[0]<=12&&p[1]>=0&&p[1]<=59&&p[2]>=0&&p[2]<=59)
        {
            if(ik(p[0],p[1],p[2]))
            {
                data.h=p[0];
                data.m=p[1];
                data.s=p[2];
                v.push_back(data);
            }
        }
    }while(next_permutation(p.begin(), p.end()));
    cout<<v.size();
}
