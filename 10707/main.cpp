#include <stdio.h>

int main()
{
    int xa,ya,yl,yp,u,i,xu,yu,l;

    scanf("%d %d %d %d %d",&xa,&ya,&yl,&yp,&u);
    xu=xa*u;
    yu=ya;
    if(u>yl)
    {
        l=u-yl;
        yu=yu+l*yp;
    }
    if(xu>yu)printf("%d",yu);
    else printf("%d",xu);
}
