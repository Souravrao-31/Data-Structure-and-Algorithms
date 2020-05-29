#include <iostream>
using namespace std;

int main()
{
    unsigned long long l, r, m, res = 0, i = 0, msk = 0;
    cin >> l >> r;
    m = l ^ r;
    while (m > 0)
    {
        i++;
        m = m >> 1;
    }

    while (i--)
    {
        res = (res << 1) | 1;
    }
    cout << res;
    return 0;
}
