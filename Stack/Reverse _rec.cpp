#include<iostream>
#include<stack>
using namespace std;

void InsertAtBottom(stack<int> &s,int x)
{
    if(s.empty()){
      s.push(x);
      return;
    }
    int y=s.top();
    s.pop();
    InsertAtBottom(s,x);
    s.push(y);
}

void reverse_rec(stack<int> &s)
{
    if(s.empty()){
        return;
    }
    int x=s.top();
    s.pop();
    reverse_rec(s);
    InsertAtBottom(s,x);
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(4);
    s.push(7);
    s.push(9);

    
   reverse_rec(s);
    while (s.empty() == false)
    {
        cout << s.top() <<endl;
        s.pop();
    }

    return 0;
}