#include <stdio.h>
int tb[41],a[41];
int main()
{
    int i;
    tb[1]=1;
    for(i=2;~scanf("%1d",&a[i]);i++)
    {
        if(a[i])tb[i]+=tb[i-1];
        if(a[i]+a[i-1]*10>=10&&a[i]+a[i-1]*10<=34)tb[i]+=tb[i-2];
    }
    printf("%d",tb[i-1]);
}
