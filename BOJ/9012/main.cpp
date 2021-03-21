#include <stdio.h>
#include <string.h>

int main()
{
    int i,j,n,an,cnt;
    char a[100];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        cnt=0;
        scanf("%s",a);
        an=strlen(a);
        for(j=0;j<an;j++)
        {
            if(a[j]=='(')cnt++;
            else cnt--;
        }
        if(cnt!=0)printf("NO\n");
        else printf("YES\n");
    }

}

