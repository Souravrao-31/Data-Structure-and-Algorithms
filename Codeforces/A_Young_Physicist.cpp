#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    n = n * 3;
    int sum1 = 0, sum2 = 0, sum3 = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if ((i % 3) == 1)
            sum1 = sum1 + x;
        else if ((i % 3) == 2)
            sum2 = sum2 + x;
        else if ((i % 3) == 0)
            sum3 = sum3 + x;
    }
    ((sum1 == 0) && (sum2 == 0) && (sum3 == 0)) ? cout << "YES" : cout << "NO";
    return 0;
}