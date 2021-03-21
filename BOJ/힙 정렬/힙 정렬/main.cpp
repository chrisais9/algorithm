#include <iostream>
#include <vector>
using namespace std;
template <class T>
class heap
{
    vector<T> tree;
    void hp_up();
    void hp_down();
    int g_parent(int child);
    int r_child(int parent);
    int l_child(int parent);
    void swap(int child,int parent);
public:
    void push(T);
    T print();
    bool is_empty();
};
template <class T>
bool heap<T>::is_empty()
{
    return tree.empty();
}
template <class T>
void heap<T>::swap(int child,int parent)
{
    T x;
    x=tree[child];
    tree[child]=tree[parent];
    tree[parent]=x;
}
template <class T>
void heap<T>::push(T value)
{
    tree.push_back(value);
}

template <class T>
int heap<T>::g_parent(int child)
{
    if (child % 2 == 0) return (child /2 ) -1;
    else return child/2;
}

template <class T>
int heap<T>::l_child(int parent)
{
    return 2 * parent + 1;
}

template <class T>
int heap<T>::r_child(int parent)
{
    return 2 * parent + 2;
}

template <class T>
void heap <T>:: hp_up()
{
    int child = tree.size() - 1;
    int parent = g_parent(child);
    while (tree[child] < tree[parent] && child >=0 && parent >= 0) {
        
        swap(child, parent);
        child = parent;
        parent = g_parent(child);
        
    }
}
template <class T>
void heap<T> :: hp_down()
{
    int parent = 0;
    while (1)
    {
        int left = l_child(parent);
        int right = r_child(parent);
        int length = tree.size();
        int largest = parent;
        
        if (left<length&&tree[left]<tree[largest])largest=left;
        if (right<length&&tree[right]<tree[largest])largest=right;
        if (largest != parent)
        {
            swap(largest, parent);
            parent = largest;
        }
        else break;
    }
}
template <class T>
T heap<T> :: print()
{
    int child = tree.size()-1;
    swap(child, 0);
    T value = tree.back();
    tree.pop_back();
    hp_down();
    return value;
}
int main()
{
    heap<int> h;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        h.push(x);
    }
    while(!h.is_empty())cout<<h.print()<<" ";
}
