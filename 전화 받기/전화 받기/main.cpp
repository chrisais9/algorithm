#include <iostream>
#include <fstream>
using namespace std;
int n,l,d;
int main()
{
    int i,j,tm=0,ring=-1,m_on=1,rest,cnt=1,end=0;
    cin>>n>>l>>d;
    do
    {
        tm++;
        cout<<tm<<" "<<m_on<<" "<<cnt;
        if(cnt>=n&&m_on==0)end=1;
        if(end==0)
        {
            if((tm%l)==0&&m_on==0)
            {
                cnt++;
                m_on=1;
            }
            else if((tm%l)==0&&m_on==1)
            {
                m_on=0;
            }
        }
        if(tm>=d)
        {
            cout<<" "<<ring;
            if((tm%d)==0&&m_on==0)
            {
                cout<<endl<<tm<<endl;
                break;
            }
        }
        cout<<endl;
    }while(1);
}
