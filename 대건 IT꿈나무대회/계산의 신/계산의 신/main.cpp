#include <iostream>
#define NUM_R 30
using namespace std;
int num,flag=0;
long double ans;
long double mysqrt(int src)
{
    unsigned int k;
    long double t;
    long double buf = (long double)src;
    for(k=0,t=buf;k<NUM_R;k++)
    {
        if(t<1.0)break;
        t = (t*t+buf)/(2.0*t);
    }
    return t;
}
int main()
{
    cin>>num;
    if(mysqrt(num)<0.00000000005)printf("%.10Lf",mysqrt(num));
    else printf("%.10Lf",mysqrt(num)-0.0000000001);
}

