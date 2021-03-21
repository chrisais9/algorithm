#include <stdio.h>
int tb[1000000]={0,};
int main()
{
    int i,n;
    scanf("%d",&n);
    tb[n]=1;
    for(i=n;i>=1;i--)
    {
        if(tb[i]!=0)
        {
            if(i%2==0)
            {
                if(tb[i/2]==0||tb[i/2]>tb[i]+1)tb[i/2]=tb[i]+1;
            }
            if(i%3==0)
            {
                if(tb[i/3]==0||tb[i/3]>tb[i]+1)tb[i/3]=tb[i]+1;
            }
            if(tb[i-1]==0||tb[i-1]>tb[i]+1)tb[i-1]=tb[i]+1;
        }
    }
    printf("%d",tb[1]-1);
}
