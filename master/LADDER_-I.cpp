// @author: Abhimanyu Maurya

#include <iostream>
#include <cstring>
using namespace std;
#define ll long long
const ll M = 10e9 + 7;
ll countways(ll start, ll end, ll steps, ll a[], ll data[10000])
{
    if (start > end)
        return 0;
    if (start == end)
        return 1;
    ll res = 0, t;
    for (ll i = 1; i <= steps; i++)
    {
        if (a[i + start])
            continue;
        t = 0;
        if (data[start + i] == -1)
            t = countways(start + i, end, steps, a, data); 
        else
            t = data[start + i]; 
        res = (res + t % M) % M;
    }
    data[start] = res;
    return res;
}

int main()
{
    ll n, m, data[10001], A[10001]; 
    memset(data, -1, sizeof(data));
    memset(A, -1, sizeof(A));
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
    {
        cin >> A[i]; 
    }
    cout << countways(1, n, m, A, data) << endl;
    return 0;
}
