#include<cstdio>
int a, b, c, d, e, f, r;
int main()
{
    scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
    r = d + e + f;
    a -= 11 * e;
    b -= 5 * d;
    if (c)
    {
        r += (c - 1) / 4 + 1;
        c %= 4;
    }
    if (c)
    {
        a -= 8 - c;
        b -= 7 - 2 * c;
    }
    if (b>0) {
        r += (b - 1) / 9 + 1;
        a -= 36 - b % 9 * 4;
    }
    else a += b * 4;
    if (a>0) r += (a - 1) / 36 + 1;
    printf("%d", r);
    return 0;
}
