#include <iostream>
using namespace std;
#define AS 100010

int ck[AS];
long long int n,m,k,dap,gp;

void input()
{
    cin>>n>>k;
    gp=1;
    for(m=n;m>0;m/=10)gp*=10;
}

void process()
{
    for(m=n,dap=1;;)
    {
        m=m%k;
        if(m==0)break;
        if(ck[m])
        {
            dap=-1;
            break;
        }
        ck[m]=true;
        m*=gp;
        m+=n;
        dap++;
    }
    cout<<dap;
}
int main()
{
    input();
    process();
    return 0;
}
