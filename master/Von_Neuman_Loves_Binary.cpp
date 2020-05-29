#include <iostream>
using namespace std;
#define ll long long

ll BinToDec(ll bin)
{
    ll mul = 1, dec = 0;
    while (bin > 0)
    {
        dec += (bin % 10) * mul;
        bin /= 10;
        mul *= 2;
    }
    return dec;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, num;
    cin >> t;

    while (t--)
    {
        cin >> num;
        cout << BinToDec(num) << endl;
    }

    return 0;
}
