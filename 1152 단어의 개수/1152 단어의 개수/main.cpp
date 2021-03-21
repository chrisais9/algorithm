#include <iostream>
#include <string>
using namespace std;
int main()
{
    int cnt=0;
    string a;
    getline(cin, a);
    for(int i=0;i<a.size();i++)if(a[i]==' ')cnt++;
    if(a[a.size()-1]==' ')cnt--;
    if(a[0]==' ')cnt--;
    cout<<cnt+1<<endl;
}
