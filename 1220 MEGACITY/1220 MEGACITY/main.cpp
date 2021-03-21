#include <iostream>
#include <queue>
#include <vector>
#define DIST 10
using namespace std;
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
int n,asx,asy,aex,aey;
struct node
{
    int x,y;
    int f,g,h;
    bool operator ()(node a,node b)
    {
        if(a.f>b.f)return 1;
        return 0;
    }
};
struct sanga
{
    int sx,sy,ex,ey,cost;
};
void prt(node B)
{
    cout<<"("<<B.x<<" "<<B.y<<") "<<B.h<<" "<<B.g<<" "<<B.f<<endl;
}
priority_queue<node,vector<node>,node> q;
vector<node>check;
vector<sanga> ob;
int astar()
{
    node A;
    A.x=asx;
    A.y=asy;
    A.f=999999;
    A.g=0;
    A.h=aex-asx+aey-asy;
    q.push(A);
    while(!q.empty())
    {
        int cost=10;
        A=q.top();
        q.pop();
        prt(A);
        cout<<"======================"<<endl;
        for(int i=0;i<4;i++)
        {
            int mx=A.x+dx[i],my=A.y+dy[i];
            if(mx<0||my<0)continue;
            for(int j=0;j<ob.size();j++)
            {
                if(ob[j].sx<mx&&mx<ob[j].ex&&ob[j].sy<my&&my<ob[j].ey)
                {
                    cout<<"!"<<endl;
                    cost=ob[j].cost;
                    break;
                }
            }
            node B;
            B.x=mx;
            B.y=my;
            B.g=A.g+cost;
            B.h=abs(aex-mx)*10+abs(aey-my)*10;
            B.f=B.g+B.h;
            if(mx==aex&&my==aey)return A.g+cost;
            prt(B);
            q.push(B);
        }
        cout<<endl;
    }
    return -1;
}
int main()
{
    int i,j;
    cin>>asx>>asy>>aex>>aey;
    for(i=0;i<n;i++)
    {
        sanga temp;
        cin>>temp.sx>>temp.sy>>temp.ex>>temp.ey>>temp.cost;
        ob.push_back(temp);
    }
    cout<<astar();
    
}
