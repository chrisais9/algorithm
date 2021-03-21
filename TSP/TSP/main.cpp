#include <iostream>
#include <algorithm>
#include <climits>
#include <

using namespace std;
int N; int cost[10][10];
bool visited[10];
int lowCost = INT_MAX;

void tsp(int node, int costSum, int count) {
    visited[node] = true;
    if (count == N) {
        lowCost = min(lowCost, costSum);
        visited[node] = false;
        return;
    }
    
    for(int i=0;i<N;i++)
    {
        if(!visited[i] && cost[node][i] != 0)
        {
            if (costSum + cost[node][i] < lowCost)
            {
                tsp(i, costSum + cost[node][i], count + 1);
            }
        }
    }
    visited[node] = false;
}

int main()
{
    cin>>N;
    for (int i = 0; i < N; i++)
    {
        visited[i] = false;
        for (int j = 0; j < N; j++) cin>>cost[i][j];
    }
    cout<<endl;
    for (int i = 0; i < N; i++)
    tsp(i, 0, 1);
    cout<<lowCost<<endl;
    return 0;
}
