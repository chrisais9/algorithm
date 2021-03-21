#include <iostream>
#include <string>
using namespace std;
string s[101];
int tb[101];
int n,m;
int main()
{
    int i,j,s_len=0;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        cin>>s[i];
        s_len+=s[i].size();
    }
    int t=(m-s_len)/(n-1);
    for(i=0;i<n-1;i++)tb[i]=t;
    t=(m-s_len)%(n-1);
    if(t>0)
    {
        for(i=1;i<n;i++)
        {
            if(islower(s[i][0]))
            {
                tb[i-1]++;
                t--;
                if(t==0)break;
            }
        }
    }
    do
    {
        if(t==0)break;
        for(i=n-2;i>=0;i--)
        {
            tb[i]++;
            t--;
            if(t==0)break;
        }
    }while(1);
    for(i=0;i<n;i++)
    {
        if(i!=0)for(j=0;j<tb[i-1];j++)cout<<"_";
        cout<<s[i];
    }

}
