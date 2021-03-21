#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int main()
{
    int a,b;
    cin>>a>>b;
    for(int i=0;;i++)
    {
        v.push_back(a%b);
        a/=b;
        if(a==0)break;
    }
    for(int i=v.size()-1;i>=0;i--)
    {
        if(v[i]>=10) cout<<char(v[i]-10+'A');
        else cout<<v[i];
    }
}
