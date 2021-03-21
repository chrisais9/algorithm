#include <iostream>
#include <queue>
#include <string>
using namespace std;
int n;
int main()
{
    queue<int> q;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string x;
        cin>>x;
        if(!x.compare("push"))
        {
            int num;
            cin>>num;
            q.push(num);
        }
        else if(!x.compare("pop"))
        {
            if(q.empty())cout<<-1<<endl;
            else
            {
                cout<<q.front()<<endl;
                q.pop();
            }
        }
        else if(!x.compare("front"))
        {
            if(q.empty())cout<<-1<<endl;
            else cout<<q.front()<<endl;
        }
        else if(!x.compare("back"))
        {
            if(q.empty())cout<<-1<<endl;
            else cout<<q.back()<<endl;
        }
        else if(!x.compare("size"))cout<<q.size()<<endl;
        else if(!x.compare("empty"))cout<<q.empty()<<endl;
    }
    
}
