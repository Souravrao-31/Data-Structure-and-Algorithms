#include <iostream>
#define ll long long
using namespace std;
// done by using inclusion exclusion principle
int main()
{
    int t, p[] = {2, 3, 5, 7, 11, 13, 17, 19};
    int sz = 8;
    cin >> t;
    while (t--)
    {
        ll res = 0, n, subset = 1 << sz;
        cin >> n;
        for (ll i = 1; i < subset; i++)
        {
            ll denom = 1, sb = __builtin_popcount(i);
            for (ll j = 0; j < sz; j++)
            {
                if (i & (1 << j))
                    denom *= p[j];
            }

            if (sb & 1)
                res += n / denom;
            else
                res -= n / denom;
        }

        cout << res << endl;
    }

    return 0;
}
