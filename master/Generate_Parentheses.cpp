/*
* @Date    : 2020-04-14 19:36:06
* @Author  : Abhimanyu Kumar Maurya (aerma7309@gmail.com)
*/
#include <bits/stdc++.h>
using namespace std;

bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);

void generate(int n, int open, int close, string s)
{
    if (n == close)
    {
        cout << s << '\n';
        return;
    }
    if (open > close)
        generate(n, open, close + 1, s + ')');
    if (open < n)
        generate(n, open + 1, close, s + '(');
}

int main()
{
    int n;
    cin >> n;
    generate(n, 0, 0, "");
    return 0;
}
