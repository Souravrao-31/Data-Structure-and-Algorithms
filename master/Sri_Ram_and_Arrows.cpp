/*
* @Date    : 2020-04-26 21:45:58
* @Author  : Abhimanyu Kumar Maurya (aerma7309@gmail.com)
*/
#include <bits/stdc++.h>
using namespace std;

bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);

signed main()
{
    int t, num;
    cin >> t;
    stack<int> s;
    while (t--)
    {
        cin >> num;

        if (!s.empty() and num < 0 and s.top() > 0)
        {
            if (s.top() == (-num))
                s.pop();
            else if (s.top() < (-num))
            {
                while (!s.empty() and s.top() > 0 and s.top() < (-num))
                    s.pop();
                if (!s.empty() and s.top() == (-num))
                    s.pop();
                else if (!s.empty() and s.top() > (-num))
                    continue;
                else
                    s.push(num);
            }
        }
        else
            s.push(num);
    }
    list<int> res;
    while (!s.empty())
    {
        res.push_front(s.top());
        s.pop();
    }
    for (auto &i : res)
        cout << i << " ";

    return 0;
}
