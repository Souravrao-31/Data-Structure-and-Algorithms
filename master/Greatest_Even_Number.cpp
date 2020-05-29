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
    char l = s[s.size() - 1];
    for (int i = 0; i < s.size() - 2; i++)
    {
        if (s[i] < l and (s[i] & 1) == 0)
        {
            swap(s[i], s[s.size() - 1]);
            cout << s;
            return 0;
        }
    }
    for (int i = s.size() - 2; i >= 0; i--)
    {
        if (s[i] > l and (s[i] & 1) == 0)
        {
            swap(s[i], s[s.size() - 1]);
            cout << s;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
