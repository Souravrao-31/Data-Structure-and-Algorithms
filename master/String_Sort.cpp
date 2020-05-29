// @author: Abhimanyu Maurya

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//fast i/o
bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);

int main()
{
    auto fun = [&](string a, string b) {
        if (a.size() > b.size() and a.substr(0, b.size()) == b)
            return true;
        else if (b.substr(0, a.size()) == a)
            return false;
        return a < b;
    };
    int n;
    cin >> n;
    vector<string> v(n);
    for (auto &i : v)
        cin >> i;
    sort(v.begin(), v.end(), fun);
    for (auto &i : v)
        cout << i << '\n';
    return 0;
}