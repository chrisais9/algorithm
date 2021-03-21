#include <iostream>
#include <fstream>
using namespace std;
int book[100000],box[100000];
int bookn,boxn;
int main()
{
    int i,bx=0,bk=0;
    cin>>boxn>>bookn;
    for(i=0;i<boxn;i++)cin>>box[i];
    for(i=0;i<bookn;i++)cin>>book[i];
    do
    {
        if(bx==boxn||bk==bookn)break;
        if(box[bx]-book[bk]>=0)
        {
            box[bx]-=book[bk];
            bk++;
        }
        else bx++;
    }while(1);
    int sm=0;
    for(i=0;i<boxn;i++)sm+=box[i];
    cout<<sm;
}

