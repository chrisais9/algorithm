#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string inp,ori;
    cin>>n;
    while(n--)
    {
        int m,W=0,B=0;
        cin>>m;
        cin>>inp>>ori;
        for(int i=0;i<inp.size();i++)
        {
            if(inp[i]=='W'&&ori[i]=='B')B++;
            else if(inp[i]=='B'&&ori[i]=='W')W++;
        }
        cout<<min(B,W)+abs(B-W)<<endl;
    }
}
