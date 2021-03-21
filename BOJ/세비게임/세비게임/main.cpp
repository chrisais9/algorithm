#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct data
{
    int tb[6];
    double sebi_po,sebist_po,st_po,f_po;
};
vector<data> v;
int sebi_score,sebist_score,st_score,f_score;
int dice[6],ts,cp[6];
int is_sebi()
{
    int i;
    for(i=1;i<5;i++)if(dice[i-1]!=dice[i])
    {
        cout<<dice[i-1]<<" "<<dice[i]<<endl;
        return 0;
    }
    return 1;
}
int is_sebist()
{
    int i,t[6];
    for(i=0;i<5;i++)t[i]=dice[i];
    sort(t,t+5);
    for(i=1;i<5;i++)if(t[i]!=t[i-1]+1)return 0;
    return 1;
}
int is_st()
{
    int i,t[6],flag1=1,flag2=1;
    for(i=0;i<5;i++)t[i]=dice[i];
    sort(t,t+5);
    for(i=1;i<5;i++)if(t[i]!=t[i-1]+1&&t[i]!=t[i-1])flag1=0;
    for(i=2;i<5;i++)if(t[i]!=t[i-1]+1)flag2=0;
    if(flag1|flag2)return 1;
    return 0;
}
int is_f()
{
    int i,t[6];
    for(i=0;i<5;i++)t[i]=dice[i];
    sort(t,t+5);
    if(t[0]==t[1]&&t[1]==t[2]&&t[3]==t[4])return 1;
    if(t[2]==t[3]&&t[3]==t[4]&&t[0]==t[1])return 1;
    return 0;
}
int is_dif(int a,int b,int c,int d,int e)
{
    int cnt=0;
    if(a!=dice[0])cnt++;
    if(b!=dice[1])cnt++;
    if(c!=dice[2])cnt++;
    if(d!=dice[3])cnt++;
    if(e!=dice[4])cnt++;
    return cnt;
}
int score()
{
    
    return max(max(is_sebi()*sebi_score,is_sebist()*sebist_score),max(is_st()*st_score,is_f()*f_score));
}
void fd()
{
    int i,j,ck,flag=0;
    for(i=0;i<v.size();i++)
    {
        ck=1;
        for(j=0;j<5;j++)
        {
            if(tb[j]!=cp[j])
            {
                ck=0;
                break;
            }
        }
        if(ck)
        {
            flag=1;
            
        }
    }
    
}
int main()
{
    int i,j,k,l,m;
    int ans[6],mi=0x7fffffff;
    //cin>>sebi_score>>sebist_score>>st_score>>f_score;
    for(i=0;i<5;i++)cin>>dice[i];
    cout<<is_sebi()<<endl<<is_sebist()<<endl<<is_st();
    for(i=1;i<=6;i++)
    {
        for(j=1;j<=6;j++)
        {
            for(k=1;k<=6;k++)
            {
                for(l=1;l<=6;l++)
                {
                    for(m=1;m<=6;m++)
                    {
                        if(is_dif(i,j,k,l,m)>=2)
                        {
                            if(i!=dice[0])cp[0]=1;
                            if(j!=dice[1])cp[1]=1;
                            if(k!=dice[2])cp[2]=1;
                            if(l!=dice[3])cp[3]=1;
                            if(m!=dice[4])cp[4]=1;
                        }
                    }
                }
            }
        }
    }
}
