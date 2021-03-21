#include <iostream>
using namespace std;
int tb[101][101],n;
void draw(int sx,int sy,int ex,int ey)
{
    for(int i=sx;i<ex;i++)
    {
        for(int j=sy;j<ey;j++)
        {
            tb[i][j]=1;
        }
    }
}
int main()
{
    int i,j;
    for(i=0;i<4;i++)
    {
        int sx,sy,ex,ey;
        cin>>sx>>sy>>ex>>ey;
        draw(sx,sy,ex,ey);
    }
    int ans=0;
    for(i=0;i<=100;i++)for(j=0;j<=100;j++)if(tb[i][j])ans++;
    cout<<ans;
}
