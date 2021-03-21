#include <iostream>
#include <vector>
using namespace std;
int n;
vector <bool> result;
vector < vector < int > > v;
vector <int> degree;
int find_odd(int start)
{
    int i = start;
    do
    {
        if (degree[i] % 2 == 1) return i;
        i = (i + 1) % n;
    } while (i != start);
    return -1;
}
void change_set(int i)
{
    int m = v[i].size();
    degree[i] = 0;
    for (int j=0;j<m;j++)
    {
        int k = v[i][j];
        if (result[i] == result[k]) degree[k]--;
        else
        {
            degree[k]++;
            degree[i]++;
        }
    }
    result[i] = !result[i];
}
int main()
{
    int i,j;
    cin>>n;
    v.resize(n);
    for(i=0;i<n;i++)
    {
        int m;
        cin>>m;
        for(j=0;j<m;j++)
        {
            int x;
            cin>>x;
            x--;
            v[i].push_back(x);
        }
    }
    result.resize(n, false);
    degree.resize(n);
    for (int i = 0; i < n; i++) degree[i] = v[i].size();
    while ((i = find_odd(rand() % n)) != -1) change_set(i);
    int ans=0;
    for(i=0;i<n;i++)if(result[i])ans++;
    cout<<ans<<endl;
    for(i=0;i<n;i++)if(result[i])cout<<i+1<<" ";
    cout<<endl;
}
