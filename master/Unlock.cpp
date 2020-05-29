/*
* @Date    : 2020-05-13 20:18:40
* @Author  : Abhimanyu Kumar Maurya (aerma7309@gmail.com)
*/
#include <bits/stdc++.h>
using namespace std;

bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);

signed main()
{
    int n, k, maxx;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    if(k<n)
    {
        for (int i = 0; i < n; i++)
        {
            if (k == 0)
                break;
            maxx = i;
            for (int j = i + 1; j < n; j++)
                if (a[maxx] < a[j])
                    maxx = j;
            if (maxx != i)
            {
                swap(a[i], a[maxx]);
                k--;
            }
        }
    }
    else sort(a.begin(),a.end(),greater<int>());
    for (auto &i : a)
        cout << i << " ";
    return 0;
}
