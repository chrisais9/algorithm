#include <stdio.h>
#include <string>

int main()
{
    int i,n,j,t=-1;
    char data[100];
    scanf("%s",data);
    n=strlen(data);

    for(i=0;i<26;i++)
    {
        for(j=0;j<n;j++)
        {
            if(data[j]==i+'a')
            {
                t=j;
                break;

            }
        }
        printf("%d ",t);
        t=-1;
    }


}
