#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
int main() {
    int n;
    string x;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++){
        getline(cin, x);
        istringstream ss(x);
        string s;
        while (getline(ss,s,' ')) {
            reverse(s.begin(), s.end());
            cout << s << " ";
        }
        cout<<endl;
    }
}
