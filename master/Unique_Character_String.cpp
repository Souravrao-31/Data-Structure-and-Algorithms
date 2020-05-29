/*
* @Date    : 2020-04-22 16:46:03
* @Author  : Abhimanyu Kumar Maurya (aerma7309@gmail.com)
*/
#include <bits/stdc++.h>
using namespace std;

bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);

map<char, int> ucs(vector<string> &vs, int pos, map<char, int> m)
{
    if (pos == vs.size())
        return m;

    map<char, int> tm(m);
    for (auto i : vs[pos])
        tm[i]++;
    for (auto i : tm)
    {
        if (i.second > 1)
            return ucs(vs, pos + 1, m);
    }
    map<char, int> inc = ucs(vs, pos + 1, tm);
    map<char, int> exc = ucs(vs, pos + 1, m);
    if (inc.size() > exc.size())
        return inc;
    else
        return exc;
}

signed main()
{
    int t;
    cin >> t;
    string s;
    vector<string> vs(t);
    for (auto &i : vs)
        cin >> i;
    map<char, int> m;
    cout << ucs(vs, 0, m).size();
    return 0;
}
