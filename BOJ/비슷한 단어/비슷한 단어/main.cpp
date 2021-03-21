#include <iostream>
#include <string>
using namespace std;
int n,k,ans;
string s[101];

int main()
{
    int i,j,a,b;
    cin>>n;
    for(i=0;i<n;i++)cin>>s[i];
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
        int t1[27]={0},t2[27]={0};
        for(k=0;k<s[i].length();k++)
        {
            a=s[i][k]-'a'+ 1;
            b=s[j][k]-'a'+ 1;
            if(t1[a]==0&&t2[b]==0)
            {
                t1[a] = b;
                t2[b] = a;
            }
            else if (t1[a] != b) break;
        }
        if (k >= s[i].length()) ans++;
        }
        cout<<endl;
    }
    cout << ans;
}
