// @author: Abhimanyu Maurya

#include <iostream>
#include <cmath>
#define ll long long

using namespace std;

//fast i/o
bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);
bool ot = cout.tie(0);

ll strToInt(string &s, const ll mod)
{
    ll num = 0;
    for (auto &i : s)
        num = ((num * 10) % mod + i - '0') % mod;
    return num;
}

ll fastPow(ll a, ll b, ll mod)
{
    if (b == 0)
        return 1;
    ll temp = fastPow(a, (b / 2), mod);
    temp %= mod;
    temp = (temp * temp) % mod;
    if (b & 1)
        return (temp * a) % mod;
    return temp % mod;
}
int main()
{
    const ll mod = 1000000007;
    int t;
    cin >> t;
    string a, b;
    while (t--)
    {
        cin >> a >> b;
        ll x = strToInt(a, mod);
        ll y = strToInt(b, mod - 1);
        cout << fastPow(x, y, mod) << "\n";
    }
    return 0;
}
