#include <iostream>
#include <algorithm>
using namespace std;
int n,data[301];
int tb[301];
int main()
{
    int i;
    cin >> n;
    for (i = 0; i < n; i++)cin>>data[i];
    tb[0] = data[0];
    tb[1] = max(data[0]+data[1],data[1]);
    tb[2] = max(data[0]+data[2],data[1]+data[2]);
    for (i = 3; i < n; i++)tb[i]=max(tb[i-2]+data[i],data[i-1]+data[i]+tb[i-3]);
    cout<<tb[n-1]<<endl;
}
