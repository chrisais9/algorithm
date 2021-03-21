#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;
int n,m,vt;
char tb[51][51];
int ar[51][51],br[51][51],ck[700],bi[700];
vector< vector<int> > v(700);
bool f(int so)
{
    if(ck[so]==vt)return false;
    ck[so]=vt;
    for(int i=0;i<v[so].size();i++)
    {
        int si=v[so][i];
        if(!bi[si]||f(bi[si]))
        {
            bi[si]=so;
            return true;
        }
    }
    return false;
}
int main()
{
    int i,j,bi_n=0,tp=0,prtp[700]={0,};
    cin>>n>>m;
    for(i=0;i<n;i++)cin>>tb[i];
    prtp[0]=1;
    for(i=0;i<n;i++)
    {
        if(prtp[tp])tp++;
        for(j=0;j<m;j++)
        {
            if(tb[i][j]=='*')
            {
                prtp[tp]=tp;
                ar[i][j]=tp;
            }
            else if(prtp[tp])tp++;
        }
    }
    bi_n=max(bi_n,tp);
    tp=0;
    memset(prtp,0, sizeof(prtp));
    prtp[0]=1;
    for(i=0;i<m;i++)
    {
        if(prtp[tp])tp++;
        for(j=0;j<n;j++)
        {
            if(tb[j][i]=='*')
            {
                prtp[tp]=tp;
                br[j][i]=tp;
            }
            else if(prtp[tp])tp++;
        }
    }
    bi_n=max(bi_n,tp);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(ar[i][j]!=0)
            {
                v[ar[i][j]].push_back(br[i][j]);
            }
        }
    }
    int ans=0;
    for(i=1;i<=bi_n;i++)
    {
        memset(ck,0,sizeof(ck));
        vt++;
        if(f(i))ans++;
    }
    cout<<ans;
}
