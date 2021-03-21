#include <stdio.h>
#include <math.h>
int N,R,D;
int E_x,E_y;
struct reversi{
    int x,y;
}data[110];
int check[110];
long long int map[110][110];
double res;

int main(void){
    scanf("%d %d %d %d %d",&N,&R,&D,&E_x,&E_y);
    int i,j,k;
    for(i=1;i<=N;i++)
    {
        scanf("%d %d",&data[i].x,&data[i].y);
        if( (double)sqrt((double)((data[i].x-E_x)*(data[i].x-E_x)+(data[i].y-E_y)*(data[i].y-E_y))) <= R){
            check[i]=1;
            res+=D;
        }
    }
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=N;j++) map[i][j]=0xfffffff;
    }
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=N;j++)
        {
            if(i==j) continue;
            else if( (double)sqrt((double)((data[i].x-data[j].x)*(data[i].x-data[j].x) + (data[i].y-data[j].y)*(data[i].y-data[j].y))) <= R){
                map[i][j]=1;
            }
        }
    }
    for(k=1;k<=N;k++)
    {
        for(i=1;i<=N;i++)
        {
            for(j=1;j<=N;j++)
            {
                if(map[i][k] + map[k][j] < map[i][j]){
                    map[i][j]=map[i][k] + map[k][j];
                }
            }
        }
    }
    int min;
    double asdf;
    for(i=1;i<=N;i++)
    {
        if(check[i]==1) continue;
        min=0xfffffff;
        for(j=1;j<=N;j++)
        {
            if(map[i][j]<min && check[j]==1) min=map[i][j];
        }
        if(min == 0xfffffff) continue;
        asdf=D;
        for(j=1;j<=min;j++) asdf/=2;
        res+=asdf;
    }
    printf("%.2lf",res);
    return 0;
}

