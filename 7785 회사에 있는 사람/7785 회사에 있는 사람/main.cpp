#include <stdio.h>
#include <set>
#include <string>
using namespace std;
int n;
set<string> name;
int main()
{
    int i;
    scanf("%d",&n);
    char t[100],b[100];
    for(i=0;i<n;i++)
    {
        scanf("%s\n%s\n",t,b);
        string a(t);
        if(b[0]=='e')name.insert(a);
        else name.erase(a);
    }
    set<string>::reverse_iterator riter;
    for(riter=name.rbegin();riter!=name.rend();printf("%s\n",(*riter).c_str()));
}
