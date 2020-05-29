/*
* @Date    : 2020-04-12 00:26:40
* @Author  : Abhimanyu Kumar Maurya (aerma7309@gmail.com)
*/
#include <iostream>
#include <cmath>
using namespace std;

bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);

int main()
{
    long long num, base, count = 0;
    cin >> num >> base;
    while (num > 1)
    {
        count++;
        num /= base;
    }
    cout << count;
    return 0;
}
