#include <iostream>
#include <string>
using namespace std;
char tb[21][21];
int m,cnt;
string s;
int main()
{
    int x=0;
    cin>>m>>s;
    for(int i=0;;i++)
    {
        for(int j=0;j<m;j++)tb[x][j]=s[cnt++];
        if(cnt>=s.size())break;
        x++;
        for(int j=m-1;j>=0;j--)tb[x][j]=s[cnt++];
        if(cnt>=s.size())break;
        x++;
    }
    for(int i=0;i<m;i++)for(int j=0;j<s.size()/m;j++)cout<<tb[j][i];
}
