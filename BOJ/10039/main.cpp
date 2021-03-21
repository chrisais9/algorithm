#include <stdio.h>
int main()
{
    int i,t,sum=0;
    for(i=0;i<5;i++)
    {
        scanf("%d",&t);
        if(t<40)t=40;
        sum+=t;
    }
    printf("%d",sum/5);
}
