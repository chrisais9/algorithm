#include <iostream>
#include <queue>
using namespace std;
typedef pair<double,int> ci;
queue<ci> q;
double m;
int ck[1000];
int cnt=0;
void pro()
{
    ci t;
    q.push(make_pair(1.0,1));
    q.push(make_pair(2.0,1));
    ck[1]=ck[2]=1;
    while(!q.empty())
    {
        t=q.front();
        q.pop();
        if(t.first==m)
        {
            cout<<t.second<<endl;
            return;
        }
        if(t.second>=16)continue;
        double x=t.first+1.0;
        if(x==m)
        {
            cout<<t.second+1;
            return;
        }
        if(ck[(int)x]==0)q.push(make_pair(x,t.second+1));
        ck[(int)x]=1;
        x=t.first+2.0;
        if(x==m)
        {
            cout<<t.second+1;
            return;
        }
        if(ck[(int)x]==0)q.push(make_pair(x,t.second+1));
        ck[(int)x]=1;
        x=t.first/(t.first+1.0);
        if(x==m)
        {
            cout<<t.second+1;
            return;
        }
        q.push(make_pair(x,t.second+1));
        x=(t.first*2.0)/(t.first+2.0);
        if(x==m)
        {
            cout<<t.second+1;
            return;
        }
        q.push(make_pair(x,t.second+1));
    }
    cout<<-1<<endl;
}
int main()
{
    int a,b;
    cin>>a>>b;
    m=(double)a/b;
    pro();
}
