#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    while (1) {
        string s;
        getline(cin,s);
        if(s==".") break;
        stack<char> stack;
        int flag=0;
        for(int i=0;i<s.size();i++){
               if(s[i]=='('||s[i]=='['){
                   stack.push(s[i]);
               }
               else if(s[i]==')'){
                   if(stack.empty()||stack.top()!='('){
                       flag = 1;
                       break;
                   }
                   else{
                      stack.pop();
                   }
                      
               }
               else if(s[i]==']'){
                   if(stack.empty()||stack.top()!='['){
                       flag = 1;
                       break;
                   }
                   else{
                       stack.pop();
                   }
                       
               }
           }
        
        if((flag == 0)&&(stack.empty()))
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
}

