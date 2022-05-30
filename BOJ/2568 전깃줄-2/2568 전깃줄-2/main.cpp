#include <stdio.h>
#include <algorithm>
struct cc
{
    int a, b;
} aa[1200000];
int sortf(cc x, cc y)
{
    if(x.a<y.a) return 1;
    else return 0;
}
int a[1200000], b[1200000], c[1200000], d[1200000];
int i, l, r, max, t, n, x, dab, s, k;
int main()
{
    scanf("%d", &n);
    t=524288;
    for(i=t; i<t+n; i++)scanf("%d %d", &aa[i].a, &aa[i].b);
    std::sort(aa+t, aa+t+n, sortf);
    for(i=t; i<t+n; i++)
    {
        x=aa[i].b;
        l=t;
        r=t+x-1;
        max=1;
        s=-1;
        while(1)
        {
            if(l==r)
            {
                if(a[l]>=max)
                {
                    max=a[l];
                    s=b[l];
                }
                break;
            }
            if(l&1)
            {
                if(a[l]>=max)
                {
                    max=a[l];
                    s=b[l];
                }
                l++;
            }
            if(!(r&1))
            {
                if(a[r]>=max)
                {
                    max=a[r];
                    s=b[r];
                }
                r--;
            }
            if(l>r)
            {
                if(a[l]>=max)
                {
                    max=a[l];
                    s=b[l];
                }
                if(a[r]>=max)
                {
                    max=a[r];
                    s=b[r];
                }
                break;
            }
            l>>=1;
            r>>=1;
        }
        l=t+x-1;
        c[i]=s;

        while(1)
        {
            if(max+1>=a[l])
            {
                a[l]=max+1;
                b[l]=i;
            }
            else break;
            l>>=1;
            if(l==0) break;
        }

        if(a[t+x-1]>=dab)
        {
            dab=a[t+x-1];
            k=i;
        }
    }

    while(1)
    {
        if(k<1) break;
        d[k]=1;
        k=c[k];
    }

    printf("%d\n", n-dab+1);
    for(i=t; i<t+n; i++)
    {
        if(d[i]==0)
            printf("%d\n", aa[i].a);
    }
    return 0;
}
