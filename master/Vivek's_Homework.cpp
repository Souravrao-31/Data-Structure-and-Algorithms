// @author: Abhimanyu Maurya

#include <iostream>
#include <cmath>
using namespace std;

#ifndef ONLINE_JUDGE
FILE *fr = freopen("input.txt", "r", stdin);
FILE *fw = freopen("output.txt", "w", stdout);
#endif

#define ld long double
#define ll long long

int main()
{
    ll n, t;
    cin >> n;
    ld s = 0;
    for (long long i = 0; i < n; i++)
    {
        cin >> t;
        s += log10l((ld)t);
    }
    s /= n;
    cout << (ll)ceill(powl(10.0, s));
    return 0;
}
