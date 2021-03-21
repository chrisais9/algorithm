#include <iostream>
#include <vector>
using namespace std;
typedef pair<int,int> ci;
vector <ci> ve;
ci start;
int way[5],lgo[5]={-1,4,3,1,2},rgo[5]={-1,3,4,2,1};
inline int fabs(int x)
{
    return x>0?x:x*-1;
}
int lf(int t)
{
    int sum=0,x,flag=1;
    ci e,temp;
    temp=start;
    x=temp.first;
    e=ve[t];
    if(x==e.first)return fabs(temp.second-e.second);
    if(x==2||x==3)sum+=temp.second;
    else if(x==4)sum+=way[4]-temp.second;
    else sum+=way[1]-temp.second;
    do
    {
        if(x==e.first)
        {
            if(x==1||x==4)sum+=e.second;
            else if(x==2)sum+=way[2]-e.second;
            else sum+=way[3]-e.second;
            break;
        }
        if(flag==0) sum+=way[x];
        x=lgo[x];
        flag=0;
    }while(1);
    return sum;
}
int rf(int t)
{
    int sum=0,x,flag=1;
    ci e,temp;
    temp=start;
    x=temp.first;
    e=ve[t];
    if(x==e.first)return fabs(temp.second-e.second);
    if(x==1||x==4)sum+=temp.second;
    else if(x==3)sum+=way[3]-temp.second;
    else sum+=way[2]-temp.second;
    do
    {
        if(x==e.first)
        {
            if(x==2||x==3)sum+=e.second;
            else if(x==1)sum+=way[1]-e.second;
            else sum+=way[4]-e.second;
            break;
        }
        if(flag==0) sum+=way[x];
        x=rgo[x];
        flag=0;
    }while(1);
    return sum;
}
int main()
{
    int i,n,m,k,ans=0;
    ci temp;
    cin >> n >> m >> k;
    for(i=0;i<k;i++)
    {
        cin >> temp.first >> temp.second;
        ve.push_back(temp);
    }
    cin >> start.first >> start.second;
    way[1]=way[2]=n;
    way[3]=way[4]=m;
    for(i=0;i<k;i++)ans+=min(lf(i),rf(i));
    cout << ans;
}
