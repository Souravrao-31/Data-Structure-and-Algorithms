// @author: Abhimanyu Maurya

#include <iostream>
using namespace std;

//fast i/o
bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);
bool ot = cout.tie(0);

int main()
{
    string s;
    cin >> s;
    int t, a, b, val;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        if (a == 1)
        {
            for (auto &i : s)
            {
                val = i - 'a';
                val = (val + b) % 26;
                i = 'a' + val;
            }
        }
        else
        {
            string sb = s.substr(0, b);
            cout << sb << '\n';
        }
    }

    return 0;
}
