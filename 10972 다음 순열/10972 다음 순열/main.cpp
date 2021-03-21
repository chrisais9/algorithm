#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> v;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    
    if(!next_permutation(v.begin(), v.end()))cout<<-1<<endl;
    else for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
}
