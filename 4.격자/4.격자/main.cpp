#include <iostream>
#include <vector>
#define MAX_N 20
using namespace std;
int n;
int tb[MAX_N][MAX_N],visit[MAX_N][MAX_N];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
struct tms
{
    int ck[MAX_N][MAX_N]={0,};
};

class side_class
{
protected:
    vector<tms> tm;
public:
    void debug()
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<tm.back().ck[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    void ini()
    {
        tms temp;
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)
        {
            temp.ck[i][j]=tb[i][j];
        }
        tm.push_back(temp);
    }
    bool check(int ax,int ay,int bx,int by)
    {
        tms temp=tm.back();
        if(ax>bx||ay>by)
        {
            swap(ax,bx);
            swap(ay,by);
        }
        bool aflag=false,bflag=false;
        if(ax!=bx)
        {
            if(ay-1>=0)
            {
                if(temp.ck[ax][ay-1]-1<0)return false;
                else
                {
                    temp.ck[ax][ay-1]--;
                    aflag=true;
                }
            }
            else aflag=true;
            if(ay<n)
            {
                if(temp.ck[ax][ay]-1<0)return false;
                else
                {
                    temp.ck[ax][ay]--;
                    bflag=true;
                }
            }
            else bflag=true;
            if(aflag && bflag)
            {
                tm.push_back(temp);
                return true;
            }
            else
            {
                if(aflag)temp.ck[ax][ay-1]++;
                if(bflag)temp.ck[ax][by]++;
                return false;
            }
        }
        else
        {
            if(ax-1>=0)
            {
                if(temp.ck[ax-1][ay]-1<0)return false;
                else
                {
                    temp.ck[ax-1][ay]--;
                    aflag=true;
                }
            }
            else aflag=true;
            if(ax<n)
            {
                if(temp.ck[ax][ay]-1<0)return false;
                else
                {
                    temp.ck[ax][ay]--;
                    bflag=true;
                }
            }
            else bflag=true;
            if(aflag && bflag)
            {
                tm.push_back(temp);
                return true;
            }
            else
            {
                if(aflag)temp.ck[ax-1][ay]++;
                if(bflag)temp.ck[ax][by]++;
                return false;
            }
        }
    }
    void un_check(int ax,int ay,int bx,int by)
    {
        tm.pop_back();
    }
    bool ok()
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(tm.back().ck[i][j])return false;
            }
        }
        return true;
    }
}side;
int flag=0;
void rec(int x,int y)
{
    if(flag)return;
    for(int i=0;i<4;i++)
    {
        if(x+dx[i]<0||x+dx[i]>n||y+dy[i]<0||y+dy[i]>n)continue;
        if(visit[x+dx[i]][y+dy[i]]&&side.ok())
        {
            cout<<"!!"<<endl;
            flag=1;
            return;
        }
        if(visit[x+dx[i]][y+dy[i]]==0)
        {
            if(side.check(x,y,x+dx[i],y+dy[i]))
            {
                cout<<x<<" "<<y<<"->"<<x+dx[i]<<" "<<y+dy[i]<<endl;
                side.debug();
                visit[x+dx[i]][y+dy[i]]=1;
                rec(x+dx[i],y+dy[i]);
                side.un_check(x,y,x+dx[i],y+dy[i]);
                visit[x+dx[i]][y+dy[i]]=0;
            }
        }
    }
}
int main()
{
    int i,j;
    cin>>n;
    for(i=0;i<n;i++)for(j=0;j<n;j++)cin>>tb[i][j];
    side.ini();
    side.debug();
    rec(0,1);
}
