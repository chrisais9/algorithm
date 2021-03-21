#include <iostream>
using namespace std;
int n,m;
int tb[110][110];
int cheeseCnt;
void meltCheese()
{
    // 1,1 부터 입력 받게 수정
    // planesweep 4방향
    int ck[110][110]={0,};
    int flag=0;
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(tb[i][j-1]&&!tb[i][j])ck[i][j-1]=1;
        }
        for(int j=m-1;j>=0;j--)
        {
            if(tb[i][)
        }
    }
    for(int j=0;j<m;j++)
    {
        for(int i=1;i<n;i++)
        {
            if(tb[i-1][j]&&!tb[i][j])ck[i-1][j]=1;
            if(!tb[i-1][j]&&tb[i][j])ck[i][j]=1;
        }
    }
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)
    {
        if(tb[i][j]&ck[i][j])
        {
            cheeseCnt--;
            tb[i][j]=0;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<ck[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<tb[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>tb[i][j];
            if(tb[i][j])cheeseCnt++;
        }
    }
    int ans=0,prev=-1;
    while (cheeseCnt>0)
    {
        ans++;
        prev=cheeseCnt;
        meltCheese();
    }
    cout<<ans<<endl<<prev<<endl;
    

}
