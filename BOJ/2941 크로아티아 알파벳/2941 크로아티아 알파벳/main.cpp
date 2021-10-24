#include <iostream>
#include <string>
using namespace std;
int main() {
    string in,cro[8];
    cin>>in;
    cro[0] = "c=";
    cro[1] = "c-";
    cro[2] = "dz=";
    cro[3] = "d-";
    cro[4] = "lj";
    cro[5] = "nj";
    cro[6] = "s=";
    cro[7] = "z=";
    
    for(int i=0;i<8;i++) {
        while (1) {
            int p = in.find(cro[i]);
            if(p==string::npos) {
                break;
            } else {
                in.replace(p, cro[i].size(), "^");
            }
        }
    }
    cout<<in.size();
}
