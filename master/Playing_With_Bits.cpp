// @author: Abhimanyu Maurya

#include <iostream>
using namespace std;

//fast i/o
bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);
bool ot = cout.tie(0);

int main()
{
    int t, a, b, c;
    cin >> t;
    long long res;
    while (t--)
    {
        res = 0;
        c = 0;
        cin >> a >> b;
        for (int bit = 0; bit < 32; bit++)
        {
            for (int i = a; i <= b; i++)
                if ((1 << bit) & i)
                    res++;
        }
        cout << res << "\n";
    }

    return 0;
}
