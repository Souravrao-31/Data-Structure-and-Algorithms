/*
* @Date    : 2020-04-30 11:14:33
* @Author  : Abhimanyu Kumar Maurya (aerma7309@gmail.com)
*/
#include <bits/stdc++.h>
using namespace std;

bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);

#define int long long

bool IsValid(vector<int> &v, int c, int ans)
{
    int cnt = 0, ptr = 0;
    for (int i : v)
    {
        if (i >= ptr)
        {
            cnt++;
            ptr = i + ans;
        }
    }
    return (cnt >= c);
}

signed main()
{
    int n, c;
    cin >> n >> c;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;
    sort(v.begin(), v.end());
    int lb = 0, ub = n, mid, res = -1;
    while (lb <= ub)
    {
        mid = (lb + ub) / 2;
        if (IsValid(v, c, mid))
        {
            res = mid;
            lb = mid + 1;
        }
        else
            ub = mid - 1;
    }
    cout << res << '\n';
    return 0;
}
