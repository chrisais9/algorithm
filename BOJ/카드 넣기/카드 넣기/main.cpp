#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,char> ci;
vector<ci> v;
char best[1010],tb[1010];
int n,bowl[1010],ck[1010],flg;
void f(int d)
{
    int i;
    if(d==n)
    {
        flg=1;
        for(i=0;i<n;i++)best[i]=tb[i];
        return;
    }
    for(i=0;i<v.size();i++)
    {
        if(ck[i]||bowl[d]>v[i].first||best[d]<v[i].second)continue;
        cout<<bowl[d]<<" "<<v[i].first<<endl;
        ck[i]=1;
        tb[d]=v[i].second;
        f(d+1);
        ck[i]=0;
    }
}
struct sortf
{
    bool operator ()(ci x,ci y)
    {
        return x.second<y.second;
    }
};
int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    int i;
    ci temp;
    in>>n;
    for(i=0;i<=n;i++)best[i]='Z';
    for(i=0;i<n;i++)
    {
        in>>temp.first>>temp.second;
        v.push_back(temp);
    }
    for(i=0;i<n;i++)in>>bowl[i];
    sort(v.begin(),v.end(),sortf());
    f(0);
    if(flg)for(i=0;i<n;i++)cout<<best[i];
    else cout<<-1;
    
}
