#include <bits/stdc++.h>
using namespace std;
long long int kroot(long long n, long long k)
{
    long long int res = 1;
    long long int s = 0, e = n;
    while (s <= e)
    {
        long long int mid = (s + e) / 2;
        if (pow(mid, k) == n)
        {
            res = mid;
            break;
        }
        else if (pow(mid, k) < n)
        {
            res = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return res;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n, k;
        cin >> n >> k;
        long long int ans = kroot(n, k);
        cout << ans << endl;
    }
    return 0;
}
