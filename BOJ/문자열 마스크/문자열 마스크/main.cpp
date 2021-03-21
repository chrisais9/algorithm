#include <iostream>
#include <string>
#include <queue>
using namespace std;
typedef pair<string,string> ci;
queue<ci> q;
int flag;
void f(string a,string b)
{
    int i,j,k;
    ci temp;
    
    string t1,t2;
    q.push(make_pair(a,b));
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        for(i=0;i<temp.first.size();i++)
        {
            if(temp.first[i]=='*')
            {
                t1=temp.first;
                t2=temp.second;
                char token='\0';
                if(i!=t1.size()-1)token=t1[i+1];
                cout<<"("<<token<<")"<<endl;
                t1.erase(i,1);
                if(t1==t2)
                {
                    cout<<t1<<endl;
                    return;
                }
                cout<<"1 "<<t1<<" "<<t2<<endl;
                q.push(make_pair(t1,t2));
                string ins;
                for(j=0;j<i;j++)
                {
                    if(t1[j]!=t2[j])break;
                }
                for(k=j;k<t2.size();k++)
                {
                    if(t2[k]=='*'||t2[k]==token)break;
                    ins+=t2[k];
                }
                cout<<i<<" "<<j<<" "<<k<<" "<<ins<<endl;
                t1.insert(i,ins);
                if(t1==t2)
                {
                    cout<<"!"<<endl;
                    cout<<t1<<endl;
                    return;
                }
                cout<<"2 "<<t1<<" "<<t2<<endl;
                q.push(make_pair(t1,t2));
                t1.insert(i+ins.size(),"*");
                cout<<"3 "<<t1<<" "<<t2<<endl;
            }
        }
    }
}
int main()
{
    string a,b;
    cin>>a>>b;
    if(a.size()>b.size())swap(a,b);
    f(a,b);
}
