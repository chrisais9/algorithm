#include <iostream>
#include <vector>
using namespace std;
int tb[100000],n;
vector< pair<int,int> > data; // 벡터 + 페어로 데이터 관리.
int main()
{
    int i,j,a,b,mx;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a>>b;
        data.push_back(make_pair(a,b));
    }
    sort(data.begin(),data.end()); //전깃줄의 시작지점(a) 로 정렬
    for(i=0;i<n;i++)
    {
        mx=0; //초기화
        for(j=0;j<i;j++)
        {
            if(data[i].second>data[j].second&&mx<tb[j])mx=tb[j];
            // i 번째 전깃줄보다 작으며, mx 변수보다 큰 값으로 갱신.
        }
        tb[i]=mx+1; //최대값 +1. 즉, 전깃줄 1개 추가.
    }
    cout<<n-*max_element(tb,tb+n); //(전체 전깃줄수) - (tb 배열값중 최대값)
}
