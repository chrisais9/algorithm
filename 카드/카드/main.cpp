#include<stdio.h>

int n;
int chk[1000];
int cnt;
int ans1,ans2;

void back(int i)
{
    if(i>n)
    {
        int l1,l2;
        cnt=0;
        for(l1=1;l1<=n;l1++)
        {
            if(chk[l1]==0)
                continue;
            cnt++;
            for(l2=l1+1;l2<=n;l2++)
            {
                if(chk[l2]==0)
                    continue;
                if(l1+l2<=n)
                    if(chk[l1+l2])
                        return ;
            }
        }
        if(ans1==cnt)
        {
            for(l1=1;l1<=n;l1++)
                if(chk[l1])
                    printf("%d ",l1);
            printf("\n");
        }
        return ;
    }
    chk[i]=1;
    back(i+1);
    chk[i]=0;
    back(i+1);
}

int main()
{
    int l1;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&n);
    ans1=(n>>1)+1;
    if(n==1)
        ans2=1;
    else if(n==2)
        ans2=1;
    else if(n==3)
        ans2=3;
    else if(n==4)
        ans2=2;
    else if(n==5)
        ans2=6;
    else if(n==6)
        ans2=1;
    else if(n==7)
        ans2=6;
    else if(n==8)
        ans2=1;
    else if(n==9)
        ans2=5;
    else if((n&1))
        ans2=4;
    else
        ans2=1;
    printf("%d %d\n",ans1,ans2);
    if(n<=9)
        back(1);
    else
    {
        if((n&1))
        {
            for(l1=1;l1<=n;l1+=2)
                printf("%d ",l1);
            printf("\n");
            for(l1=n-ans1;l1<n;l1++)
                printf("%d ",l1);
            printf("\n");
            printf("%d ",n-ans1);
            for(l1=n-ans1+2;l1<=n;l1++)
                printf("%d ",l1);
            printf("\n");
        }
        for(l1=n-ans1+1;l1<=n;l1++)
            printf("%d ",l1);
        printf("\n");
    }
    return 0;
}
