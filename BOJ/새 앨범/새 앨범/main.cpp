#include <iostream>
using namespace std;
int n,l,c;
int main()
{
    int ans=0;
    cin>>n>>l>>c;
    do
    {
        if(n<=0)break;
        ans++;
        int cap=c,cnt=1;
        cap-=l;
        cnt+=cap/(l+1);
        if(cnt>n)cnt=n;
        if(cnt>0&&cnt%13==0)cnt--;
        n-=cnt;
        cout<<cnt<<endl;
    }while(1);
    cout<<ans;
}
