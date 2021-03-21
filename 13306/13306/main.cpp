#include <stdio.h>

int tb[200001],n,q;
int con(int u)
{
    if(tb[u]==-1)return -1;
    if(tb[u]==u)return u;
    return con(tb[u]);
}
int main()
{
    int i,x,a,b,c;
    scanf("%d %d",&n,&q);
    tb[1]=-2;
    for(i=2;i<=n;i++)scanf("%d",&tb[i]);
    c=0;
    while(1)
    {
        scanf("%d",&x);
        if(x==1)
        {
            scanf("%d %d",&a,&b);
            if(con(a)==con(b))printf("YES\n");
            else printf("NO\n");
            c++;
            if(c==q)break;
        }
        else
        {
            scanf("%d",&a);
            tb[a]=-1;
        }
    }
}
