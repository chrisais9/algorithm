#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int s,e;
struct node
{
    int num,inc,dist;
    bool flag;
};
int bfs(int te)
{
    node temp;
    temp.num=1;
    temp.flag=true;
    temp.inc=2;
    temp.dist=0;
    queue<node> q;
    q.push(temp);
    while(!q.empty())
    {
        node now=q.front();
        q.pop();
        if(now.flag)
        {
            node next;
            next.num=now.num+now.inc;
            next.inc=now.inc+2;
            next.dist=now.dist+1;
            next.flag=false;
            if(next.num==te) return next.dist;
            q.push(next);
        }
        else
        {
            node next;
            next.num=now.num+1;
            next.inc=now.inc;
            next.dist=now.dist+1;
            next.flag=true;
            if(next.num==te) return next.dist;
            q.push(next);
            
            next.num=now.num-1;
            next.inc=now.inc;
            next.dist=now.dist+1;
            next.flag=true;
            if(next.num==te) return next.dist;
            q.push(next);
        }
    }
    return -1;
}
int main()
{
    cin>>s>>e;
    cout<<bfs(max(s,e))-bfs(min(s,e))<<endl;
    
}
