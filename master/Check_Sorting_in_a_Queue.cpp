// @author: Abhimanyu Maurya

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

//fast i/o
bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);
bool ot = cout.tie(0);

int main()
{
    int t, n, tmp;
    cin >> t;
    while (t--)
    {
        cin >> n;
        stack<int> stk;
        queue<int> Q;
        int expected = 1;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            Q.push(tmp);
        }
        bool flag = true;

        while (!Q.empty())
        {
            if (Q.front() == expected)
            {
                expected++;
                Q.pop();
                continue;
            }
            else if (!stk.empty() and stk.top() == expected)
            {
                expected++;
                stk.pop();
                continue;
            }

            if (stk.empty())
            {
                stk.push(Q.front());
                Q.pop();
            }
            else
            {
                if (stk.top() < Q.front())
                    break;
                else
                {
                    stk.push(Q.front());
                    Q.pop();
                }
            }
        }
        while (!stk.empty())
        {
            tmp = stk.top();
            stk.pop();
            if (tmp != expected)
                break;
            expected++;
        }

        if (expected == n + 1)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
