/*
* @Date    : 2020-05-27 18:21:32
* @Author  : Abhimanyu Kumar Maurya (aerma7309@gmail.com)
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);

int combinations(int n, int k)
{
    int res = 1, i = n - k + 1, j = 2;
    while (i <= n)
    {
        res *= (i++);
        if (res % j == 0 and j <= k)
            res /= (j++);
    }
    while (j < k)
        res /= j++;
    return res;
}

signed main()
{
    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        cout << combinations(n - 1, k - 1)<<'\n';
    }
    return 0;
}
