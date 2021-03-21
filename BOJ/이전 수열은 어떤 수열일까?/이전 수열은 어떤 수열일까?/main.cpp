#include <iostream>
#include <vector>
using namespace std;
int n,flag=0;
int ori[50010];
int tb[50010];
int ck[50010];
void f(int d)
{
    if(flag)return;
    if(d==n)
    {
        flag=1;
        for(int i=0;i<n;i++)cout<<tb[i]<<" ";
        cout<<endl;
        return;
    }
    for(int i=ori[d]-1;i<=ori[d]+1;i++)
    {
        if(i<=0||i>n)continue;
        if(ck[i]==0)
        {
            ck[i]=1;
            tb[d]=i;
            f(d+1);
            tb[d]=-1;
            ck[i]=0;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int i;
    cin>>n;
    for(i=0;i<n;i++)cin>>ori[i];
    cout<<endl;
    f(0);
}
