#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int isasc()
{
    for(int i=1;i<=8;i++)if(v[i-1]!=i)return 0;
    return 1;
}
int isdesc()
{
    for(int i=8;i>=1;i--)if(v[8-i]!=i)return 0;
    return 1;
}
int main()
{
    for(int i=0;i<8;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    if(isasc())
    {
        cout<<"ascending"<<endl;
        return 0;
    }
    if(isdesc())
    {
        cout<<"descending"<<endl;
        return 0;
    }
    cout<<"mixed"<<endl;
}
