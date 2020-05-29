// @author: Abhimanyu Maurya

#include <iostream>
#include <stack>
using namespace std;

//fast i/o
bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);
bool ot = cout.tie(0);

int main()
{
    stack<char> s;
    string str;
    getline(cin, str);
    for (auto &i : str)
    {
        if (i == '(' or i == '[' or i == '{')
            s.push(i);
        else
        {
            if (i == ')' and s.top() == '(')
                s.pop();
            else if (i == ']' and s.top() == '[')
                s.pop();
            else if (i == '}' and s.top() == '{')
                s.pop();
            else
                break;
        }
    }
    if (s.empty())
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
