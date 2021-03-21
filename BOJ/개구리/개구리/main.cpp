#include <iostream>
#include <map>
using namespace std;
multimap<int,int> mx,my,mp;
int n,r,d;
int main()
{
    int i,j,x,y;
    cin>>n>>r;
    for(i=0;i<n;i++)
    {
        cin>>x>>y;
        mx.insert(make_pair(x,y));
        my.insert(make_pair(y,x));
    }
    multimap<int,int>::iterator xit=mx.begin();
    for(i=0;i<mx.size();i++)
    {
        if(mp.empty())mp.insert(*xit++);
        else
        {
            
        }
    }
}
