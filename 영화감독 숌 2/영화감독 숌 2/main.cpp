#include <iostream>
using namespace std;
long long process(int index,long long number)
{
    int count,i,ret;
    long long tmp = number;
    count = 0;
    while (tmp != 0)
    {
        if (tmp % 10 == 6)
        {
            count++;
            if (count == 3)
            {
                long long base;
                
                base = 1;
                
                for (i = 0; i < index; i++)
                    base = base * 10;
                
                return base;
            }
        }
        else
        {
            break;
        }
        tmp/= 10;
    }
    if (index == 3 && count == 0) return 1;
    if (index == 3 && count == 1) return 10;
    if (index == 3 && count == 2) return 100;
    ret = 0;
    for (i = 0; i < 10; i++)
    {
        ret += process(index - 1, number * 10 + i);
    }
    return ret;
}
long long fd(int index,long long number,long long remain)
{
    int i,count;
    long long tmp = number,ret,sum;
    count = 0;
    while (tmp != 0)
    {
        if (tmp % 10 == 6)
        {
            count++;
            if(count == 3)
            {
                long long base;
                base = 1;
                for (i = 0; i < index; i++) base = base * 10;
                return number*base + remain-1;
            }
        }
        else
        {
            break;
        }
        tmp = tmp / 10;
    }
    if (index == 3 && count == 0) return number * 1000 + 666;
    if (index == 3 && count == 1) return number * 1000 + 660 + remain-1;
    if (index == 3 && count == 2) return number * 1000 + 600 + remain-1;
    sum = 0;
    for (i = 0; i < 10; i++)
    {
        ret = process(index - 1, number * 10 + i);
        if (sum + ret >= remain) break;
        else sum = sum + ret;
    }
    return fd(index - 1, number * 10 + i, remain - sum);
}
int main()
{
    int N;
    cin>>N;
    cout<<fd(10,0,N);
}


