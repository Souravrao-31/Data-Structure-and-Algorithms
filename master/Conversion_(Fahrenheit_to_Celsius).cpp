#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, mx, mn;
    cin >> mn >> mx >> t;
    for (int frn = mn; frn <= mx; frn += t)
    {
        cout << frn << "\t" << (int)(5 * (frn - 32) / 9) << "\n";
    }

    return 0;
}
