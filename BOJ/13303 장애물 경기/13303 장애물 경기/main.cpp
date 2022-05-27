#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
struct lin
{
    int x,y1,y2;
    bool operator<(const lin& c)const
    {
        return x<c.x;
    }
}ba[101010];
struct st
{
    int y,val;
    bool operator<(const st& c)const
    {
        return y<c.y;
    }
}sim;
set<st> sets;
set<st>::iterator it;
int n,sy,tx;
int main()
{
    int i;
    cin>>n>>sy>>tx;
    for(i=0;i<n;i++)
        cin>>ba[i].x>>ba[i].y1>>ba[i].y2;
    sort(ba,ba+n);
    sim={sy,0};
    sets.insert(sim);
    for(i=0;i<n;i++)
    {
        st im;
        int lmin=(int)1e9;
        int rmin=(int)1e9;
        sim={ba[i].y1,0};
        it=sets.lower_bound(sim);
        if(it==sets.end())continue;
        vector<int> v;
        for(;it!=sets.end();it++)
        {
            im=*it;
            if(im.y>ba[i].y2)break;
            v.push_back(im.y);
            if(im.y<ba[i].y2)lmin=min(lmin,im.val+im.y-ba[i].y1);
            if(im.y>ba[i].y1)rmin=min(rmin,im.val+ba[i].y2-im.y);
        }
        for(unsigned int j=0;j<v.size();j++) {
            sim={v[j],0};
            sets.erase(sim);
        }
        if(lmin<(int)1e9) {
            sim={ba[i].y1,lmin};
            sets.insert(sim);
        }
        if(rmin<(int)1e9) {
            sim={ba[i].y2,rmin};
            sets.insert(sim);
        }
    }
    int ans=(int)1e9;
    for(it=sets.begin();it!=sets.end();it++)if(ans>(*it).val)ans=(*it).val;
    printf("%d\n",ans+tx);
    vector<int> v;
    for(it=sets.begin();it!=sets.end();it++)if(ans==(*it).val)v.push_back((*it).y);
    cout<<v.size()<<" ";
    for(i=0;i<v.size();i++)cout<<v[i]<<" ";
}
