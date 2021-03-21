#include <iostream>
#include <string>
using namespace std;
int main()
{
    int combo,T,score;
    string a;
    cin>>T;
    while(T--)
    {
        combo=0;
        score=0;
        cin>>a;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]=='X')combo=0;
            else combo++;
            score+=combo;
        }
        cout<<score<<endl;
    }
}
