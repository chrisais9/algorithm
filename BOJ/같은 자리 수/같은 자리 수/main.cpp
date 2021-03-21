#include <iostream>
using namespace std;
bool f(long long int x)
{
    int ck[10]={0,};
    while(x>0)
    {
        ck[x%10]++;
        x/=10;
    }
    int flag=-1;
    for(int i=0;i<10;i++)
    {
        if(ck[i]==0)continue;
        if(flag==-1)flag=ck[i];
        if(ck[i]!=flag)return false;
    }
    return true;
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int t,n;
    cin>>n;
    for(n;;n++)
    {
        if(f(n))
        {
            cout<<n<<endl;
            return 0;
        }
    }
}
