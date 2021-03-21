#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int n;
int main()
{
    int i,x;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x;
        v.push_back(x);
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    do
    {
        int ck[11]={0,};
        for(i=0;i<v.size();i++)
        {
            if(ck[i]==0)
            {
                if(v[i+1+v[i]]==v[i])ck[i]=ck[i+1+v[i]]=1;
                else break;
            }
        }
        if(i==v.size())
        {
            for(i=0;i<v.size();i++)cout<<v[i]<<" ";
            cout<<endl;
            return 0;
        }
    }while(next_permutation(v.begin(), v.end()));
    cout<<-1;
}
