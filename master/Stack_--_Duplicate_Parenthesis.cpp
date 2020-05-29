// @author: Abhimanyu Maurya

#include <iostream>
#include <stack>
using namespace std;

//fast i/o
bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);
bool ot = cout.tie(0);

bool checkDuplicate(string &s)
{
    stack<char> Stack;
    for (char i : s)
    {
        if (i == ')')
        {
            int count = 0;
            while (Stack.top() != '(')
            {
                count++;
                Stack.pop();
            }
            Stack.pop();
            if (count < 1)
                return true;
        }
        else
            Stack.push(i);
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    string str;
    while (t--)
    {
        cin >> str;
        if (checkDuplicate(str))
            cout << "Duplicate Found\n";
        else
            cout << "No Duplicates Found\n";
    }
    return 0;
}
