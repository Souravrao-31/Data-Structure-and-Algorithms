/*
* @Date    : 2020-05-15 11:25:19
* @Author  : Abhimanyu Kumar Maurya (aerma7309@gmail.com)
*/
#include <bits/stdc++.h>
using namespace std;

bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);

// int calIndex(int n)
// {
//     if (n == 0)
//         return 1;
//     int res = calIndex(n / 10);
//     res = res << 1;
//     if (n % 10 == 7)
//         res = res + 1;
//     return res;
// }

// int main()
// {
//     int num;
//     cin >> num;
//     cout << calIndex(num) - 1;
//     return 0;
// }

int main()
{
    int num, index = 0,i=0;
    cin >> num;
    while (num > 0)
    {
        if ((num % 10) == 7)
            index |= (1<<i);
        i++;
        num /= 10;
    }
    index |=(1<<i);
    cout << index - 1;
    return 0;
}