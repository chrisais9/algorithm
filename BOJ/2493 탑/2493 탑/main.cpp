#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> v,vi;
    int i,n,t;
    cin>>n;
    vi.push_back(0);
    v.push_back(0);
    for(i=1;i<=n;i++)
    {
        cin>>t;
        if(v.back()<t)
        {
            while(1)
            {
                if(v.size()==1||v.back()>t)break;
                v.pop_back();
                vi.pop_back();
            }
            cout<<vi.back()<<" ";
            v.push_back(t);
            vi.push_back(i);
        }
        else
        {
            cout<<vi.back()<<" ";
            v.push_back(t);
            vi.push_back(i);
        }
    }
}

