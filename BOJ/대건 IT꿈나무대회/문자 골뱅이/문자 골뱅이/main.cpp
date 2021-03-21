#include <iostream>
#include <fstream>
using namespace std;
int mx;
int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    int tb[110][110];
    int i,x=0,y=-1,d=1,p,cnt=0,jmx;
    in>>p;
    mx=p;
    jmx=mx;
    while(0<=jmx)
    {
        for(i=0;i<jmx;i++)
        {
            y=y+d;
            tb[x][y]=cnt;
            cnt++;
        }
        jmx--;
        for(i=0;i<jmx;i++)
        {
            x=x+d;
            tb[x][y]=cnt;
            cnt++;
        }
        
        d=d*-1;
    }
    for(x=0;x<mx;x++)
    {
        for(y=0;y<mx;y++)
        {
            out<<(char)((tb[x][y]%26)+'A')<<" ";
        }
        out<<endl;
    }
}
