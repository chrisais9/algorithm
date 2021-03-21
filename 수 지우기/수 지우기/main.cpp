#include <iostream>
#include <string>
using namespace std;
char a[1001], b[1001];
bool check[1001];
int num[10][3],p;
int main()
{
    int i,j,flag;
    cin>>a>>b;
    for (int i = 0; a[i]; i++) num[a[i] - '0'][0]++;
    for (int i = 0; b[i]; i++) num[b[i] - '0'][1]++;
    for (int i = 0; i < 10; i++) num[i][2] = num[i][0] - num[i][1];
    
    for (; a[p];p++)
    {
        int x = p;
        for (i = 9; i>=0; i--)
        {
            flag=0;
            int del[10] = { 0, };
            while (!num[i][2]) i--;
            for (; a[x]; x++)
            {
                if (a[x] - '0' == i) break;
                del[a[x] - '0']++;
            }
            for (j = 0; j < 10; j++) if (num[j][1] < del[j]) flag=1;
            if (flag)
            {
                x = p;
                continue;
            }
            else
            {
                for (j = 0; j < 10; j++) num[j][1] -= del[j];
                p = x;
                num[a[x]-'0'][2]--;
                check[x] = true;
                break;
            }
        }
    }
    
    for (i = 0; a[i]; i++) if(check[i]) cout<<a[i];
}
