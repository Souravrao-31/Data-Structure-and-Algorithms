#include <iostream>
#include <cmath>
using namespace std;

#ifndef ONLINE_JUDGE
FILE *fr = freopen("input.txt", "r", stdin);
FILE *fw = freopen("output.txt", "w", stdout);
#endif
void toh(string a, string b, string c, int n)
{
    if (n == 1)
        cout << "Move " << n << "th disc from " << a << " to " << c << endl;
    else
    {
        toh(a, c, b, n - 1);
        cout << "Move " << n << "th disc from " << a << " to " << c << endl;
        toh(b, a, c, n - 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    toh("T1", "T3", "T2", n);
    cout << (1 << n) - 1;
    return 0;
}
