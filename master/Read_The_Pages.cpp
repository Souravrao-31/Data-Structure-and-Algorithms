// @author: Abhimanyu Maurya

#include <iostream>
#define ll long long
using namespace std;

//fast i/o
bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);
bool ot = cout.tie(0);

bool isValid(ll a[], ll n, ll k, ll ans)
{
    ll s = 1, b = 0;
    for (ll i = 0; i < n; i++)
    {
        if (a[i] + b <= ans)
        {
            b += a[i];
        }
        else
        {
            b = a[i];
            s++;
        }
        if (s > k)
            return false;
    }
    return true;
}

int main()
{
    ll n, m, a[100001];

    cin >> n >> m;
    ll total = 0, res = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        total += a[i];
    }
    ll start = a[n - 1], end = total;
    while (start <= end)
    {
        ll mid = (start + end) / 2;
        if (isValid(a, n, m, mid))
        {
            res = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    cout << res << "\n";

    return 0;
}
