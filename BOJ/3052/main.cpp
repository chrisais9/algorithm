#include <stdio.h>
#include <algorithm>

int main()
{
    int i,j,a[11],t,cnt=0;
    for(i=0;i<10;i++)
    {
        scanf("%d",&t);
        a[i]=t%42;
    }
    std::sort(a,a+10);
    for(i=0;i<9;i++)if(a[i]!=a[i+1])cnt++;
    printf("%d",cnt+1);

}
