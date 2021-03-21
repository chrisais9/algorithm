#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int x,y,w,h,t;
    cin>>w>>h>>x>>y>>t;
    cout<<w-abs(w-(x+t)%(2*w))<<" "<<h-abs(h-(y+t)%(2*h));
}
