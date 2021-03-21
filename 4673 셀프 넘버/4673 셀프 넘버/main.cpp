#include <iostream>
using namespace std;

int d(int currentNum)  // 자릿수 구하기
{
    int numArr[5] = { 0 };
    
    numArr[0] = currentNum / 10000;
    numArr[1] = (currentNum % 10000) / 1000;
    numArr[2] = (currentNum  % 1000) / 100;
    numArr[3] = (currentNum % 100) / 10;
    numArr[4] = (currentNum % 10);
    
    int result = currentNum + numArr[0] + numArr[1] + numArr[2] + numArr[3] + numArr[4];
    
    return result;
}

int main()
{
    bool isSelfNum[10001] = { 0 };
    int n = 1;
    
    while (1)
    {
        int t = d(n);
        
        if (n >= 10000)
            break;
        
        if (t <= 10000)
            isSelfNum[t] = 1;
        
        n++;
    }
    
    for(int i = 1; i < 10000; i++)
    {
        if (isSelfNum[i] == 0)
        {
            cout << i << endl;
        }
    }
    
    return 0;
}
