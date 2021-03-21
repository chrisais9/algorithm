#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX_LEN 310
using namespace std;
int W, L;
int D[MAX_LEN];
string S;
vector<string> dictionary;
int compare_string(int index, string word)
{
    int i = 0;
    int j = index;
    while (j < L && i < word.size())
    {
        if (S[j] == word[i]) i++;
        j++;
    }
    return (i < word.size()) ? j-index : j-index-word.size();
}

int calculate(int index)
{
    if (index >= L) return 0;
    int &result = D[index];
    if (result < 0)
    {
        result = MAX_LEN;
        int len = dictionary.size();
        for (int i = 0; i < len; i++)
        {
            int mid_result = compare_string(index, dictionary[i]);
            result = min(result, (int)(mid_result + calculate(index+mid_result+dictionary[i].size())));
        }
    }
    return result;
}


int main(void)
{
    for (int i = 0; i < MAX_LEN; i++) D[i] = -1;
    cin >> W >> L;
    cin >> S;
    for (int w = 0; w < W; w++)
    {
        string word;
        cin >> word;
        dictionary.push_back(word);
    }
    cout<<calculate(0);
}
