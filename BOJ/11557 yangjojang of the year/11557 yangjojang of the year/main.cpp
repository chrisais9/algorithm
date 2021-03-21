#include <iostream>
#include <string>
using namespace std;
int main()
{
    int T;
    cin>>T;
    for(int k=0;k<T;k++)
    {
        int n,mx=-1,t;
        cin>>n;
        string ans;
        for(int i=0;i<n;i++)
        {
            string x;
            cin>>x>>t;
            if(mx<t)
            {
                mx=t;
                ans=x;
            }
        }
        cout<<ans<<endl;
    }
}
