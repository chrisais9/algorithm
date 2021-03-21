#include <iostream>
#include <vector>
using namespace std;

class indextree
{
protected:
    vector<int> tree;
    void tree_insert(int i)
    {
        if(i==1)return;
        else tree[i>>1]=tree[i]&tree[i+1];
    }
public:
    void init()
    {
        tree.resize(1000000);
    }
    void connect(int x)
    {
        tree[x]=1;
    }
};
int main()
{
    
}
