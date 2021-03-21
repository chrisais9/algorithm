#include <iostream>
using namespace std;

int main()
{
    int x1, y1, x2, y2;
    cin>>x1>>y1>>x2>>y2;
    long long int ans=0;
    for( int x = x1; x < x2; ++x )if( x%2 )ans+= (y2 > x ? x : y2) - (y1 > x ? x : y1);
    for( int y = y1; y < y2; ++y )if( y%2 )ans+= (x2 > y ? y : x2) - (x1 > y ? y: x1);
    for( int i = (x1 < y1 ? y1 : x1); i < (x2 > y2 ? y2 : x2); ++i )if( i%2 )ans+= 1;
    cout<<ans<<endl;
}
