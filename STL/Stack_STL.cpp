#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack <int> s;
   
    for(int i=0;i<=5;i++){
        
        s.push(i);      //O(1)
    }
    //cout<<s.size()<<endl;
    //s.push(31);
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();        //O(1)
    }

    return 0;
}