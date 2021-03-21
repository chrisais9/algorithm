#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> v;
int main()
{
    int sum=0, prev=0, t;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if(x==0)
        {
            t=-v.back();
            v.pop_back();
        }
        else
        {
            t=x;
            v.push_back(t);
        }
        sum+=t;
    }
    cout<<sum;
}
