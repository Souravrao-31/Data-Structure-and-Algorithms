/*
* @Date    : 2020-04-26 22:52:49
* @Author  : Abhimanyu Kumar Maurya (aerma7309@gmail.com)
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);

signed main()
{
    int t, num;
    double sum = 0;
    list<int> v;
    cin >> t >> num;
    while (num != -1)
    {
        if (v.size() < t)
        {
            sum += num;
            v.push_front(num);
        }
        else
        {
            sum -= v.back();
            v.pop_back();
            sum += num;
            v.push_front(num);
        }
        if (sum != 0)
            cout << sum / v.size() << " ";
        else
            cout << 0 << " ";
        cin >> num;
    }
    return 0;
}
