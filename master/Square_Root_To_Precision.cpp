#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    double n, p;
    cin >> n >> p;
    double precision = 1, res = 1, prev;
    for (int i = 0; i <= p; i++)
    {
        while (res * res <= n)
        {
            prev = res;
            res += precision;
        }
        res = prev;
        precision /= 10;
    }
    cout << res;
    return 0;
}
