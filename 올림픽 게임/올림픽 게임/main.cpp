#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,d;
struct in
{
    int silver,bronze,num;
    bool operator ()(in a,in b)
    {
        if(a.silver==b.silver)
        {
            if(a.bronze==b.bronze)
            {
                return a.num>b.num;
            }
            return a.bronze<b.bronze;
        }
        return a.silver<b.silver;
    }
}temp;
vector<in> v;
void debug()
{
    for(int i=0;i<v.size();i++)cout<<v[i].num<<" "<<v[i].silver<<" "<<v[i].bronze<<endl;
    cout<<endl;
}
int main()
{
    int i,j,a,b,c,rank=1;
    int fg,fs,fb;
    cin>>n>>d;
    cin>>fg>>fs>>fb;
    fg+=d;
    for(i=2;i<=n;i++)
    {
        int tg;
        cin>>tg>>temp.silver>>temp.bronze;
        temp.num=i;
        if(fg==tg)v.push_back(temp);
        else if(fg<tg)rank++;
    }
    cout<<endl;
    sort(v.begin(),v.end(),in());
    debug();
    int sd=d;
    for(i=0;i<=v.size();i++)
    {
        if(v[i].silver<fs)
        {
            if(sd-(fs-v[i].silver)>=0)v[i].silver+=fs-v[i].silver;
            else
            {
                v[i].silver+=sd;
                break;
            }
        }
    }
    debug();
}
