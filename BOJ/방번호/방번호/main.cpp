#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string num;
int su[10]={0,};
int main()
{
    int i;
    cin>>num;
    for(i=0;i<num.size();i++)
    {
        if(num[i]=='6'||num[i]=='9')su[6]++;
        else su[num[i]-'0']++;
    }
    if(su[6]%2==0)su[6]/=2;
    else
    {
        su[6]/=2;
        su[6]++;
    }
    cout<<*max_element(su,su+9);
}
