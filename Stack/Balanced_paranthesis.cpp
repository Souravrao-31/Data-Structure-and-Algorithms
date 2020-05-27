#include<iostream>
#include<stack>
using namespace std;

bool checkExpression(string str){

   stack<char> s;

    for(int i=0;i<str.size();i++){
        char curchar=str[i];
        if(curchar == '(' ){
            s.push(curchar);
        }
        else if(curchar == ')' ){
            if(s.empty() || s.top() !='(' ){
                return false;  
            }
            s.pop();
        }
    }
    return s.empty();
}

int main(){
    string exp;
    cin>>exp;

    bool isValid =checkExpression(exp);
    cout<<isValid;

    return 0;
}