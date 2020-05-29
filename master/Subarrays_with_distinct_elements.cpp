/*
* @Date    : 2020-05-13 23:12:17
* @Author  : Abhimanyu Kumar Maurya (aerma7309@gmail.com)
*/
#include <bits/stdc++.h>
using namespace std;

bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);
#define int long long
const int mod = 1e9 + 7;
signed main()
{
    int n, res = 0;
    cin >> n;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;
    int i = 0, j = 0;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        while (j < n and s.find(v[j]) == s.end())
        {
            s.insert(v[j]);
            j++;
        }
        res += (((j - i) * (j - i + 1)) / 2);
        res %= mod;
        s.erase(v[i]);
    }
    cout << res;
    return 0;
}
