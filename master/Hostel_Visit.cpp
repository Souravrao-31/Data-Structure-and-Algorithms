/*
* @Date    : 2020-05-13 18:12:18
* @Author  : Abhimanyu Kumar Maurya (aerma7309@gmail.com)
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);

signed main()
{
    int n, k, t, x, y;
    cin >> n >> k;
    priority_queue<int> q;
    while (n--)
    {
        cin >> t;
        if (t == 1)
        {
            cin >> x >> y;
            q.push(x * x + y * y);
            if (q.size() > k)
                q.pop();
        }
        else
            cout << q.top() << '\n';
    }
    return 0;
}
