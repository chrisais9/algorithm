#include <iostream>
#include <vector>
using namespace std;
int n,m;
char map[101][101];
class tower
{
    vector< pair<int,int> > one,two,three,four;
public:
    void make_blow()
    {
        
    }
}
int main()
{
    int i,j;
    cin>>n>>m;
    for(i=0;i<n;i++)cin>>map[i];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)cout<<map[i][j]<<" ";
        cout<<endl;
    }
}
