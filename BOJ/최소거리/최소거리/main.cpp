#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#define INF 987654321
using namespace std;
typedef pair<int,int> ci;
vector<ci> v;
int n;
int main()
{
    int i,j;
    cin>>n;
    for(i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }
    sort(v.begin(),v.end());
    int ucli=INF,manh=INF,cheb=INF;
    for(i=1;i<v.size();i++)
    {
        ucli=min(ucli,(v[i].first-v[i-1].first)*(v[i].first-v[i-1].first)+(v[i].second-v[i-1].second)*(v[i].second-v[i-1].second));
        manh=min(manh,abs(v[i].first-v[i-1].first)+abs(v[i].second-v[i-1].second));
        cheb=min(cheb,max(abs(v[i].first-v[i-1].first),abs(v[i].second-v[i-1].second)));
    }
    cout<<ucli<<" "<<manh<<" "<<cheb<<endl;
}
