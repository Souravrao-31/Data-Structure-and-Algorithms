// @author: Abhimanyu Maurya

#include <iostream>
#include <cstring>
#define ll long long
using namespace std;

//fast i/o
bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);
bool ot = cout.tie(0);

int main()
{
    int a[50005], b[50005], n, t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = n; i > 0; i--)
            b[i] = max(b[i + 1], a[i + 1]);
        ll cp = 0, share = 0, profit = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] < b[i])
            {
                share++;
                cp += a[i];
            }
            if (a[i] == b[i - 1])
            {
                profit += share * a[i] - cp;
                share = 0;
                cp = 0;
            }
        }
        cout << profit << "\n";
    }

    return 0;
}
