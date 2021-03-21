#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
typedef pair<int,int> ci;
ci m_ver;
vector<ci> v,data;
int n;
double ccw(ci a,ci b,ci c)
{
    return (a.first*b.second+b.first*c.second+c.first*a.second)-(a.second*b.first+b.second*c.first+c.second*a.first);
}
double g_angle(ci a,ci b)
{
    return (a.first - b.first) / sqrt(pow(a.first-b.first, 2.0) + pow(a.second-b.second, 2.0));
}
bool acmp(ci a,ci b)
{
    double ta=g_angle(a,m_ver);
    double tb=g_angle(b,m_ver);
    if(ta==tb)return a.second<b.second;
    return ta<tb;
}
int dist(ci a,ci b)
{
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}
int main()
{
    int i,j,T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        v.clear();
        data.clear();
        for(i=0;i<n;i++)
        {
            int x,y,w;
            cin>>x>>y>>w;
            data.push_back(make_pair(x,y));
            data.push_back(make_pair(x+w,y));
            data.push_back(make_pair(x,y+w));
            data.push_back(make_pair(x+w,y+w));
        }
        
        sort(data.begin(),data.end());
        data.erase(unique(data.begin(),data.end()),data.end());
        m_ver=data[0];
        sort(data.begin()+1,data.end());
        v.push_back(data[0]);
        v.push_back(data[1]);
        for(i=2;i<data.size();i++)
        {
            while (v.size()>=2)
            {
                ci c=data[i];
                ci b=v.back();
                v.pop_back();
                ci a=v.back();
                if(ccw(a,b,c)>0)
                {
                    v.push_back(b);
                    break;
                }
            }
            v.push_back(data[i]);
        }
        int ans=0;
        for(i=0;i<v.size();i++)
        {
            for(j=i+1;j<v.size();j++)
            {
                ans=max(ans,dist(v[i],v[j]));
            }
        }
        cout<<ans<<endl;
    }
}
