#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> ci;
vector<ci> v;
int n;
int change(int c,int x)
{
    if(c==1)return x;
    if(c==2)return 300000-x;
    if(c==3)return 500000-x;
    if(c==4)return 100000+x;
    return -1;
}
bool iscross(ci a,ci b)
{
    return (a.first<=b.first&&b.first<=a.second)^(a.first<=b.second&&b.second<=a.second);
}
int main()
{
    int i,j;
    cin>>n;
    for(i=0;i<n/2;i++)
    {
        int c1,x1,c2,x2,m1,m2;
        cin>>c1>>x1>>c2>>x2;
        m1=change(c1,x1);
        m2=change(c2,x2);
        v.push_back(make_pair(min(m1,m2),max(m1,m2)));
    }
    int mx=0,mi=0;
    for(i=0;i<n/2;i++)
    {
        int cross=0,cross2=0;
        for(j=i+1;j<n/2;j++)if(iscross(v[i],v[j]))cross2++;
        for(j=0;j<n/2;j++)
        {
            if(i==j)continue;
            if(iscross(v[i],v[j]))cross++;
        }
        mx=max(mx,cross);
        mi+=cross2;
    }
    cout<<mi<<endl<<mx<<endl;
}
