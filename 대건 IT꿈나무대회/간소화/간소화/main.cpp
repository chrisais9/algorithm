#include <iostream>
#include <math.h>
using namespace std;
int num,flag=0;
long double ans;
void f(long double x,int dec)
{
    int i,t=1;
    if(flag)return;
    if(dec>=12||x*x==ans)
    {
        flag=1;
        ans=x;
        return;
    }
    if(x*x>num)return;
    printf("%.15Lf\n",x);
    for(i=0;i<dec;i++)t*=10;
    for(i=9;i>=0;i--)
    {
        f(x+((long double)i/t),dec+1);
    }
}
long double ini()
{
    int i;
    for(i=1;i<=num;i++)
    {
        if(i*i>num)break;
    }
    return i-1;
}
int main()
{
    cin>>num;
    f(ini(),1);
    printf("%.10Lf",ans);
}
