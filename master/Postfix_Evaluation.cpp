// @author: Abhimanyu Maurya

#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

//fast i/o
bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);
bool ot = cout.tie(0);

int main()
{
    string s;
    cin >> s;
    stack<int> stk;
    for (auto &i : s)
    {
        if (isalnum(i))
            stk.push(i - '0');
        else
        {
            int a = stk.top();
            stk.pop();
            int b = stk.top();
            stk.pop();
            if (i == '+')
                stk.push(b + a);
            if (i == '-')
                stk.push(b - a);
            if (i == '*')
                stk.push(b * a);
            if (i == '/')
                stk.push(b / a);
        }
    }
    cout << stk.top();
    return 0;
}
