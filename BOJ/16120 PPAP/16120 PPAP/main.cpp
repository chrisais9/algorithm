#include <iostream>
using namespace std;
string tb,inp;
int x;
bool is_ppap()
{
    if(x<4)return false;
    if(inp[x-1]=='P'&&inp[x-2]=='A'&&inp[x-3]=='P'&&inp[x-4]=='P')
        return true;
    return false;
}

int main()
{
    cin>>inp;
    for(int i=0;i<inp.size();i++)
    {
        tb[x++]=inp[i];
        cout<<i<<" "<<x<<" "<<inp[x-4]<<" "<<inp[x-3]<<" "<<inp[x-2]<<" "<<inp[x-1]<<endl;
        while (is_ppap())
        {
            cout<<"ok"<<endl;
            x-=4;
            tb[x++]='P';
        }
    }
    if(x==1&&tb[0]=='P')cout<<"PPAP"<<endl;
    else cout<<"NP"<<endl;
}
