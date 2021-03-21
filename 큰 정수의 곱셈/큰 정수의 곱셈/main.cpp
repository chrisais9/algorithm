#include <iostream>
#include <string>
#include <math.h>
using namespace std;
const int SIZE = 100000;
const int PART = 1;
const int D = pow(10, PART);

struct LONG_INTEGER
{
    int num[SIZE];
    int size;
    bool sign;
};

void stringToint(string num, LONG_INTEGER &dest)
{
    if (num[0] == '-')
    {
        dest.sign = false;
        num = num.substr(1);
    }
    else dest.sign = true;
    int i;
    for (i = num.length() - PART; i >= 0; i -= PART)
    {
        dest.num[dest.size++] = stoi(num.substr(i, PART));
    }
    
    if (i + PART != 0)
    {
        dest.num[dest.size++] = stoi(num.substr(0, i + PART));
    }
}

void intTostring(LONG_INTEGER c, string &dest)
{
    int i;
    for (i = c.size; i >= 0 && c.num[i] == 0; i--);
    
    if (i >= 0 && c.sign == false)
    {
        dest += "-";
    }
    if (i < 0) dest += "0";
    
    for (; i >= 0; i--)
    {
        dest += to_string(c.num[i]);
    }
}

string multiply(string num1, string num2)
{
    LONG_INTEGER a = { 0, };
    LONG_INTEGER b = { 0, };
    LONG_INTEGER c = { 0, };
    long long int m, q = 0, r = 0;
    stringToint(num1, a);
    stringToint(num2, b);
    c.size = a.size + b.size - 1;
    
    for (int i = 0; i < a.size; i++)
    {
        for (int j = 0; j <= b.size; j++)
        {
            m = a.num[i] * b.num[j] + c.num[i + j] + q;
            q = m / D;
            r = m % D;
            
            c.num[i + j] = r;
        }
    }
    
    if ((a.sign && !b.sign) || (!a.sign && b.sign)) c.sign = false;
    else c.sign = true;
    
    string ret = "";
    intTostring(c, ret);
    
    return ret;
}

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    cout << multiply(str1, str2) << endl;
}
