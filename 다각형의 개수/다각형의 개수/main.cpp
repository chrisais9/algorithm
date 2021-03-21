#include <vector>
#include <cstdio>
#define eps (1.0e-7)
using namespace std;
double abs(double x) {
    return x<0?-x:x;
}
vector<int> x1,y1,x2,y2;
double xx[2500],yy[2500];
int cc[2500];
int p;
int tmp[5000];
int n;
void add(double x, double y){
    for(int i=0; i<p; i++){
        if(abs(xx[i]-x)<eps && abs(yy[i]-y)<eps){
            cc[i]++;
            return;
        }
    }
    xx[p]=x;
    yy[p]=y;
    cc[p]=1;
    p++;
}
int main()
{
    scanf("%d\n",&n);
    for(int i=0; i<n; i++){
        int t1,t2,t3,t4;
        scanf("%d %d %d %d\n",&t1,&t2,&t3,&t4);
        x1.push_back(t1);
        y1.push_back(t2);
        x2.push_back(t3);
        y2.push_back(t4);
    }
    int f;
    double a,b,c;
    p=0;
    f=n+1;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){

            b = (y1[i]-y1[j]) * (double)(x2[j]-x1[j]) - (x1[i]-x1[j]) * (double)(y2[j]-y1[j]);
            c = (x2[i]-x1[i]) * (double)(y2[j]-y1[j]) - (y2[i]-y1[i]) * (double)(x2[j]-x1[j]);
            if(abs(c) > eps){
                a = b/c;
                add(x1[i] + (x2[i]-x1[i]) * a, y1[i] + (y2[i]-y1[i]) * a);
            }
        }
    }
    for(int i=2; i<=50; i++)
        tmp[i*(i-1)/2]=i-1;
    for (int i=0; i<p; i++)
        f += tmp[cc[i]];
    printf("%d\n",max((f-n*2),0));
    return 0;
}

