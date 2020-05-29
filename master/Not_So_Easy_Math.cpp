/*
* @Date    : 2020-05-13 23:58:09
* @Author  : Abhimanyu Kumar Maurya (aerma7309@gmail.com)
*/
#include <bits/stdc++.h>
using namespace std;

bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);

signed main()
{
    int t, n;
    cin >> t;
    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19};
    int len = (sizeof(primes) / sizeof(primes[0]));
    int subets = (1 << len);
    while (t--)
    {
        cin >> n;
        int ans = 0;
        for (int i = 1; i < subets; i++)
        {
            int denominator = 1;
            int j = 0;
            for (int j = 0; j < len; j++)
            {
                if (i & (1<<j))
                    denominator *= primes[j];
            }
            if (__builtin_popcount(i) & 1)
                ans += n / denominator;
            else
                ans -= n / denominator;
        }
        cout << ans << '\n';
    }
    return 0;
}
