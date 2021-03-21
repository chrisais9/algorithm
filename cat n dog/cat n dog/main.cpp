#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int c,d,n,T,vt;
int ck[510],bi[510];
pair<string,string> data[510];
vector< vector<int> > V;
bool bm(int so)
{
    if(ck[so])return false;
    ck[so]=1;
    for(int i=0;i<V[so].size();i++)
    {
        int si=V[so][i];
        if(!bi[si]||bm(bi[si]))
        {
            bi[si]=so;
            return true;
        }
    }
    return true;
}
int main()
{
    int i,j,ans,g;
    cin>>g;
    while(g--)
    {
        cin>>c>>d>>n;
        V.clear();
        V.resize(n+1);
        for(i=1;i<=n;i++)
        {
            string t1,t2;
            cin>>t1>>t2;
            data[i]=make_pair(t1,t2);
        }
        for(i=1;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                if(data[i].first==data[j].second||data[i].second==data[j].first)
                {
                    if(data[i].first[0]=='C')V[i].push_back(j);
                    else V[j].push_back(i);
                }
            }
        }
        ans=0;
        memset(bi,0,sizeof(bi));
        for(i=1;i<=n;i++)
        {
            memset(ck,0,sizeof(ck));
            if(bm(i))ans++;
        }
        cout<<n-ans;
    }
}
