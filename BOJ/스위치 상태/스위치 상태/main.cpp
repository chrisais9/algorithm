#include <iostream>
using namespace std;
bool tb[101];
int m,n;
void boy(int x)
{
    for(int i=x;i<=n;i+=x)tb[i]^=1;
}
void girl(int x)
{
    int p1=x,p2=x;
    tb[x]^=1;
    do
    {
        p1--;
        p2++;
        if(p1<1||p2>n||tb[p1]!=tb[p2])break;
        tb[p1]^=1;
        tb[p2]^=1;
    }while(1);
}
int main()
{
    int i;
    cin>>n;
    for(i=1;i<=n;i++)cin>>tb[i];
    cin>>m;
    for(i=0;i<m;i++)
    {
        int gen,t;
        cin>>gen>>t;
        if(gen==1)boy(t);
        else girl(t);
    }
    for(i=0;i<n;i++)cout<<tb[i]<<" ";
}
