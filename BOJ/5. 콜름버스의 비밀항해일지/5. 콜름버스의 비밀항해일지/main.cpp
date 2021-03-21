#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main ()
{
    int T;
    cin>>T;
    while (T--)
    {
        string s;
        cin>>s;
        int u[30]={0,},cnt[30]={0,};
        for (int i=0; i<26; i++)
        {
            if (!u[i])
            {
                int j=i,n=0;
                do
                {
                    u[j]=1;
                    j=s.find('A'+j);
                    n++;
                }while (j!=i);
                cnt[n]++;
            }
        }
        int ok=1;
        for (int i=0; i<=26; i++)if(i%2==0 && cnt[i]%2!=0)ok=0;
        if (ok) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}

