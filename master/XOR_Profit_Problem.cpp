/*
* @Date    : 2020-05-13 23:47:23
* @Author  : Abhimanyu Kumar Maurya (aerma7309@gmail.com)
*/
#include <bits/stdc++.h>
using namespace std;

bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);

int main()
{
    int l, r, m, i = 0;
    cin >> l >> r;
    m = l ^ r;
    while (m > 0)
        i++, m = m >> 1;
    cout << (1 << i) - 1;
    return 0;
}
