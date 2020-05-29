/*
* @Date    : 2020-04-12 00:09:14
* @Author  : Abhimanyu Kumar Maurya (aerma7309@gmail.com)
*/
#include <iostream>
using namespace std;

bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);

int main()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.size() - 1; i++)
    {
        cout << s[i] << (int)s[i + 1] - s[i];
    }
    cout << s[s.size() - 1];
    return 0;
}
