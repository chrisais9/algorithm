#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
vector<int> v;
int n,ck[8001];
int main()
{
    cout<<endl;
    int i,sum=0,cmx=0,ct=0,cidx=-1;
    cin>>n;
    for(i=0;i<n;i++)
    {
        int x,t;
        cin>>x;
        t=x+4000;
        ck[t]++;
        sum+=x;
        if(cmx<ck[t])
        {
            cmx=ck[t];
            cout<<"!"<<cmx<<endl;
            cidx=x;
            ct++;
        }
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    
    double aa;
    aa=(double)sum/v.size();
    aa=floor(aa+0.5);
    cout<<(int)aa<<endl;
    
    cout<<v[v.size()/2]<<endl;
    if(ct==1)cout<<cidx<<endl;
    else
    {
        int flag=0;
        for(i=0;i<=8000;i++)
        {
            if(ck[i]==cmx)
            {
                cout<<"! "<<i<<endl;
                flag=1;
            }
            if(flag==1&&ck[i]==cmx)
            {
                cout<<" "<<i-4000<<endl;
                break;
            }
        }
    }
    cout<<v[v.size()-1]-v[0];
}
