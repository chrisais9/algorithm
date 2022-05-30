#include <stdio.h>
#include <algorithm>
using namespace std;
int x[100],y[100],n,l,m;
int main()
{
    int i,j,k,p,ans=0,tx,ty,c;
    scanf("%d %d %d",&n,&l,&m);
    for(i=0;i<m;i++)scanf("%d %d",&x[i],&y[i]);

    for(i=0;i<m;i++) {
        for(j=i;j<m;j++) {
            for(k=1;k<l/2;k++) {
                c=0;
                tx=min(x[i],x[j]);
                ty=min(y[i],y[j]);
                for(p=0;p<m;p++) {
                    if(x[p]>=tx&&y[p]>=ty&&x[p]<=tx+k&&y[p]<=ty+l/2-k) {
                        c++;
                    }
                }
                ans=max(ans,c);
            }
        }
    }
    printf("%d",ans);
}
