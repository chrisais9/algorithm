#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
int n,m,ck[10][10],pck[10][10];
struct data
{
    char tb[8][8];
    int time,x,y;
}temp;
queue<data> q;
int main()
{
    data t1,t2;
    int i,j;
    cin>>n>>m;
    for(i=0;i<n;i++)for(j=0;j<m;j++)cin>>temp.tb[i][j];
    temp.time=0;
    temp.x=0;
    temp.y=0;
    q.push(temp);
    while(!q.empty())
    {
        t1=q.front();
        q.pop();
        pck[t1.x][t1.y]++;
        if(t1.tb[t1.x][t1.y]=='A')
        {
            if(t1.x+1<n&&t1.tb[t1.x+1][t1.y]!='B'&&pck[t1.x+1][t1.y]>3)
            {
                t2=t1;
                t2.x=t1.x+1;
                t2.time++;
                if(t2.x==n-1&&t2.y==m-1)
                {
                    cout<<t2.time;
                    return 0;
                }
                q.push(t2);
            }
            if(t1.y+1<m&&t1.tb[t1.x][t1.y+1]!='B'&&pck[t1.x][t1.y+1]>3)
            {
                t2=t1;
                t2.y=t1.y+1;
                t2.time++;
                if(t2.x==n-1&&t2.y==m-1)
                {
                    cout<<t2.time;
                    return 0;
                }
                q.push(t2);
            }
            if(t1.y-1>=0&&t1.tb[t1.x][t1.y-1]!='B'&&pck[t1.x][t1.y-1]>3)
            {
                t2=t1;
                t2.y=t1.y-1;
                t2.time++;
                if(t2.x==n-1&&t2.y==m-1)
                {
                    cout<<t2.time;
                    return 0;
                }
                q.push(t2);
            }
            if(t1.x-1>=0&&t1.tb[t1.x-1][t1.y]!='B'&&pck[t1.x-1][t1.y]>3)
            {
                t2=t1;
                t2.x=t1.x-1;
                t2.time++;
                if(t2.x==n-1&&t2.y==m-1)
                {
                    cout<<t2.time;
                    return 0;
                }
                q.push(t2);
                
            }
            if(ck[t1.x][t1.y]<3)
            {
                ck[t1.x][t1.y]++;
                t2=t1;
                for(i=0;i<n;i++)
                {
                    if(t2.tb[i][t2.y]=='C')t2.tb[i][t2.y]='D';
                    else if(t2.tb[i][t2.y]=='D')t2.tb[i][t2.y]='C';
                }
                for(i=0;i<m;i++)
                {
                    if(t2.tb[t2.x][i]=='C')t2.tb[t2.x][i]='D';
                    else if(t2.tb[t2.x][i]=='D')t2.tb[t2.x][i]='C';
                }
                t2.time++;
                q.push(t2);
            }
        }
        else if(t1.tb[t1.x][t1.y]=='C')
        {
            if(t1.x+1<n&&t1.tb[t1.x+1][t1.y]!='B'&&pck[t1.x+1][t1.y]>3)
            {
                t2=t1;
                t2.x=t1.x+1;
                t2.time++;
                if(t2.x==n-1&&t2.y==m-1)
                {
                    cout<<t2.time;
                    return 0;
                }
                q.push(t2);
            }
            if(t1.x-1>=0&&t1.tb[t1.x-1][t1.y]!='B'&&pck[t1.x-1][t1.y]>3)
            {
                t2=t1;
                t2.x=t1.x-1;
                t2.time++;
                if(t2.x==n-1&&t2.y==m-1)
                {
                    cout<<t2.time;
                    return 0;
                }
                q.push(t2);
                
            }
            if(ck[t1.x][t1.y]<3)
            {
                ck[t1.x][t1.y]++;
                t2=t1;
                for(i=0;i<n;i++)
                {
                    if(t2.tb[i][t2.y]=='C')t2.tb[i][t2.y]='D';
                    else if(t2.tb[i][t2.y]=='D')t2.tb[i][t2.y]='C';
                }
                for(i=0;i<m;i++)
                {
                    if(t2.tb[t2.x][i]=='C')t2.tb[t2.x][i]='D';
                    else if(t2.tb[t2.x][i]=='D')t2.tb[t2.x][i]='C';
                }
                t2.time++;
                q.push(t2);
            }
            
        }
        else if(t1.tb[t1.x][t1.y]=='D')
        {
            if(t1.y+1<m&&t1.tb[t1.x][t1.y+1]!='B'&&pck[t1.x][t1.y+1]>3)
            {
                t2=t1;
                t2.y=t1.y+1;
                t2.time++;
                if(t2.x==n-1&&t2.y==m-1)
                {
                    cout<<t2.time;
                    return 0;
                }
                q.push(t2);
            }
            if(t1.y-1>=0&&t1.tb[t1.x][t1.y-1]!='B'&&pck[t1.x][t1.y-1]>3)
            {
                t2=t1;
                t2.y=t1.y-1;
                t2.time++;
                if(t2.x==n-1&&t2.y==m-1)
                {
                    cout<<t2.time;
                    return 0;
                }
                q.push(t2);
            }
            if(ck[t1.x][t1.y]<3)
            {
                ck[t1.x][t1.y]++;
                t2=t1;
                for(i=0;i<n;i++)
                {
                    if(t2.tb[i][t2.y]=='C')t2.tb[i][t2.y]='D';
                    else if(t2.tb[i][t2.y]=='D')t2.tb[i][t2.y]='C';
                }
                for(i=0;i<m;i++)
                {
                    if(t2.tb[t2.x][i]=='C')t2.tb[t2.x][i]='D';
                    else if(t2.tb[t2.x][i]=='D')t2.tb[t2.x][i]='C';
                }
                t2.time++;
                q.push(t2);
            }
        }
    }
    cout<<-1;
}
