// MakeValid
/*

()))))
4

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <cmath>
#include <functional>
#include <deque>
#include <bitset>
#include <climits>
#include <cstdio>
#include <list>
#include <iomanip>

using namespace std;

char a[10001];

void solve()
{
    stack<char> s;

    for (int i = 0; a[i] != '\0'; i++)
    {
        char ch = a[i];
        if (s.empty())
        {
            s.push(ch);
        }
        else
        {
            // When stack is non-empty
            char t = s.top();
            if (t == '(' and ch == ')')
                s.pop();
            else
                s.push(ch);
        }
    }
    cout << s.size() << endl;
}

int main()
{
    cin >> a;
    solve();

    return 0;
}
