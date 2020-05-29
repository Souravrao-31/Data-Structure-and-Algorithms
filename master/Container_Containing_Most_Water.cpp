/*
* @Date    : 2020-04-23 11:12:01
* @Author  : Abhimanyu Kumar Maurya (aerma7309@gmail.com)
*/
#include <bits/stdc++.h>
using namespace std;

bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);

signed main()
{
    int t;
    cin >> t;
    vector<int> v(t);
    for (auto &i : v)
        cin >> i;
    int res = INT_MIN;
    int i = 0, j = t - 1;
    while (i < j)
    {
        res = max(res, (j - i) * (min(v[i], v[j])));
        if (v[i] > v[j])
            --j;
        else
            ++i;
    }
    cout << res;
    return 0;
}
