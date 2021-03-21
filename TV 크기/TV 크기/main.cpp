#include <iostream>
#include <math.h>
using namespace std;
double h,w,d,r;
int main()
{
    cin>>d>>h>>w;
    r=sqrt(h*h+w*w);
    cout<<(int)(d*h/r)<<" "<<(int)(d*w/r)<<endl;
}
