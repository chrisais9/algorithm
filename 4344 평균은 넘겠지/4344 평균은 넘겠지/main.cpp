#include <iostream>
#include <vector>
using namespace std;
int C;
int main()
{
    cin>>C;
    while(C--)
    {
        int n,sum=0;
        double ave;
        cin>>n;
        int v[1001];
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            sum+=x;
            v[i]=x;
        }
        ave=sum/(double)n;
        int cnt=0;
        for(int i=0;i<n;i++)if(v[i]>ave)cnt++;
        printf("%.3f%%\n",(double)cnt*100/n);
    };
}
