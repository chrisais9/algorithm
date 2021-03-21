#include<iostream>
#include<vector>
using namespace std;
int n,c;
long long int data[50];
vector<long long int> v;
int main()
{
    int i,j;
    int tn;
    cin>>n>>c;
    for(i=0;i<n;i++)cin>>data[i];
    v.push_back(0);
    for(i=0;i<n;i++)
    {
        tn=v.size();
        for(j = 0; j < tn; j++)
        {
            if(v[j] + data[i] <= c)v.push_back(v[j] + data[i]);
        }
    }
    cout<<v.size();
}
